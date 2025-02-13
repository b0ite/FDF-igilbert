/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igilbert <igilbert@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 10:18:02 by igilbert          #+#    #+#             */
/*   Updated: 2025/01/22 10:19:13 by igilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;

	if (!s)
		return (NULL);
	str = malloc(len + 1);
	if (!str)
		return (NULL);
	i = 0;
	while (i < len && s[start + i])
	{
		str[i] = s[start + i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

void	*ft_realloc(void *old, size_t len, size_t len_new)
{
	size_t		i;
	char		*new;

	new = malloc(len_new + 1);
	if (!new)
		return (NULL);
	i = 0;
	while (i < len_new + 1)
	{
		((char *)new)[i] = 0;
		i++;
	}
	i = 0;
	if (old)
	{
		while (i < len)
		{
			((char *)new)[i] = ((char *)old)[i];
			i++;
		}
		free(old);
	}
	((char *)new)[len_new] = '\0';
	return (new);
}
