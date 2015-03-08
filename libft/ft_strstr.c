/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccervant <ccervant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/23 16:40:52 by ccervant          #+#    #+#             */
/*   Updated: 2013/12/01 22:43:44 by ccervant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strstr(const char *s1, const char *s2)
{
	int		cmp;
	int		cmp2;

	cmp = 0;
	cmp2 = 0;
	if (!s2[0])
		return ((char *)(s1));
	while (s1[cmp])
	{
		if (s1[cmp] == s2[cmp2])
			cmp2++;
		else
		{
			cmp -= cmp2;
			cmp2 = 0;
		}
		if (!s2[cmp2])
			return ((char *)(s1 + cmp - cmp2 + 1));
		cmp++;
	}
	return (NULL);
}
