/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atseruny <atseruny@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 14:24:35 by atseruny          #+#    #+#             */
/*   Updated: 2025/01/25 19:51:48 by atseruny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	k;
	size_t	l;

	l = (size_t)ft_strlen(needle);
	i = 0;
	k = 0;
	if (needle[i] == '\0')
		return ((char *)haystack);
	while (haystack[i] != '\0' && k != l && i < len)
	{
		k = 0;
		while ((haystack[i + k] != '\0') && (haystack[i + k] == needle[k]) && \
			(i + k < len))
			k++;
		i++;
	}
	if (k == l)
		return ((char *)&haystack[i - 1]);
	return (NULL);
}

// int main()
// {
//     char s1[100]="bbbbbbb alo blo", n1[100]="";
//     char s2[100]="bbbbbbb alo blo", n2[100]="";
//     printf("%s\n",strnstr(s1, n1,10));

//     printf("%s\n",ft_strnstr(s2, n2,10));
// }
