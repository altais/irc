/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccervant <ccervant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/30 14:20:15 by ccervant          #+#    #+#             */
/*   Updated: 2015/03/03 17:58:24 by ccervant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*dest;
	int		i;

	i = 0;
	dest = (char *)malloc (ft_strlen(s) * 1);
	while (s[i] != '\0')
	{
		dest[i] = f(i, s[i]);
		i++;
	}
	return (dest);
}
