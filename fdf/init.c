/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igilbert <igilbert@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 10:10:10 by igilbert          #+#    #+#             */
/*   Updated: 2025/02/13 10:43:23 by igilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	count_lines(int fd)
{
	int		i;
	char	*line;

	i = 1;
	line = get_next_line(fd);
	while (line)
	{
		i++;
		free(line);
		line = get_next_line(fd);
	}
	return (i);
}

void	count_array(char *file, t_fdf **fdf)
{
	int		fd;
	int		i;
	char	*line;
	char	**split;

	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		ft_printf("Error: couldn't open the file\n");
		exit(1);
	}
	i = 0;
	line = get_next_line(fd);
	split = ft_split(line, ' ');
	while (split[i])
		i++;
	(*fdf)->line = count_lines(fd);
	(*fdf)->col = i;
	free(line);
	free_split(split);
	close(fd);
}

void	init_fdf(t_fdf *fdf, char *file)
{
	fdf->mlx = mlx_init();
	fdf->win = mlx_new_window(fdf->mlx, WIDTH, HEIGHT, "FDF");
	fdf->img = malloc(sizeof(t_img));
	if (!fdf->img)
	{
		ft_putstr_fd("Error : failed to allocate fdf->img\n", 2);
		exit(1);
	}
	fdf->img->img = mlx_new_image(fdf->mlx, WIDTH, HEIGHT);
	fdf->img->addr = mlx_get_data_addr(fdf->img->img,
			&fdf->img->bits_per_pixel, &fdf->img->line_length,
			&fdf->img->endian);
	count_array(file, &fdf);
	fdf->zoom = 1;
	fdf->offset_x = 0;
	fdf->offset_y = 0;
	fdf->view = 0;
	fdf->view_changed = 1;
}
