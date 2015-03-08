/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccervant <ccervant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/30 15:15:14 by ccervant          #+#    #+#             */
/*   Updated: 2014/04/20 15:21:01 by ccervant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

int		ft_strnequ(const char *s1, const char *s2, size_t n)
{
	if (!s1 && !s2)
		return (1);
	else if (!s1 || !s2)
		return (0);
	while (n && (*s1 || *s2))
	{
		if (*s1 != *s2)
			return (0);
		++s1;
		++s2;
		--n;
	}
	return (1);
}
