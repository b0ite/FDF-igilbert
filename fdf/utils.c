/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igilbert <igilbert@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 10:23:04 by igilbert          #+#    #+#             */
/*   Updated: 2025/02/18 11:13:11 by igilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	free_split(char **split)
{
	int	i;

	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

void	fdf_free_map(t_fdf *fdf)
{
	int	i;

	i = 0;
	while (i < fdf->line)
	{
		free(fdf->map[i]);
		i++;
	}
	free(fdf->map);
}

void	init_bresenham(t_bresenham *bres, t_map p1, t_map p2)
{
	bres->dx = abs(p2.x_proj - p1.x_proj);
	bres->dy = abs(p2.y_proj - p1.y_proj);
	bres->err = bres->dx - bres->dy;
	bres->x = p1.x_proj;
	bres->y = p1.y_proj;
	if (p1.x_proj < p2.x_proj)
		bres->sx = 1;
	else
		bres->sx = -1;
	if (p1.y_proj < p2.y_proj)
		bres->sy = 1;
	else
		bres->sy = -1;
}

int	get_base_length(char *base)
{
	int	base_length;
	int	j;

	base_length = 0;
	while (base[base_length])
	{
		if (base[base_length] == '-' || base[base_length] == '+')
			return (0);
		j = base_length + 1;
		while (base[j])
		{
			if (base[base_length] == base[j])
				return (0);
			++j;
		}
		++base_length;
	}
	if (base_length < 2)
		return (0);
	return (base_length);
}
