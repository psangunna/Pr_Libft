/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psanguna <psanguna@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 10:07:41 by pamela            #+#    #+#             */
/*   Updated: 2024/04/12 11:33:03 by psanguna         ###   ########.fr       */
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

static void	print_list(t_list *head);
static t_list	*ft_lstnew(void *content);
/*
The functions provides a way to determine the size (i.e., the number of nodes)
of a linked list by traversing through the list and counting the nodes 
encountered along the way. 
*/
int	ft_lstsize(t_list *lst)
{
	int	cnt;

	cnt = 0;
	while (lst)
	{
		cnt++;
		lst = lst->next;
	}
	return (cnt);
}

int	main(void)
{
	t_list	*head1;
	t_list	*second;
	t_list	*third;
	int		sizes;
	// Create some nodes for the linked list 
    head1 = ft_lstnew("First"); 
    second = ft_lstnew("Second"); 
    third = ft_lstnew("Third"); 
    // Connect the nodes to form a linked list 
    head1->next = second; 
    second->next = third; 
	third->next = NULL; 
    // Call the function ft_lstsize to get the size of the linked list 
	sizes = ft_lstsize(head1);
    // Print the size of the linked list
	printf("list:\n");
	print_list(head1); 
    printf("Size of the linked list: %d\n", sizes);
    // Free memory allocated for the linked list 
    free(head1);
    free(second);
    free(third);
	return (0);
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
