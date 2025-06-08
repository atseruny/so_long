/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anush <anush@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 16:27:04 by atseruny          #+#    #+#             */
/*   Updated: 2025/06/08 21:07:11 by anush            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define XK_ESCAPE 0xff1b
# define XK_WL 0x0077
# define XK_AL 0x0061
# define XK_SL 0x0073
# define XK_DL 0x0064
# define XK_A 0x0041
# define XK_D 0x0044
# define XK_W 0x0057
# define XK_S 0x0053
#define XK_Left 0xff51 // Left Arrow
#define XK_Up 0xff52 // Up Arrow
#define XK_Right 0xff53 // Right Arrow
#define XK_Down 0xff54 // Down Arrow
# define B 0x000000 //color black
# define P 60 //size for each picture in pixels

# include <mlx.h>
# include "libft.h"
// # include <stdio.h>
# include "get_next_line.h"

typedef struct s_str
{
	t_list	*map;
	int		len;
	int		p;
	int		c;
	int		e;
	int		b;
	int		py;
	int		px;
	int		ex;
	int		ey;
	int		size_x;
	int		size_y;
}			t_str;

typedef struct s_mlx_data {
	void	*mlx;
	void	*win;
	void	*b;
	void	*w;
	void	*p;
	void	*c1;
	void	*c2;
	void	*e;
	void	*v;
	t_str	*map;
	int		move;
}				t_mlx_data;

void	free_map(t_list **lst);
int		ft_inside_str(t_str	*map, char *s, int i, int j);
int		ft_inside(t_str *str, t_list *lst);
int		ft_wall(char *s);
void	set_values_struct(t_str	*str, t_list *map, int len);
int		ft_space_line(char *s);
int		map_valid(t_list *map, t_str *map_str);
int		map_name_valid(char *map);
t_list	*get_map(char *map);
int		get_cpy(t_list *map, t_str *lst);
char	**ft_fill_cpy(char **cpy, t_list *map);
int		flood_fill(char **map, int x, int y, t_str *lst);
void	f_l(char **map, int x, int y);
void	start(t_str *map_str);
void	go_left(t_mlx_data *dt, int j, int px);
void	go_right(t_mlx_data *dt, int j, int px);
void	go_down(t_mlx_data *dt, int j, int px);
void	go_up(t_mlx_data *dt, int j, int px);
int		move(int keycode, t_mlx_data *data);
int		f(t_mlx_data *data);
void	print_map(t_str *map_str, t_mlx_data *data, int k, int i);
void	print_back(t_str *map_str, t_mlx_data *dt);
void	get_images(t_mlx_data *data);
int		print_all(t_mlx_data *data);
char	get_ch(t_list *map, int x, int y);
void	ex_flag(t_mlx_data *data, int flag);

#endif