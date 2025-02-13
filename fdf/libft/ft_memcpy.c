/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memcpy.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igilbert <igilbert@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 00:00:23 by ivan              #+#    #+#             */
/*   Updated: 2024/11/04 23:13:44 by igilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *restrict dst, const void *restrict src, size_t n)
{
	size_t				i;
	unsigned char		*mst;
	unsigned char		*std;

	mst = (unsigned char *)dst;
	std = (unsigned char *)src;
	if (mst == NULL && std == NULL)
		return (dst);
	i = 0;
	while (i < n)
	{
		mst[i] = std[i];
		i++;
	}
	return (dst);
}
