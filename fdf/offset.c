/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   offset.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igilbert <igilbert@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 11:19:02 by igilbert          #+#    #+#             */
/*   Updated: 2025/02/13 11:44:40 by igilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	fdf_calc_offset(t_fdf *fdf)
{
	if (fdf->view == 0)
		_fdf_calc_offset_iso(fdf);
	else if (fdf->view == 1)
		_fdf_calc_offset_parallel(fdf);
	else if (fdf->view == 2)
		_fdf_calc_offset_top(fdf);
}

void	fdf_calc_offset_iso(t_fdf *fdf)
{
	t_offset	offset;
	t_point		point;

	fdf_offset_init(&offset);
	while (offset.j < fdf->line)
	{
		offset.i = 0;
		while (offset.i < fdf->col)
		{
			point = fdf_calculate_iso(fdf, offset.i, offset.j);
			if (point.draw_x < offset.min_x)
				offset.min_x = point.draw_x;
			if (point.draw_x > offset.max_x)
				offset.max_x = point.draw_x;
			if (point.draw_y < offset.min_y)
				offset.min_y = point.draw_y;
			if (point.draw_y > offset.max_y)
				offset.max_y = point.draw_y;
			offset.i++;
		}
		offset.j++;
	}
	fdf->offset_x = (WIDTH - (offset.max_x - offset.min_x)) / 2 - offset.min_x;
	fdf->offset_y = (HEIGHT - (offset.max_y - offset.min_y)) / 2 - offset.min_y;
}

t_point	fdf_calculate_iso(t_fdf *fdf, int i, int j)
{
	t_point	point;

	point.origin_x = fdf->map[j][i].x_orig;
	point.origin_y = fdf->map[j][i].y_orig;
	point.origin_z = fdf->map[j][i].z_orig;
	point.draw_x = (point.origin_x - point.origin_y) * cos(0.523599);
	point.draw_y = -point.origin_z + (point.origin_x + point.origin_y) * sin(0.523599);
	point.draw_z = fdf->map[j][i].z_orig;
	point.color = fdf->map[j][i].color;
	return (point);
}

void	fdf_calc_offset_parallel(t_fdf *fdf)
{
	t_offset	of;
	t_point		point;

	fdf_offset_init(&of);
	while (of.i < fdf->line)
	{
		of.j = 0;
		while (of.j < fdf->col)
		{
			point.draw_x = fdf->map[of.i][of.j].x_orig * fdf->zoom;
			point.draw_y = fdf->map[of.i][of.j].z_orig * fdf->zoom;
			if (point.draw_x < of.min_x)
				of.min_x = point.draw_x;
			if (point.draw_x > of.max_x)
				of.max_x = point.draw_x;
			if (point.draw_y < of.min_y)
				of.min_y = point.draw_y;
			if (point.draw_y > of.max_y)
				of.max_y = point.draw_y;
			of.j++;
		}
		of.i++;
	}
	fdf->offset_x = (WIDTH - (of.max_x - of.min_x)) / 2 - of.min_x;
	fdf->offset_y = (HEIGHT - (of.max_y - of.min_y)) / 2 - of.min_y;
}
