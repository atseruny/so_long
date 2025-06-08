/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atseruny <atseruny@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 14:44:00 by atseruny          #+#    #+#             */
/*   Updated: 2025/01/25 20:14:49 by atseruny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*str;
	unsigned int	i;
	unsigned int	n;

	i = 0;
	if (s[i] == '\0' && len == 0)
		n = 0;
	if (start >= (unsigned int)ft_strlen(s))
		n = 0;
	else if (len > (unsigned int)ft_strlen(s) - start)
		n = ft_strlen(s) - start;
	else
		n = len;
	str = (char *)malloc((n + 1) * sizeof(char));
	if (!str)
		return (NULL);
	while (i < n && s[start + i] != '\0')
	{
		str[i] = s[start + i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
// int main()
// {
//     char *s="Barev dzez alo";
//     printf("%s\n", ft_substr("", 10, 5));
// }
