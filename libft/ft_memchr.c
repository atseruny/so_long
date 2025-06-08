/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atseruny <atseruny@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 20:59:12 by atseruny          #+#    #+#             */
/*   Updated: 2025/01/25 16:10:42 by atseruny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*s1;

	s1 = (unsigned char *)s;
	i = 0;
	if (n == 0)
		return (0);
	while ((i < n - 1) && (s1[i] != (unsigned char)c))
		i++;
	if (s1[i] == (unsigned char)c)
		return (s1 + i);
	return (NULL);
}
// int main()
// {
//     char s1[50]="somethintg";
//     char s2[50]="somethintg";

//     printf("%s\n", memchr(s1,'a', 5));
//     printf("%s\n", ft_memchr(s2,'a', 5));

// }
