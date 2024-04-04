/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psanguna <psanguna@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 16:11:19 by psanguna          #+#    #+#             */
/*   Updated: 2024/04/04 16:11:35 by psanguna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

/*
Adds a new node at the beginning of a linked list.
*/
void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!new)
		return ;
	if (!lst)
	{
		*lst = new;
	}
	else
	{
		new->next = *lst;
		*lst = new;
	}
}
