/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccervant <ccervant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/23 16:21:41 by ccervant          #+#    #+#             */
/*   Updated: 2014/01/29 10:57:59 by ccervant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memmove(void *s1, const void *s2, size_t n)
{
	char		*tmp_s1;
	const char	*tmp_s2;
	char		tmp[n];
	size_t		i;

	i = 0;
	tmp_s1 = (char *)s1;
	tmp_s2 = (const char*)s2;
	while (i < n)
	{
		tmp[i] = tmp_s2[i];
		i++;
	}
	i = 0;
	while (i < n)
	{
		tmp_s1[i] = tmp[i];
		i++;
	}
	return (s1);
}
