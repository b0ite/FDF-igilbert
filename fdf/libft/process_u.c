/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_u.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igilbert <igilbert@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 10:56:04 by igilbert          #+#    #+#             */
/*   Updated: 2025/01/22 10:18:58 by igilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putnbr_long(long nb)
{
	int		len;

	len = 0;
	if (nb < 0)
	{
		len += ft_putchar('-');
		nb *= -1;
	}
	if (nb >= 10)
	{
		len += ft_putnbr(nb / 10);
		len += ft_putchar(nb % 10 + '0');
	}
	else
		len += ft_putchar(nb + '0');
	return (len);
}

int	process_u(va_list args)
{
	unsigned int	nb;
	int				len;

	nb = va_arg(args, unsigned int);
	len = ft_putnbr_long(nb);
	return (len);
}
