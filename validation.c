/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anush <anush@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 16:27:22 by atseruny          #+#    #+#             */
/*   Updated: 2025/06/08 21:44:21 by anush            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_inside_str(t_str	*map, char *s, int i, int j)
{
	if (s[0] != '1' || s[ft_strlen(s) - 1] != '1' || ft_strlen(s) != map->len)
		return (0);
	while (s[i] != '\0')
	{
		if (s[i] == 'C')
			(map->c)++;
		else if (s[i] == 'B')
			(map->b)++;
		else if (s[i] == 'E')
		{
			(map->e)++;
			(map->ex) = i;
			(map->ey) = j;
		}
		else if (s[i] == 'P')
		{
			(map->py) = j;
			(map->px) = i;
			(map->p)++;
		}
		else if (s[i] != '1' && s[i] != '0')
			return (0);
		i++;
	}
	return (1);
}

int	ft_inside(t_str *str, t_list *lst)
{
	int	j;

	j = 1;
	while (lst->next != NULL)
	{
		if (ft_inside_str(str, lst->content, 1, j) == 0)
			return (0);
		lst = lst->next;
		j++;
	}
	if (str->c == 0 || str->e != 1 || str->p != 1)
		return (0);
	return (1);
}

int	ft_wall(char *s)
{
	int	i;

	i = 0;
	while (s[i] == '1' && s[i] != '\0')
		i++;
	if (s[i] != '\0')
		return (0);
	return (1);
}

int	ft_space_line(char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0' && ((s[i] >= 9 && s[i] <= 13) || s[i] == 32))
		i++;
	if (s[i] != '\0')
		return (0);
	return (1);
}

int	map_name_valid(char *map)
{
	int	i;

	i = 0;
	while (map[i] != '\0' && map[i] != '.')
		i++;
	if (map[i] == '\0')
		return (0);
	if (map[i + 1] != 'b' && map[i + 2] == 'e' && map[i + 3] == 'r'
		&& map[i + 4] != '\0')
		return (0);
	if ((open(map, O_RDONLY)) < 0)
		return (0);
	return (1);
}
