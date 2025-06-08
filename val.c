/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   val.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atseruny <atseruny@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 16:27:12 by atseruny          #+#    #+#             */
/*   Updated: 2025/03/31 19:42:57 by atseruny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	get_cpy(t_list *map, t_str *lst)
{
	char	**cpy;

	lst->size_x = ft_strlen(map -> content);
	lst->size_y = ft_lstsize(map);
	cpy = (char **)malloc((lst->size_y + 1) * sizeof(char *));
	if (!cpy)
		return (0);
	cpy = ft_fill_cpy(cpy, map);
	if (flood_fill(cpy, lst -> px, lst -> py, lst) == 0)
	{
		ft_free(cpy, lst->size_y);
		return (0);
	}
	ft_free(cpy, lst->size_y);
	return (1);
}

char	**ft_fill_cpy(char **cpy, t_list *map)
{
	int	j;

	j = 0;
	while (map)
	{
		cpy[j] = ft_strdup(map->content);
		map = map -> next;
		j++;
	}
	cpy[j] = NULL;
	return (cpy);
}

void	f_l(char **map, int x, int y)
{
	if ((x > 0 && y > 0) && (map[y][x] != '\0' && map[y][x] != '1')
		&& (map[y][x] != 'F' && map[y][x] != 'B'))
		map[y][x] = 'F';
	else
		return ;
	f_l(map, x + 1, y);
	f_l(map, x, y + 1);
	f_l(map, x - 1, y);
	f_l(map, x, y - 1);
}

int	flood_fill(char **map, int x, int y, t_str *lst)
{
	int	i;
	int	j;

	i = 0;
	f_l(map, x, y);
	while (i < lst->size_y)
	{
		j = 0;
		while (j < lst->size_x)
		{
			if (map[i][j] == 'C' || map[i][j] == 'E')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
