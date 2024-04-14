/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psanguna <psanguna@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 10:09:58 by pamela            #+#    #+#             */
/*   Updated: 2024/04/12 11:57:31 by psanguna         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct s_list
{
        void                    *content;
        struct s_list   *next;
}       t_list;

static void	print_content(void *content);
static void	del_content(void *content);
static void	ft_lstdelone(t_list *lst, void (*del)(void *));
static void	ft_lstclear(t_list **lst, void (*del)(void *));
static void	ft_lstclear(t_list **lst, void (*del)(void *));
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

int	main(void)
{
	t_list *head1;
	
	head1 = (t_list *)malloc(sizeof(t_list)); 
    if (head1 == NULL) 
	{
		printf("Error de memoria");
    }
	head1->content = strdup("First");
    head1->next = (t_list *)malloc(sizeof(t_list)); 
    head1->next->content = strdup("Second"); 
    head1->next->next = (t_list *)malloc(sizeof(t_list)); 
    head1->next->next->content = strdup("Third"); 
    head1->next->next->next = NULL;
    // Call ft_lstiter to apply print_content to each node's content 
    printf("Contents of the nodes:\n"); 
    ft_lstiter(head1, &print_content); 
	// Liberar la memoria de la lista enlazada
	ft_lstclear(&head1, &del_content);
}

// Function to print the content of a node 
static void	print_content(void *content) 
{
	printf("%s\n", (char *)content); 

}

static void		del_content(void *content)
{
	free(content);
}

static void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*current;
	t_list	*next_node;

	if (!lst || !del)
		return ;
	current = *lst;
	while (current)
	{
		next_node = current->next;
		ft_lstdelone(current, del);
		current = next_node;
	}
	*lst = NULL;
}

static void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (lst && del)
	{
		del(lst->content);
		free(lst);
	}
}
static void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*current;
	t_list	*next_node;

	if (!lst || !del)
		return ;
	current = *lst;
	while (current)
	{
		next_node = current->next;
		ft_lstdelone(current, del);
		current = next_node;
	}
	*lst = NULL;
}
