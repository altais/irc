/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccervant <ccervant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/27 17:45:25 by ccervant          #+#    #+#             */
/*   Updated: 2015/03/04 13:37:21 by ccervant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLIENT_H
# define CLIENT_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/socket.h>
# include <netdb.h>
# include <netinet/in.h>
# include <arpa/inet.h>
# include <errno.h>
# include "../libft/libft.h"
# include "../libft/get_next_line.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <sys/mman.h>

typedef struct			s_arg
{
	int					port;
	const char			*host;
	int					sock;
	char				*input;
}						t_arg;

void					send_file(t_arg *arg, char *command);
void					receive_file(t_arg *arg, char *file);
int						create_client(t_arg *arg);
void					receive_data(t_arg *arg);
char					*parse_file(char *filename);

#endif
