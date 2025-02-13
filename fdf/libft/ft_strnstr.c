/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igilbert <igilbert@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 20:06:28 by ivan              #+#    #+#             */
/*   Updated: 2024/11/07 18:41:28 by igilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (ft_strlen(needle) == 0 && (!haystack || !needle))
		return (NULL);
	if (*needle == '\0')
		return ((char *)haystack);
	if ((int)len < 0)
		return (ft_strnstr(haystack, needle, ft_strlen(haystack)));
	if (len == 1 && haystack[0] == needle[0])
		return ((char *)haystack);
	while (haystack[i] && i < len)
	{
		j = 0;
		while ((char)haystack[i + j] == (char)needle[j] && i + j < len)
		{
			if (j == ft_strlen((char *)needle) - 1)
				return ((char *)(haystack + i));
			j++;
		}
		i++;
	}
	return (NULL);
}
