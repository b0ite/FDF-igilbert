/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igilbert <igilbert@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 19:38:03 by ivan              #+#    #+#             */
/*   Updated: 2024/11/06 14:51:34 by igilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	check(char c, char const *set)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	j;
	size_t	k;
	char	*str;

	i = 0;
	if (!s1 || !set)
		return (NULL);
	j = ft_strlen(s1);
	while (check(s1[i], set) && s1[i])
		i++;
	while (check(s1[j - 1], set) && j > i)
		j--;
	k = 0;
	str = malloc(j - i + 1);
	if (str == NULL)
		return (NULL);
	while (i < j)
	{
		str[k] = s1[i];
		i++;
		k++;
	}
	str[k] = '\0';
	return (str);
}
