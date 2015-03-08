/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccervant <ccervant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/27 17:45:09 by ccervant          #+#    #+#             */
/*   Updated: 2015/03/04 13:38:25 by ccervant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

static int		check_file_error(char *command, int *fd, struct stat	*stats)
{
	if (command == NULL)
	{
		ft_putstr("Usage : put <file>\n");
		return (-1);
	}
	if ((*fd = open(command, O_RDONLY)) < 0)
	{
		ft_putendl("Impossible de trouver le fichier");
		return (-1);
	}
	if (fstat(*fd, stats) == 0 && S_ISDIR(stats->st_mode))
	{
		ft_putendl("Error : is a directory");
		return (-1);
	}
	return (0);
}

void			send_file(t_arg *arg, char *command)
{
	int				fd;
	void			*file;
	struct stat		stats;
	int				size_send;
	char			buf[1024];

	if (check_file_error(command, &fd, &stats) == -1)
		return ;
	size_send = 0;
	send(arg->sock, arg->input, 1024, 0);
	file = (char *)mmap(NULL, stats.st_size, PROT_READ, MAP_PRIVATE, fd, 0);
	while (size_send <= stats.st_size)
	{
		if (stats.st_size - size_send < 1024)
			send(arg->sock, file + size_send, stats.st_size - size_send, 0);
		else
			send(arg->sock, file + size_send, 1024, 0);
		size_send += 1024;
	}
	close(fd);
	recv(arg->sock, buf, 1024, 0);
	ft_putendl(buf);
}

static int		loop_receive_file(t_arg *arg, int create, int fd, char *file)
{
	int		r;
	char	buf[1024];

	while ((r = recv(arg->sock, buf, 1024, 0)))
	{
		if ((ft_strcmp(buf, "Impossible de trouver le fichier") == 0) ||
			(ft_strcmp(buf, "Error : is a directory") == 0))
		{
			ft_putendl(buf);
			return (-1);
		}
		if (create != 1)
		{
			fd = open(file, O_RDWR | O_CREAT, S_IRWXU | O_APPEND, S_IRWXU);
			create = 1;
		}
		write(fd, buf, r);
		if (r < 1024)
			break ;
	}
	close(fd);
	return (0);
}

void			receive_file(t_arg *arg, char *file)
{
	if (file == NULL)
	{
		ft_putstr("Usage : get <file>\n");
		return ;
	}
	send(arg->sock, arg->input, strlen(arg->input), 0);
	file = parse_file(file);
	if (loop_receive_file(arg, 0, 0, file) != -1)
		ft_putstr("File successfully received\n");
}
