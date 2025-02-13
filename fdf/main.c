/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igilbert <igilbert@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 10:54:57 by igilbert          #+#    #+#             */
/*   Updated: 2025/02/13 10:55:06 by igilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int ac, char **av)
{
	t_fdf	fdf;

	if (ac != 2)
	{
		ft_printf("Usage: ./fdf [map]\n");
		return (1);
	}
	fdf_init(&fdf, av[1]);
	fdf_read_map(&fdf, av[1]);
	fdf_draw(&fdf, 0);
	mlx_hook(fdf.win, 17, 1L << 17, ft_exit, &fdf);
	mlx_hook(fdf.win, 2, 1L << 0, handle_hook, &fdf);
	mlx_loop(fdf.mlx);
	return (0);
}