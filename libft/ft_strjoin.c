/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atseruny <atseruny@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 14:23:53 by atseruny          #+#    #+#             */
/*   Updated: 2025/01/25 19:42:40 by atseruny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s;
	int		l1;
	int		l2;
	int		i;

	i = 0;
	l1 = ft_strlen(s1);
	l2 = ft_strlen(s2);
	s = (char *)malloc((l1 + l2 + 1) * sizeof(char));
	if (!s)
		return (NULL);
	while (i < l1)
	{
		s[i] = s1[i];
		i++;
	}
	i = 0;
	while (i < l2)
	{
		s[l1 + i] = s2[i];
		i++;
	}
	s[l1 + l2] = '\0';
	return (s);
}
// int main()
// {
//     printf("%s", ft_strjoin("aas", "jihd"));
// }
