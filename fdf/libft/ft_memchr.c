/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memchr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igilbert <igilbert@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 20:06:02 by ivan              #+#    #+#             */
/*   Updated: 2024/11/04 13:13:32 by igilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*str;
	unsigned char	cha;
	size_t			i;

	str = (unsigned char *)s;
	cha = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		if (*str == cha)
			return (str);
		str++;
		i++;
	}
	return (NULL);
}
