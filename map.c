/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atseruny <atseruny@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 15:54:04 by atseruny          #+#    #+#             */
/*   Updated: 2025/03/31 21:01:20 by atseruny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_map(t_str *m, t_mlx_data *d, int k, int i)
{
	int	j;

	while (i < m->size_y)
	{
		j = 0;
		while (j < m->size_x)
		{
			if (get_ch(m->map, j, i) == '1')
				mlx_put_image_to_window(d->mlx, d->win, d->w, j * P, i * P);
			else if (get_ch(m->map, j, i) == 'E')
				mlx_put_image_to_window(d->mlx, d->win, d->e, j * P, i * P);
			else if (get_ch(m->map, j, i) == 'C' && k == 0)
				mlx_put_image_to_window(d->mlx, d->win, d->c1, j * P, i * P);
			else if (get_ch(m->map, j, i) == 'C' && k == 1)
				mlx_put_image_to_window(d->mlx, d->win, d->c2, j * P, i * P);
			else if (get_ch(m->map, j, i) == 'P')
				mlx_put_image_to_window(d->mlx, d->win, d->p, j * P, i * P);
			else if (get_ch(m->map, j, i) == 'B')
				mlx_put_image_to_window(d->mlx, d->win, d->v, j * P, i * P);
			else if (get_ch(m->map, j, i) == '0')
				mlx_put_image_to_window(d->mlx, d->win, d->b, j * P, i * P);
			j++;
		}
		i++;
	}
}

void	get_images(t_mlx_data *data)
{
	int	w;

	w = P;
	data->b = mlx_xpm_file_to_image(data->mlx, "textures/B.xpm", &w, &w);
	data->c1 = mlx_xpm_file_to_image(data->mlx, "textures/C1.xpm", &w, &w);
	data->c2 = mlx_xpm_file_to_image(data->mlx, "textures/C2.xpm", &w, &w);
	data->e = mlx_xpm_file_to_image(data->mlx, "textures/E.xpm", &w, &w);
	data->p = mlx_xpm_file_to_image(data->mlx, "textures/P.xpm", &w, &w);
	data->w = mlx_xpm_file_to_image(data->mlx, "textures/W.xpm", &w, &w);
	data->v = mlx_xpm_file_to_image(data->mlx, "textures/V.xpm", &w, &w);
	data->move = 0;
}

void	print_back(t_str *map_str, t_mlx_data *dt)
{
	int	i;
	int	j;

	i = 0;
	while (i < map_str->size_y)
	{
		j = 0;
		while (j < map_str->size_x)
		{
			mlx_put_image_to_window(dt->mlx, dt->win, dt->b, j * P, i * P);
			j++;
		}
		i++;
	}
}

int	print_all(t_mlx_data *d)
{
	static int	c;
	char		*m;
	int			k;
	int			x;

	k = 1;
	x = d->map->size_x / 2;
	m = ft_itoa(d->move);
	if (c < 150)
		k = 1;
	else if (c >= 150 && c < 300)
		k = 0;
	c++;
	print_map(d->map, d, k, 0);
	mlx_string_put(d->mlx, d->win, x * P, (d->map->size_y - 1) * P, B, m);
	if (c == 300)
		c = 0;
	free(m);
	return (0);
}
