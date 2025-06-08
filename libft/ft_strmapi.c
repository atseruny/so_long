/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atseruny <atseruny@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 15:53:25 by atseruny          #+#    #+#             */
/*   Updated: 2025/01/25 19:47:13 by atseruny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*s1;

	i = 0;
	s1 = (char *)malloc((ft_strlen(s) + 1) * sizeof(char));
	if (!s1)
		return (NULL);
	while (s[i] != '\0')
	{
		s1[i] = f(i, (char)s[i]);
		i++;
	}
	s1[i] = '\0';
	return (s1);
}
