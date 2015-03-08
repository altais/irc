/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccervant <ccervant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/27 17:27:53 by ccervant          #+#    #+#             */
/*   Updated: 2015/03/03 20:04:21 by ccervant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

int			create_client(t_arg *arg)
{
	struct protoent		*proto;
	struct hostent		*hostinfo;
	struct sockaddr_in	sin;

	proto = getprotobyname("tcp");
	if (proto == 0)
		return (-1);
	arg->sock = socket(PF_INET, SOCK_STREAM, proto->p_proto);
	hostinfo = gethostbyname(arg->host);
	if (hostinfo == NULL)
	{
		printf ("Unknown host %s.\n", arg->host);
		exit(-1);
	}
	sin.sin_family = AF_INET;
	sin.sin_port = htons(arg->port);
	sin.sin_addr = *(struct in_addr*)hostinfo->h_addr;
	if (connect(arg->sock, (const struct sockaddr *)&sin, sizeof(sin)) == -1)
	{
		printf("Connect error\n");
		exit(-1);
	}
	return (arg->sock);
}

void		receive_data(t_arg *arg)
{
	char	buffer[1024];
	int		n;
	char	**command;

	command = ft_strsplit(arg->input, ' ');
	if (ft_strcmp(command[0], "get") == 0)
		receive_file(arg, command[1]);
	else if (ft_strcmp(command[0], "put") == 0)
		send_file(arg, command[1]);
	else
	{
		send(arg->sock, arg->input, 1024, 0);
		while ((n = recv(arg->sock, buffer, 1024, 0)))
		{
			if (n < 1024)
			{
				buffer[n] = '\0';
				ft_putendl(buffer);
				break ;
			}
			else
				ft_putendl(buffer);
		}
	}
}

int			main(int argc, char **argv)
{
	t_arg	arg;

	if (argc != 3)
	{
		printf("Usage: %s <machine> <port>\n", argv[0]);
		return (-1);
	}
	arg.host = argv[1];
	arg.port = atoi(argv[2]);
	arg.sock = create_client(&arg);
	if (arg.sock == -1)
		return (-1);
	while (1)
	{
		ft_putstr("[Client] : ");
		get_next_line(0, &arg.input);
		if (ft_strcmp(arg.input, "quit") == 0)
			return (-1);
		else if (!ft_strcmp(arg.input, "") == 0)
			receive_data(&arg);
	}
	close(arg.sock);
	return (0);
}
