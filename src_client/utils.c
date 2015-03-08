/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccervant <ccervant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/27 17:45:15 by ccervant          #+#    #+#             */
/*   Updated: 2015/02/27 18:02:49 by ccervant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

char	*parse_file(char *filename)
{
	char	*r;

	r = ft_strrchr(filename, '/');
	if (r != NULL)
		return (r + 1);
	else
		return (filename);
}
