/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccervant <ccervant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/27 08:40:31 by ccervant          #+#    #+#             */
/*   Updated: 2015/02/27 18:14:48 by ccervant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char		*ft_strjoin(char *s1, char *s2)
{
	char		*ret;
	char		*tmp;
	int			len;

	tmp = s1;
	while (*tmp)
		tmp++;
	ret = s2;
	while (*ret)
		ret++;
	len = ret - s2;
	if (!(ret = (char *)malloc(sizeof(char) * (1 + len + tmp - s1))))
		return (NULL);
	tmp = ret;
	while ((*tmp = *(s1++)))
		tmp++;
	while ((*tmp = *(s2++)))
		tmp++;
	return (ret);
}

static char		*ft_strchr(const char *s, int c)
{
	if (!s)
		return (NULL);
	while (*s != c)
	{
		if (!*s)
			return (NULL);
		s++;
	}
	return ((char*)s);
}

static int		ft_to_short(char **line, char **buf)
{
	if (**buf)
	{
		*line = *buf;
		free(*buf);
		return (1);
	}
	return (0);
}

static int		ft_read_line(char **line, char **buf, int fd)
{
	char		buffer[BUFF_SIZE + 1];
	char		*temp;
	int			ret;

	while ((ret = read(fd, buffer, BUFF_SIZE)))
	{
		if (ret == -1)
			return (-1);
		buffer[ret] = '\0';
		if ((temp = ft_strchr(buffer, '\n')) != NULL)
		{
			*temp = '\0';
			if ((*line = ft_strjoin(*buf, buffer)) == NULL
					|| (temp = ft_strjoin(temp + 1, "\0")) == NULL)
				return (-1);
			free(*buf);
			*buf = temp;
			return (1);
		}
		if ((temp = ft_strjoin(*buf, buffer)) == NULL)
			return (-1);
		free(*buf);
		*buf = temp;
	}
	return (ft_to_short(line, buf));
}

int				get_next_line(int const fd, char **line)
{
	static char	*buf = NULL;
	char		*temp;

	if (buf == NULL)
	{
		buf = (char *)malloc(sizeof(char));
		if (buf == NULL)
			return (-1);
		*buf = '\0';
	}
	else
	{
		if ((temp = ft_strchr(buf, '\n')) != NULL)
		{
			*temp = '\0';
			if ((temp = ft_strjoin(temp + 1, "\0")) == NULL)
				return (-1);
			if ((*line = ft_strjoin(buf, "\0")) == NULL)
				return (-1);
			free(buf);
			buf = temp;
			return (1);
		}
	}
	return (ft_read_line(line, &buf, fd));
}
