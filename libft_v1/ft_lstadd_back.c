/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psanguna <psanguna@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 16:13:01 by psanguna          #+#    #+#             */
/*   Updated: 2024/04/04 16:13:07 by psanguna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

/*
Adds a new node to the end of a linked list. It takes two parameters: a pointer 
to a pointer to the first node of the list (lst) and a pointer to the 
new node to be added (new). 
*/
void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*current;

	if (!new)
		return ;
	if (!*lst)
	{
		*lst = new;
	}
	else
	{
		current = ft_lstlast(*lst);
		current->next = new;
	}
}
