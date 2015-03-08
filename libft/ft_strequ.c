/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccervant <ccervant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/30 14:23:06 by ccervant          #+#    #+#             */
/*   Updated: 2014/04/15 14:27:41 by ccervant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

int	ft_strequ(const char *s1, const char *s2)
{
	if (s1 && s2)
		return (!ft_strcmp(s1, s2));
	return (0);
}
