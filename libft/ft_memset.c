/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccervant <ccervant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 13:52:59 by ccervant          #+#    #+#             */
/*   Updated: 2013/12/01 19:40:02 by ccervant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memset(void *s, int c, size_t len)
{
	size_t		i;
	char		*tmp;

	tmp = (char *)s;
	i = 0;
	while (i < len)
	{
		tmp[i] = (char)c;
		i++;
	}
	return (s);
}
