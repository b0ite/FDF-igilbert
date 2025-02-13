/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igilbert <igilbert@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 19:37:46 by ivan              #+#    #+#             */
/*   Updated: 2024/11/07 18:20:29 by igilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *s1, int len)
{
	char	*dup;
	size_t	i;

	i = 0;
	dup = malloc(len + 1);
	if (dup == NULL)
		return (NULL);
	while (i < (size_t)len)
	{
		dup[i] = s1[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

int	count_words(int c, char const *s)
{
	int	i;
	int	j;
	int	in;

	i = 0;
	j = 0;
	in = 0;
	while (s[i])
	{
		if (s[i] != (char)c && in != 1)
		{
			in = 1;
			j++;
		}
		if (s[i] == (char)c && in == 1)
			in = 0;
		i++;
	}
	return (j);
}

char	**ft_split(char const *str, char c)
{
	int		e;
	int		s;
	int		k;
	char	**res;

	s = 0;
	k = 0;
	if (!str)
		return (NULL);
	res = (char **)malloc(sizeof(char *) * (count_words(c, (char *)str) + 1));
	if (res == NULL)
		return (NULL);
	while (k < count_words(c, (char *)str) && str[s])
	{
		while (str[s] == c && str[s])
			s++;
		e = s;
		while (str[e] != c && str[e])
			e++;
		res[k] = ft_strndup((char *)str + s, e - s);
		k++;
		s = e;
	}
	res[k] = 0;
	return (res);
}
