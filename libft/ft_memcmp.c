/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atseruny <atseruny@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 21:29:32 by atseruny          #+#    #+#             */
/*   Updated: 2025/01/25 16:12:18 by atseruny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*p1;
	unsigned char	*p2;
	size_t			i;

	i = 0;
	p1 = (unsigned char *)s1;
	p2 = (unsigned char *)s2;
	if (n == 0)
		return (0);
	while ((i < n - 1) && (p1[i] == p2[i]))
	{
		i++;
	}
	return (p1[i] - p2[i]);
}
// int main()
// {
//     int s1[50]={1,2,3,4,5,8};    
//     int s2[50]={1,2,3,4,5,6};
//     printf("%d\n", memcmp(s1,s2, 109));
//     printf("%d\n", ft_memcmp(s1,s2, 109));
// }
