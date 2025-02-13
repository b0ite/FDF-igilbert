/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igilbert <igilbert@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 11:28:06 by igilbert          #+#    #+#             */
/*   Updated: 2025/01/22 10:19:48 by igilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	in_charset(char c)
{
	int		i;
	char	*charset;

	i = 0;
	charset = "cspdiuxX%";
	while (charset[i])
	{
		if (charset[i] == c)
			return (1);
		i++;
	}
	return (0);
}

void	print_correct(char const *str, va_list args, int index, int *len)
{
	char	c;

	c = str[index];
	if (c == 'c')
		*len += ft_putchar(va_arg(args, int));
	if (c == 's')
		*len += process_s(args);
	if (c == 'p')
		*len += process_p(args);
	if (c == 'd')
		*len += process_d(args);
	if (c == 'i')
		*len += process_i(args);
	if (c == 'u')
		*len += process_u(args);
	if (c == 'x')
		*len += process_x(args);
	if (c == 'X')
		*len += process_capx(args);
	if (c == '%')
		*len += ft_putchar('%');
}

int	ft_printf(char const *str, ...)
{
	int		i;
	int		len;
	va_list	args;

	len = 0;
	i = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			if (in_charset(str[i + 1]))
			{
				print_correct(str, args, i + 1, &len);
				i++;
			}
			else if (str[i + 1] == ' ')
				i++;
		}
		else
			len += ft_putchar(str[i]);
		i++;
	}
	return (len);
}
