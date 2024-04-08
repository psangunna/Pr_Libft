/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psanguna <psanguna@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 16:12:17 by psanguna          #+#    #+#             */
/*   Updated: 2024/04/04 16:12:21 by psanguna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

/*
Returns a pointer to the last node of a linked list. It takes the head of
the list (lst) as its parameter. The function first checks if the list is ç
empty (i.e., if lst is NULL). If the list is not empty, it traverses the 
list by following the next pointers until it reaches the last node (i.e., the 
node whose next pointer is NULL). Finally, it returns a pointer to 
the last node of the list. 
*/
t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (0);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}
