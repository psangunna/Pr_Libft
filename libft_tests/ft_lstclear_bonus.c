/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psanguna <psanguna@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 10:09:39 by pamela            #+#    #+#             */
/*   Updated: 2024/04/29 11:09:31 by pamela           ###   ########.fr       */
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
static void		del_content(void *content);
void	ft_lstdelone(t_list *lst, void (*del)(void *));
/*
Deletes and frees the given node 'lst' and all its consecutive nodes, using the 
function 'del' and free. At the end, the pointer to the list should be NULL.
*/
void	ft_lstclear(t_list **lst, void (*del)(void *))
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


int	main(void)
{
	t_list *current;
	t_list *head1;

	// Create a linked list with three nodes
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

	// Print the content of each node before deletion 
	printf("Content of nodes before deletion:\n"); 
	current = head1; 
	while (current)
	{
		printf("%s\n", (char *)current->content); 
		current = current->next;
	}
	// Call ft_lstclear to delete all nodes 
	ft_lstclear(&head1, &del_content); 
	// Print a message after deletion 
	 printf("\nNodes deleted successfully.\n");
}

static void		del_content(void *content)
{
	free(content);
}

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (lst && del)
	{
		del(lst->content);
		free(lst);
	}
}
