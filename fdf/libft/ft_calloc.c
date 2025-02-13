/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igilbert <igilbert@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 19:37:24 by ivan              #+#    #+#             */
/*   Updated: 2024/11/07 17:47:13 by igilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*al;
	size_t	i;

	i = 0;
	if (count * size >= 2147483647 || ((int)count < 0 && (int)size < 0))
		return (NULL);
	if (count == 0 || size == 0)
	{
		al = malloc(sizeof(char));
		return (al);
	}
	al = malloc(size * (count));
	if (al == NULL)
		return (NULL);
	while (i < count * size)
	{
		((char *)al)[i] = 0;
		i++;
	}
	return (al);
}
