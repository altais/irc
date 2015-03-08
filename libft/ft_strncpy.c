/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccervant <ccervant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/23 16:31:23 by ccervant          #+#    #+#             */
/*   Updated: 2013/12/01 23:29:03 by ccervant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <unistd.h>

char	*ft_strncpy(char *s1, const char *s2, size_t n)
{
	char	*d;

	d = s1;
	while (*s2 != 0)
	{
		if (!n--)
			return (s1);
		*d++ = *s2++;
	}
	while (n--)
		*d++ = 0;
	return (s1);
}
