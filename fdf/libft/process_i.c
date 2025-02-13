/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_i.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igilbert <igilbert@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 10:38:52 by igilbert          #+#    #+#             */
/*   Updated: 2025/01/22 10:18:46 by igilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	process_i(va_list args)
{
	long	nb;
	int		len;

	nb = va_arg(args, int);
	len = ft_putnbr(nb);
	return (len);
}
