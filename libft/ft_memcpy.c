/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atseruny <atseruny@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 18:36:43 by atseruny          #+#    #+#             */
/*   Updated: 2025/01/25 16:13:40 by atseruny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t		i;
	char		*c;
	const char	*k;

	k = src;
	c = dst;
	i = 0;
	if (!dst && !src)
		return (NULL);
	while (i < n)
	{
		c[i] = k[i];
		i++;
	}
	return (dst);
}

// int main()
// {
//     char dst1[100]="Overlap Test";
//     char src1[100]="alo alo";

//     char dst2[100]="Overlap Test";
//     char src2[100]="alo alo";
//     printf("%s\n",ft_memcpy((void *)0,(void *)0, 3));
// //    printf("%s\n",memcpy((void *)0, (void *)0, 3));
// }
