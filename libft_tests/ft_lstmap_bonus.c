/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psanguna <psanguna@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 10:10:21 by pamela            #+#    #+#             */
/*   Updated: 2024/04/29 10:56:18 by pamela           ###   ########.fr       */
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

static void	ft_lstadd_back(t_list **lst, t_list *new);
static t_list	*ft_lstnew(void *content);
static void	ft_lstdelone(t_list *lst, void (*del)(void *));
static void		del_content(void *content);
static t_list	*ft_lstlast(t_list *lst);
static void *change_list(char *content);
static void	free_list(t_list *head);
static void	ft_lstclear(t_list **lst, void (*del)(void *));
/*
function takes a list lst, a function f, and a function del as parameters 
and returns a new list resulting from applying the function f to each node 
of the original list. If the function f returns NULL at any point, the function 
releases the memory allocated for the new list and its content using the del 
function and returns NULL. 
*/
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;
	t_list	*item;i
	void	*set;

	if (!lst)
		return (0);
	new_lst = 0;
	while (lst)
	{
		set = f(lst->content);
		item = ft_lstnew(set);
		if (!item)
		{
			del(set);
			ft_lstclear(&new_lst, del);
			return (0);
		}
		ft_lstadd_back(&new_lst, item);
		lst = lst->next;
	}
	return (new_lst);
}

int	main()
{
	t_list *head1;
	t_list *current;

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
	current = head1;
	while (current != NULL)
	{
		printf("%s\n", (char *)current->content);
		current = current->next;
	}
	// Create a new list by adding one to each element of the original list 
	t_list *new_list = ft_lstmap(head1, (void *)&change_list, (void *)&del_content); 
	// Print the new list 
	printf("\nNew list after mapping:\n"); 
	current = new_list;
	while (current != NULL)
	{
		printf("%s\n", (char *)current->content);
		current = current->next;
	}
	// Free memory allocated for both listsfree_list(head1);
	free_list(new_list);
	return (0);
}

static void	ft_lstadd_back(t_list **lst, t_list *new)
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

static void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (lst && del)
	{
		del(lst->content);
		free(lst);
	}
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

static t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (0);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}

static void *change_list(char *content)
{
	int		i;

	i = 0;
	while (content[i])
	{
		content[i] = 'y';
		i++;
	}
	
	return (content);
}

// Function to free memory allocated for the linked list 
static void	free_list(t_list *head)
{ 
	t_list	*current;
	t_list	*temp;

	current = head; 
	while (current != NULL)
	{
		temp = current;
		current = current->next;
		free(temp);
	} 

}
