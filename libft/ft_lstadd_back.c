/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anush <anush@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 15:31:11 by atseruny          #+#    #+#             */
/*   Updated: 2025/03/28 17:57:18 by anush            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*cpy;

	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	cpy = *lst;
	while (cpy -> next != NULL)
		cpy = cpy -> next;
	new -> prev = cpy;
	cpy -> next = new;
}
