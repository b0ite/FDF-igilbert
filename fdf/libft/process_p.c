/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_p.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igilbert <igilbert@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 10:24:54 by igilbert          #+#    #+#             */
/*   Updated: 2025/01/22 10:18:50 by igilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putnbr_base(unsigned long long nb, char *base)
{
	int	len;

	len = 0;
	if (nb >= 16)
	{
		len += ft_putnbr_base(nb / 16, base);
		len += ft_putchar(base[nb % 16]);
	}
	else
		len += ft_putchar(base[nb % 16]);
	return (len);
}

int	process_p(va_list args)
{
	unsigned long long	nb;
	int					len;

	nb = va_arg(args, unsigned long long);
	if (!nb)
		return (ft_putstr("(nil)"));
	len = ft_putstr("0x");
	len += ft_putnbr_base(nb, "0123456789abcdef");
	return (len);
}
