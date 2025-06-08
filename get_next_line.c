/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atseruny <atseruny@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 19:30:21 by atseruny          #+#    #+#             */
/*   Updated: 2025/03/31 19:47:22 by atseruny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_in_buf(char *buf, int i, int len)
{
	char	*new_buf;

	new_buf = (char *)malloc((len + 1) * sizeof(char));
	if (!new_buf)
	{
		buf = ft_free_null(buf);
		return (NULL);
	}
	i = i - len - 1;
	len = 0;
	while (buf[i] != '\0')
		new_buf[len++] = buf[i++];
	new_buf[len] = '\0';
	return (new_buf);
}

static char	*ft_find_pos(char *buf)
{
	char	*new_buf;
	int		i;
	int		len;

	i = 0;
	len = 0;
	while (buf[i] != '\0' && buf[i] != '\n')
		i++;
	if (buf[i] == '\0')
	{
		buf = ft_free_null(buf);
		return (NULL);
	}
	i++;
	while (buf[i++] != '\0')
		len++;
	if (len == 0)
	{
		buf = ft_free_null(buf);
		return (NULL);
	}
	new_buf = ft_in_buf(buf, i, len);
	buf = ft_free_null(buf);
	return (new_buf);
}

static char	*ft_fill(char *buf)
{
	char	*line;
	int		i;

	i = 0;
	if (!buf)
		return (NULL);
	while (buf[i] != '\0' && buf[i] != '\n')
		i++;
	line = (char *)malloc((i + 1) * sizeof(char));
	if (!line)
		return (NULL);
	i = 0;
	while (buf[i] != '\0' && buf[i] != '\n')
	{
		line[i] = buf[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

static char	*rd_frst_line(char *tmp, int fd)
{
	ssize_t	num_read;
	char	*b;

	b = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!b)
		return (NULL);
	num_read = 1;
	while (num_read > 0)
	{
		num_read = read(fd, b, BUFFER_SIZE);
		if (num_read <= 0)
		{
			if (num_read == -1)
				tmp = ft_free_null(tmp);
			break ;
		}
		b[num_read] = '\0';
		tmp = ft_strjoin_other(tmp, b, ft_strlen_gnl(tmp), ft_strlen_gnl(b));
		if (ft_newline_instr(b) == 1)
			break ;
	}
	b = ft_free_null(b);
	return (tmp);
}

char	*get_next_line(int fd)
{
	static char	*buf;
	char		*line;

	if ((fd < 2 && fd != 0) || BUFFER_SIZE <= 0)
		return (NULL);
	buf = rd_frst_line(buf, fd);
	if (!buf)
		return (NULL);
	line = ft_fill(buf);
	buf = ft_find_pos(buf);
	return (line);
}
