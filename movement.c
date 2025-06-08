/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anush <anush@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/30 17:55:59 by atseruny          #+#    #+#             */
/*   Updated: 2025/06/08 21:11:38 by anush            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	go_left(t_mlx_data *dt, int j, int px)
{
	t_list	*mp;

	mp = dt->map->map;
	while (j < dt->map->py)
	{
		mp = mp->next;
		j++;
	}
	if ((mp->content)[px - 1] == 'C')
		(dt->map->c)--;
	else if ((mp->content)[px - 1] == '1')
		return ;
	else if ((mp->content)[px - 1] == 'E' && dt->map->c == 0)
		ex_flag(dt, 0);
	else if ((mp->content)[px - 1] == 'B')
		ex_flag(dt, 1);
	(mp->content)[px - 1] = 'P';
	if (px == dt->map->ex && dt->map->py == dt->map->ey)
		(mp->content)[px] = 'E';
	else
		(mp->content)[px] = '0';
	(dt->move)++;
	(dt->map->px)--;
}

void	go_right(t_mlx_data *dt, int j, int px)
{
	t_list	*mp;

	mp = dt->map->map;
	while (j < dt->map->py)
	{
		mp = mp->next;
		j++;
	}
	if ((mp->content)[px + 1] == 'C')
		(dt->map->c)--;
	else if ((mp->content)[px + 1] == '1')
		return ;
	else if ((mp->content)[px + 1] == 'E' && dt->map->c == 0)
		ex_flag(dt, 0);
	else if ((mp->content)[px + 1] == 'B')
		ex_flag(dt, 1);
	(mp->content)[px + 1] = 'P';
	if (px == dt->map->ex && dt->map->py == dt->map->ey)
		(mp->content)[px] = 'E';
	else
		(mp->content)[px] = '0';
	(dt->move)++;
	(dt->map->px)++;
}

void	go_down(t_mlx_data *dt, int j, int px)
{
	t_list	*mp;

	mp = dt->map->map;
	while (j < dt->map->py + 1)
	{
		mp = mp->next;
		j++;
	}
	if ((mp->content)[px] == 'C')
		(dt->map->c)--;
	else if ((mp->content)[px] == '1')
		return ;
	else if ((mp->content)[px] == 'E' && dt->map->c == 0)
		ex_flag(dt, 0);
	else if ((mp->content)[px] == 'B')
		ex_flag(dt, 1);
	(mp->content)[px] = 'P';
	mp = mp->prev;
	if (px == dt->map->ex && dt->map->py == dt->map->ey)
		(mp->content)[px] = 'E';
	else
		(mp->content)[px] = '0';
	(dt->move)++;
	(dt->map->py)++;
}

void	go_up(t_mlx_data *dt, int j, int px)
{
	t_list	*mp;

	mp = dt->map->map;
	while (j < dt->map->py - 1)
	{
		mp = mp->next;
		j++;
	}
	if ((mp->content)[px] == 'C')
		(dt->map->c)--;
	else if ((mp->content)[px] == '1')
		return ;
	else if ((mp->content)[px] == 'E' && dt->map->c == 0)
		ex_flag(dt, 0);
	else if ((mp->content)[px] == 'B')
		ex_flag(dt, 1);
	(mp->content)[px] = 'P';
	mp = mp->next;
	if (px == dt->map->ex && dt->map->py == dt->map->ey)
		(mp->content)[px] = 'E';
	else
		(mp->content)[px] = '0';
	(dt->move)++;
	(dt->map->py)--;
}

int	move(int keycode, t_mlx_data *data)
{
	if (keycode == XK_ESCAPE)
		f(data);
	else if (keycode == XK_WL || keycode == XK_W || keycode == XK_Up)
		go_up(data, 0, data->map->px);
	else if (keycode == XK_SL || keycode == XK_S || keycode == XK_Down)
		go_down(data, 0, data->map->px);
	else if (keycode == XK_DL || keycode == XK_D || keycode == XK_Right)
		go_right(data, 0, data->map->px);
	else if (keycode == XK_AL || keycode == XK_A || keycode == XK_Left)
		go_left(data, 0, data->map->px);
	return (0);
}
