/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anush <anush@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 16:26:55 by atseruny          #+#    #+#             */
/*   Updated: 2025/06/08 21:14:17 by anush            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ex_flag(t_mlx_data *data, int flag)
{
	if (flag == 1)
		ft_putstr_fd("Game Over!!!\n", 1);
	else
		ft_putstr_fd("You win!!!\n", 1);
	f(data);
}

char	get_ch(t_list *map, int x, int y)
{
	int		i;
	t_list	*cpy;
	char	*s;

	cpy = map;
	i = 0;
	while (i < y && cpy)
	{
		cpy = cpy -> next;
		i++;
	}
	s = cpy -> content;
	return (s[x]);
}

void	free_map(t_list **lst)
{
	t_list	*s;

	s = *lst;
	while (s != NULL)
	{
		s = s -> next;
		free((*lst)->content);
		free(*lst);
		*lst = s;
	}
}

int	f(t_mlx_data *data)
{
	mlx_destroy_image(data->mlx, data->b);
	mlx_destroy_image(data->mlx, data->c1);
	mlx_destroy_image(data->mlx, data->c2);
	mlx_destroy_image(data->mlx, data->p);
	mlx_destroy_image(data->mlx, data->e);
	mlx_destroy_image(data->mlx, data->w);
	mlx_destroy_image(data->mlx, data->v);
	mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	free_map(&(data->map->map));
	free(data->map);
	exit (0);
}

void	start(t_str *map_str)
{
	t_mlx_data	data;

	data.mlx = mlx_init();
	if (!data.mlx)
		return ;
	data.map = map_str;
	data.win = mlx_new_window(data.mlx, map_str -> size_x * P,
			map_str -> size_y * P, "So_long");
	if (data.win == NULL)
	{
		mlx_destroy_display(data.mlx);
		free(data.mlx);
		return ;
	}
	get_images(&data);
	mlx_key_hook(data.win, move, &data);
	mlx_loop_hook(data.mlx, print_all, &data);
	mlx_hook(data.win, 17, 0, f, &data);
	mlx_loop(data.mlx);
}
