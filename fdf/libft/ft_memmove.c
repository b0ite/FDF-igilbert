/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memmove.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igilbert <igilbert@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 20:06:10 by ivan              #+#    #+#             */
/*   Updated: 2024/11/04 13:13:31 by igilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *d, const void *s, size_t len)
{
	size_t			i;

	i = 0;
	if (d == NULL && s == NULL)
		return (d);
	if (d > s)
	{
		while (len != 0)
		{
			len--;
			((unsigned char *)d)[len] = ((unsigned char *)s)[len];
		}
	}
	else
	{
		while (i < len)
		{
			((unsigned char *)d)[i] = ((unsigned char *)s)[i];
			i++;
		}
	}
	return (d);
}
