/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atseruny <atseruny@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 20:20:13 by atseruny          #+#    #+#             */
/*   Updated: 2025/01/25 19:53:48 by atseruny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = ft_strlen((char *)s);
	if ((char)c == '\0')
		return ((char *)(s + i));
	i--;
	while (i > 0 && s[i] != (char)c)
		i--;
	if (s[i] == (char)c)
		return ((char *)(s + i));
	return (NULL);
}
// int main()
// {
//     char s[50]="Somethintg";
//     char s1[50]="Somethintg";
//     printf("%s\n", ft_strrchr(s, 't' + 256));
//     printf("%s\n", strrchr(s1, 't' + 256));
// }
