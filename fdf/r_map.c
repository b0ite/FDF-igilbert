/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_map.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igilbert <igilbert@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 10:13:42 by igilbert          #+#    #+#             */
/*   Updated: 2025/02/13 10:38:14 by igilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	parse_line(t_fdf *fdf, char **split, int i)
{
	int		j;
	char	**split2;

	j = 0;
	while (i < fdf->col)
	{
		split2 = ft_split(split[i], ',');
		fdf->map[j][i].x_orig = i * 20;
		fdf->map[j][i].y_orig = j * 20;
		fdf->map[j][i].z_orig = ft_atoi(split2[0]);
		if (split2[1])
			fdf->map[j][i].color = ft_atoi_base(split2[1] + 2,
					"0123456789ABCDEF");
		else
			fdf->map[j][i].color = 0xFFFFFF;
		i++;
		free_split(split2);
	}
}

void	alloc_map(t_fdf **fdf)
{
	int	i;

	(*fdf)->map = malloc(sizeof(t_map *) * (*fdf)->line);
	if (!(*fdf)->map)
	{
		ft_putstr_fd("Error : failed to allocate fdf->map\n", 2);
		exit(1);
	}
	while (i < (*fdf)->line)
	{
		(*fdf)->map[i] = malloc(sizeof(t_map) * (*fdf)->col);
		if (!(*fdf)->map[i])
		{
			ft_printf("Error : failed to allocate fdf->map[%d]\n", i);
			exit(1);
		}
		i++;
	}
}

void	read_map(t_fdf *fdf, char *file)
{
	int		fd;
	char	*line;
	char	**split;
	int		i;

	i = 0;
	alloc_map(&fdf);
	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		ft_putstr_fd("Error : couldn't open the file\n", 2);
		exit(1);
	}
	line = get_next_line(fd);
	while (i < fdf->line)
	{
		split = ft_split(line, ' ');
		parse_line(fdf, split, i);
		free(line);
		free_split(split);
		line = get_next_line(fd);
		i++;
	}
	free(line);
	close(fd);
}
