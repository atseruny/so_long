/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anush <anush@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 16:27:34 by atseruny          #+#    #+#             */
/*   Updated: 2025/06/08 21:13:41 by anush            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	set_values_struct(t_str	*str, t_list *map, int len)
{
	str -> map = map;
	str -> len = len;
	str -> c = 0;
	str -> e = 0;
	str -> p = 0;
	str -> py = 0;
	str -> px = 0;
	str -> size_x = 0;
	str -> size_y = 0;
}

int	map_valid(t_list *map, t_str *map_str)
{
	t_list	*tmp;
	int		len;

	tmp = map;
	len = ft_strlen(tmp->content);
	if (ft_wall(tmp->content) == 0)
		return (0);
	set_values_struct(map_str, map, len);
	if (ft_inside(map_str, tmp->next) == 0)
		return (0);
	while (tmp->next != NULL)
		tmp = tmp->next;
	if (ft_wall(tmp->content) == 0)
		return (0);
	if (get_cpy(map, map_str) == 0)
		return (0);
	return (1);
}

t_list	*read_map(char *line, int fd)
{
	t_list	*list;
	t_list	*tmp;

	tmp = ft_lstnew(line);
	list = tmp;
	while (line != NULL)
	{
		line = get_next_line(fd);
		if (line == NULL || ft_space_line(line) == 1)
			break ;
		line = ft_strtrim(line, "\t\n\v\f\r ");
		tmp = ft_lstnew(line);
		ft_lstadd_back(&list, tmp);
	}
	while (line != NULL)
	{
		free(line);
		line = get_next_line(fd);
	}
	if (line != NULL && ft_space_line(line) == 1)
		free(line);
	return (list);
}

t_list	*get_map(char *map)
{
	t_list	*lst;
	char	*line;
	int		fd;

	fd = open(map, O_RDONLY);
	if (fd < 0)
		return (NULL);
	line = get_next_line(fd);
	while (line != NULL && ft_space_line(line) == 1)
	{
		free(line);
		line = get_next_line(fd);
	}
	lst = read_map(line, fd);
	close(fd);
	return (lst);
}

int	main(int argc, char **argv)
{
	t_list	*map;
	t_str	*map_str;

	if (argc != 2)
		return (ft_putstr_fd("Wrong number of arguments\n", 1), 1);
	if (map_name_valid(argv[1]) == 0)
		return (ft_putstr_fd("Invalid path\n", 1), 1);
	map_str = malloc(sizeof(t_str));
	if (!map_str)
		return (1);
	map = get_map(argv[1]);
	if (map_valid(map, map_str) == 0)
	{
		free_map(&(map_str->map));
		free(map_str);
		return (ft_putstr_fd("Invalid map\n", 1), 1);
	}
	start(map_str);
	free_map(&(map_str->map));
	free(map_str);
	return (0);
}
