/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atseruny <atseruny@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 15:33:37 by atseruny          #+#    #+#             */
/*   Updated: 2025/03/25 20:57:45 by atseruny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	instr(char *s, char c)
{
	int	i;

	i = 0;
	if (c == '\0')
		return (0);
	while (s[i] != '\0')
	{
		if (s[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static int	trimmer(char const *s1, char const *set, int start)
{
	int	i;
	int	n;

	i = ft_strlen(s1) - 1;
	if (i > 0)
	{
		while (instr((char *)set, s1[i]))
			i--;
	}
	n = i - start + 1;
	if (start == ft_strlen(s1))
		n = 0;
	return (n);
}

char	*ft_strtrim(char *s1, char const *set)
{
	int		i;
	int		start;
	int		n;
	char	*s;

	i = 0;
	// while (instr((char *)set, s1[i]))
	// 	i++;
	start = i;
	n = trimmer(s1, set, start);
	s = (char *)malloc((n + 1) * sizeof(char));
	if (!s)
		return (NULL);
	i = 0;
	while (i < n)
	{
		s[i] = s1[start + i];
		i++;
	}
	s[i] = '\0';
	free(s1);
	return (s);
}
// int main()
// {
//     printf("%s", ft_strtrim(" lorem et l", "l "));
// }
