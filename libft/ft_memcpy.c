/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccervant <ccervant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 11:00:15 by ccervant          #+#    #+#             */
/*   Updated: 2014/01/24 14:15:37 by ccervant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memcpy(void *dest, const void *src, size_t num)
{
	size_t		i;
	char		*tmp_dest;
	char		*tmp_src;

	tmp_dest = (char *)dest;
	tmp_src = (char *)src;
	i = 0;
	while (i < num)
	{
		tmp_dest[i] = tmp_src[i];
		i++;
	}
	return (dest);
}
