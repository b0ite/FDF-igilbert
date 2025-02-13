/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_draw.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igilbert <igilbert@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 11:09:30 by igilbert          #+#    #+#             */
/*   Updated: 2025/02/13 11:43:27 by igilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	fdf_offset_init(t_offset *offset)
{
	offset->i = 0;
	offset->j = 0;
	offset->min_x = INT_MAX;
	offset->max_x = INT_MIN;
	offset->min_y = INT_MAX;
	offset->max_y = INT_MIN;
}

void	draw_line(t_fdf *fdf, t_map p1, t_map p2)
{
	t_bresenham	bres;
	t_map		xtmp;

	init_bresenham(&bres, p1, p2);
	xtmp = p1;
	while (1)
	{
		my_mlx_pixel_put(fdf, p1.x_proj, p1.y_proj,
			create_gradient(xtmp, p2, p1.x_proj));
		if (p1.x_proj == p2.x_proj && p1.y_proj == p2.y_proj)
			break ;
		bres.e2 = bres.err * 2;
		if (bres.e2 >= -bres.dy)
		{
			bres.err -= bres.dy;
			p1.x_proj += bres.sx;
		}
		if (bres.e2 < bres.dx)
		{
			bres.err += bres.dx;
			p1.y_proj += bres.sy;
		}
	}
}

void	fdf_draw_lines(t_fdf *fdf)
{
	int	i;
	int	j;

	i = 0;
	while (i < fdf->line)
	{
		j = 0;
		while (j < fdf->col)
		{
			if (j < fdf->col - 1)
				draw_line(fdf, fdf->map[i][j], fdf->map[i][j + 1]);
			if (i < fdf->line - 1)
				draw_line(fdf, fdf->map[i][j], fdf->map[i + 1][j]);
			j++;
		}
		i++;
	}
}

void	fdf_draw(t_fdf *fdf, int view)
{
	if (view == 0)
		fdf_draw_iso(fdf);
	else if (view == 1)
		fdf_draw_parallel(fdf);
	else if (view == 2)
		fdf_draw_top(fdf);
	fdf_draw_lines(fdf);
	mlx_put_image_to_window(fdf->mlx, fdf->win, fdf->img->img, 0, 0);
}
