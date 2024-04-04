/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psanguna <psanguna@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 16:14:54 by psanguna          #+#    #+#             */
/*   Updated: 2024/04/04 16:14:58 by psanguna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

/*
This function ft_lstiter iterates over a list lst and applies 
the function f to the content of each node. It takes two parameters:
a pointer to the first node of the list (lst) and a pointer to a 
function (f) that will be applied to each node's content. 
*/
void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (!lst || !f)
		return ;
	while (lst)
	{
		f(lst->content);
		lst = lst->next;
	}
}
