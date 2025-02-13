/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_s.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igilbert <igilbert@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 10:19:46 by igilbert          #+#    #+#             */
/*   Updated: 2025/01/22 10:18:54 by igilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	process_s(va_list args)
{
	char	*str;
	int		len;

	str = va_arg(args, char *);
	if (!str)
		str = "(null)";
	len = ft_putstr(str);
	return (len);
}
