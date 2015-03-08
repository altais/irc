/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccervant <ccervant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/23 13:31:52 by ccervant          #+#    #+#             */
/*   Updated: 2015/03/04 13:38:48 by ccervant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "serveur.h"


static int create_server(void)
{
   int sock;
   SOCKADDR_IN sin;

   sock = socket(AF_INET, SOCK_STREAM, 0);
   if(sock == INVALID_SOCKET)
   {
      printf("Sock error\n");
      exit(-1);
   }
   sin.sin_addr.s_addr = htonl(INADDR_ANY);
   sin.sin_port = htons(PORT);
   sin.sin_family = AF_INET;
   if(bind(sock,(SOCKADDR *) &sin, sizeof sin) == SOCKET_ERROR)
   {
      printf("Bind error\n");
      exit(-1);
   }
   if(listen(sock, MAX_CLIENTS) == SOCKET_ERROR)
   {
      printf("Listen error\n");
      exit(-1);
   }
   return sock;
}

static void    init_fds(t_data *data, int actual)
{
   int      i;

   i = 0;
   FD_ZERO(&(data->rdfs));
   FD_SET(STDIN_FILENO, &(data->rdfs));
   FD_SET(server->sock, &(data->rdfs));
   while (i < actual)
      FD_SET(data->clients[i++].sock, &(data->rdfs));
}

void  ft_irc(t_data *data)
{
   char buffer[BUF_SIZE];
   int actual;

   actual = 0;
   while(1)
   {
      init_fds(data, actual);
      if(select(data->max + 1, &(data->rdfs), NULL, NULL, NULL) == -1)
      {
         perror("select()");
         exit(errno);
      }

      /* something from standard input : i.e keyboard */
      if(FD_ISSET(STDIN_FILENO, &rdfs))
      {
         /* stop process when type on keyboard */
         break;
      }
      else if(FD_ISSET(sock, &rdfs))
      {
         /* new client */
         SOCKADDR_IN csin = { 0 };
         socklen_t sinsize = sizeof(csin);

         int csock = accept(sock, (SOCKADDR *)&csin, &sinsize);
         if(csock == SOCKET_ERROR)
         {
            perror("accept()");
            continue;
         }

         /* after connecting the client sends its name */
         if(read_client(csock, buffer) == -1)
         {
            /* disconnected */
            continue;
         }

         /* what is the new maximum fd ? */
         max = csock > max ? csock : max;

         FD_SET(csock, &rdfs);

         Client c = { csock };
         strncpy(c.name, buffer, BUF_SIZE - 1);
         clients[actual] = c;
         actual++;
      }
      else
      {
         int i = 0;
         for(i = 0; i < actual; i++)
         {
            /* a client is talking */
            if(FD_ISSET(clients[i].sock, &rdfs))
            {
               Client client = clients[i];
               int c = read_client(clients[i].sock, buffer);
               /* client disconnected */
               if(c == 0)
               {
                  closesocket(clients[i].sock);
                  remove_client(clients, i, &actual);
                  strncpy(buffer, client.name, BUF_SIZE - 1);
                  strncat(buffer, " disconnected !", BUF_SIZE - strlen(buffer) - 1);
                  send_message_to_all_clients(clients, client, actual, buffer, 1);
               }
               else
               {
                  send_message_to_all_clients(clients, client, actual, buffer, 0);
               }
               break;
            }
         }
      }
   }

   clear_clients(clients, actual);
}

int main(int argc, char **argv)
{
   t_data   data;

   if (argc != 2)
   {
      printf("Usage: %s <port>\n", argv[0]);
      exit(-1);
   }
   data.sock = create_server();
   data.max = data.sock;
   ft_irc(&data);  
   closesocket(sock);
   return (0);
}
