/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccervant <ccervant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/30 13:52:31 by ccervant          #+#    #+#             */
/*   Updated: 2015/03/03 17:58:00 by ccervant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*dest;
	int		i;

	i = 0;
	dest = (char *)malloc (ft_strlen(s) * 1);
	while (s[i] != '\0')
	{
		dest[i] = f(s[i]);
		i++;
	}
	return (dest);
}
