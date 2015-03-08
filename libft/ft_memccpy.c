/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccervant <ccervant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/24 18:26:18 by ccervant          #+#    #+#             */
/*   Updated: 2014/04/15 08:17:39 by ccervant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memccpy(void *dest, const void *src, int c, size_t num)
{
	size_t			i;
	char			*tmp_dest;
	char			*tmp_src;

	tmp_dest = (char *)dest;
	tmp_src = (char *)src;
	i = 0;
	while (i < num)
	{
		if (tmp_src[i] == c)
		{
			tmp_dest[i] = tmp_src[i];
			i++;
			return (tmp_dest + i);
		}
		tmp_dest[i] = tmp_src[i];
		i++;
	}
	return (NULL);
}
