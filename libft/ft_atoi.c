/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atseruny <atseruny@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 15:03:30 by atseruny          #+#    #+#             */
/*   Updated: 2025/03/25 20:45:59 by atseruny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_strtoint(char ch)
{
	int	n;

	n = ch - '0';
	return (n);
}

static int	ft_num(int len, char *str)
{
	int	i;
	int	n;
	int	num;

	num = 0;
	i = 0;
	while (i < len && str[i] != '\0')
	{
		n = ft_strtoint(str[i]);
		num = num * 10 + n;
		i++;
	}
	return (num);
}

int	ft_isspace(char s)
{
	if (s == '\t' || s == '\n' || s == '\v'
		|| s == '\f' || s == '\r' || s == ' ')
		return (1);
	return (0);
}

int	ft_atoi(const char *str)
{
	int	i;
	int	cnt;
	int	num;

	num = 0;
	cnt = 0;
	i = 0;
	while (ft_isspace((char)str[i]) == 1)
		i++;
	if ((char)str[i] == '+' || (char)str[i] == '-')
	{
		if ((char)str[i] == '-')
			cnt = 1;
		i++;
	}
	str += i;
	i = 0;
	while ((char)str[i] >= '0' && (char)str[i] <= '9')
	{
		i++;
	}
	num = ft_num(i, (char *)str);
	if (cnt % 2 == 1)
		num = -num;
	return (num);
}

// int main(int argc, char **argv)
// {
// 	int num = 0;
// 	if (argc == 2)
// 	{
// 		num = ft_atoi(argv[1]);
// 	}
// 	printf("%d",num);

// }