/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccervant <ccervant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/24 19:11:53 by ccervant          #+#    #+#             */
/*   Updated: 2014/01/29 10:58:30 by ccervant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memchr(const void *s1, int c, size_t n)
{
	char		tmp_c;
	char		*tmp_s1;

	tmp_c = (unsigned char)c;
	tmp_s1 = (char *)s1;
	while (n--)
	{
		if (*tmp_s1 == tmp_c)
			return (tmp_s1);
		tmp_s1++;
	}
	return (NULL);
}
