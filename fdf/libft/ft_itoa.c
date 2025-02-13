/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igilbert <igilbert@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 19:37:30 by ivan              #+#    #+#             */
/*   Updated: 2024/11/04 14:41:39 by igilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	nblen(long n)
{
	int	len;

	len = 0;
	while (n > 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*itoa2(char *ret, long nb, int len, int signe)
{
	if (signe == 1)
		ret[0] = '-';
	ret[len] = '\0';
	while (len > signe)
	{
		len--;
		ret[len] = (nb % 10) + '0';
		nb /= 10;
	}
	return (ret);
}

char	*ft_itoa(int n)
{
	int		len;
	char	*ret;
	long	nb;
	int		signe;

	nb = (long)n;
	signe = 0;
	if (n == 0)
		return (ft_strdup("0"));
	if (nb < 0)
	{
		nb = -nb;
		signe = 1;
	}
	len = nblen(nb) + signe;
	ret = malloc(len + 1);
	if (!ret)
		return (NULL);
	ret = itoa2(ret, nb, len, signe);
	return (ret);
}
