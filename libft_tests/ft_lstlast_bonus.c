/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psanguna <psanguna@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 10:08:03 by pamela            #+#    #+#             */
/*   Updated: 2024/04/29 11:01:28 by pamela           ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>

typedef struct s_list
{
        void                    *content;
        struct s_list   *next;
}       t_list;

static t_list	*ft_lstnew(void *content);
static void	print_list(t_list *head);
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

int	main(void)
{
	t_list *last_node;
	t_list *head1;
	t_list *second;
	t_list *third;

	// Create some nodes for the linked list 
	head1 = ft_lstnew("First"); 
	second = ft_lstnew("Second"); 
	third = ft_lstnew("Third"); 

	// Connect the nodes to form a linked list 
	head1->next = second;
	second->next = third;
	third->next = NULL; 
	// Call ft_lstlast to get the last node of the linked list 
  	last_node = ft_lstlast(head1); 
	// Print the size of the linked list
	printf("list:\n");
	print_list(head1); 
	if (last_node != NULL)
	{
		printf("Content of the last node: %s\n", (char *)last_node->content); 
	}
	else
	{
		printf("The list is empty.\n"); 
	}
	// Free memory allocated for the linked list 
	free(head1); 
	free(second); 
	free(third);
	return (0);
}

static t_list	*ft_lstnew(void *content)
{
	t_list	*new_node;

	new_node = (t_list *)malloc(sizeof(t_list));
	if (!new_node)
		return (0);
	new_node->content = content;
	new_node->next = NULL;
	return (new_node);
}

static void	print_list(t_list *head)
{ 
	t_list	*current;

	current = head;
	while (current != NULL)
	{
		printf("%s -> ", (char *)current->content); 
		current = current->next; 
	}
    printf("NULL\n"); 

}
