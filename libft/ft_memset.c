/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atseruny <atseruny@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 19:09:59 by atseruny          #+#    #+#             */
/*   Updated: 2025/01/25 19:24:29 by atseruny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *str, int c, size_t len)
{
	size_t	i;
	char	*ptr;

	i = 0;
	ptr = str;
	while (i < len)
	{
		*ptr = c;
		ptr++;
		i++;
	}
	return (str);
}
// int main()
// {
//     int str[38]={12,4,3,45,32,3};
//     //printf("%s\n",memset(str, 112, 4));
//     printf("%s\n",ft_memset(str, 65, 4));
// }
