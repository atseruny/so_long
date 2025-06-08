/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atseruny <atseruny@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 21:59:34 by atseruny          #+#    #+#             */
/*   Updated: 2025/01/25 20:28:23 by atseruny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, char *src, size_t size)
{
	size_t	i;
	size_t	dest_size;
	size_t	src_size;

	dest_size = ft_strlen(dest);
	src_size = ft_strlen(src);
	if (dest_size >= size)
		return (src_size + size);
	i = 0;
	while (dest_size + i < size - 1 && src[i] != '\0')
	{
		dest[dest_size + i] = src[i];
		i++;
	}
	dest[dest_size + i] = '\0';
	return (src_size + dest_size);
}
// int main() {
//     char src[] = "hello duplicates";
//     char dst[125] = "target buffer";
// 	char dst1[125] = "target buffer";
// 	printf("%s  %d\n", dst,ft_strlcat(dst, src, 17));

// 	printf("%s  %lu\n", dst1,strlcat(dst1, src, 17));
// 	return 0;
// }
