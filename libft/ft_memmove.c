/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atseruny <atseruny@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 19:10:50 by atseruny          #+#    #+#             */
/*   Updated: 2025/01/25 19:22:23 by atseruny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	other_variant(char *dst1, const char *src1, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		dst1[i] = src1[i];
		i++;
	}
}

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	size_t		i;
	char		*dst1;
	const char	*src1;

	src1 = src;
	dst1 = dst;
	if (!dst1 && !src1)
		return (NULL);
	if (src1 < dst1)
	{
		i = n;
		while (i > 0)
		{
			i--;
			dst1[i] = src1[i];
		}
	}
	else
		other_variant(dst1, src1, n);
	return (dst);
}
// int main()
// {
//     // char dst[100]="alo alo", src[100]="alo alo";
//     // printf("%s\n",memcpy(dst,src,7));
//     // printf("%s\n",dst);
//     char dst1[100]="Overlap Test";
//     char src1[100]="alo alo";
//  //   printf("%s\n",memmove(dst1+4,dst1,7));
// //    printf("%s\n",ft_memmove(dst1,src1,7));
//     printf("%s\n",memmove(dst1,src1,7));
// }
