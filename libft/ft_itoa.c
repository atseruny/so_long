/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atseruny <atseruny@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 19:12:48 by atseruny          #+#    #+#             */
/*   Updated: 2025/01/25 18:28:56 by atseruny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*min_val(int cnt, char *num)
{
	int	i;
	int	n;

	i = cnt - 1;
	num[0] = '-';
	num[1] = '2';
	num[cnt] = '\0';
	n = 147483648;
	while (i > 1)
	{
		num[i--] = (n % 10) + '0';
		n = n / 10;
	}
	return (num);
}

static int	len_num(int i)
{
	int	cnt;

	cnt = 0;
	if (i == -2147483648)
		i++;
	if (i < 0)
	{
		cnt++;
		i = -i;
	}
	else if (i == 0)
		cnt = 1;
	while (i > 0)
	{
		i = i / 10;
		cnt++;
	}
	return (cnt);
}

static char	*num_fill(int cnt, char *num, int n)
{
	int	j;

	j = cnt - 1;
	num[cnt] = '\0';
	cnt = 0;
	if (n < 0)
	{
		num[0] = '-';
		n = -n;
		cnt = 1;
	}
	while (j >= cnt)
	{
		num[j--] = (n % 10) + '0';
		n = n / 10;
	}
	return (num);
}

char	*ft_itoa(int n)
{
	int		cnt;
	char	*num;

	cnt = len_num(n);
	num = (char *)malloc((cnt + 1) * sizeof(char));
	if (!num)
		return (NULL);
	if (n == -2147483648)
	{
		num = min_val(cnt, num);
		return (num);
	}
	num = num_fill(cnt, num, n);
	return (num);
}
