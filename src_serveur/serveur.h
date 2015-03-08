/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   serveur.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccervant <ccervant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/23 13:50:54 by ccervant          #+#    #+#             */
/*   Updated: 2015/03/04 12:18:20 by ccervant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVEUR_H
# define SERVEUR_H

# include <sys/types.h>
# include <sys/socket.h>
# include <netinet/in.h>
# include <arpa/inet.h>
# include <unistd.h>
# include <stdio.h>
# include <netdb.h>
# include <stdio.h>
# include <stdlib.h>
# include <errno.h>
# include <string.h>

# define INVALID_SOCKET			-1
# define SOCKET_ERROR			-1
# define CRLF					"\r\n"
# define MAX_CLIENTS			100
# define BUF_SIZE				1024
# define NAME_LEN				9
# define MAX_CHANNEL			10

typedef struct sockaddr_in		t_sockaddr_in;
typedef struct sockaddr			t_sockaddr;
typedef struct in_addr			t_in_addr;

typedef struct					s_client
{
	int							sock;
	char						*name;
}								t_client;

typedef struct					s_data
{
	int							sock;
	int							max;
	fd_set						rdfs;
	t_client					clients[MAX_CLIENTS];
}								t_data;

void					create_server(t_arg *arg);
void					ls(t_arg *arg);
void					cd(t_arg *arg, char **command);
void					pwd(t_arg *arg);
char					*parse_file(char *filename);
void					receive_file(t_arg *arg, char *file, int create);
void					send_file(t_arg *arg, char **command, int size_send);
void					check_entry(t_arg *arg);
void					new_client(t_arg *arg);
void					ft_p(t_arg *arg);

#endif
