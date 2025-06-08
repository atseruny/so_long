/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atseruny <atseruny@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 19:00:19 by atseruny          #+#    #+#             */
/*   Updated: 2025/01/25 19:33:03 by atseruny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*p;
	int		i;

	i = 0;
	p = (char *)malloc((ft_strlen((char *)s1) + 1) * sizeof(char));
	if (p == NULL)
		return (NULL);
	while (i < ft_strlen((char *)s1))
	{
		p[i] = s1[i];
		i++;
	}
	p[i] = '\0';
	return (p);
}
// int main()
// {
//     char *p="alo lao";
//     char *s=ft_strdup(p);
//     printf("%s\n", p);
//     printf("%s\n", s);
// }
