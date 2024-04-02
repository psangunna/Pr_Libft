#include <stdio.h> 
#include <stdlib.h> 
#include <string.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

/*
It dynamically allocates memory for a new node in a linked list,
initializes its content, and returns a pointer to the newly created node
*/
t_list	*ft_lstnew(void *content)
{
	t_list	*new_node;

	new_node = (t_list*)malloc(sizeof(t_list));
	if (!new_node)
		return (0);
	new_node->content = content;
	new_node->next = NULL;
	return (new_node);
}

/*
Adds a new node at the beginning of a linked list.
*/
void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!new)
		return;
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

/*
The functions provides a way to determine the size (i.e., the number of nodes) of 
a linked list by traversing through the list and counting the nodes encountered 
along the way. 
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
	return(cnt);
}

/*
Returns a pointer to the last node of a linked list. It takes the head of
the list (lst) as its parameter. The function first checks if the list is empty 
(i.e., if lst is NULL). If the list is not empty, it traverses the list by following 
the next pointers until it reaches the last node (i.e., the node whose next pointer
is NULL). Finally, it returns a pointer to the last node of the list. 
*/

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (0);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}

/*
Adds a new node to the end of a linked list. It takes two parameters: a pointer 
to a pointer to the first node of the list (lst) and a pointer to the 
new node to be added (new). 
*/
void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list *current;
	if (!new)
		return;
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

/*
function to free memory allocated for the content of a node.
It takes a node lst and a function pointer del as parameters. It checks if both parameters
are not NULL, and if they are valid, it frees the memory allocated for the content 
of the node using the provided del function, and then frees the memory allocated 
for the node itself. 
*/
void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (lst && del)
	{
		del(lst->content);
		free(lst);
	}
} 

/*
Deletes and frees the given node 'lst' and all its consecutive nodes, using the 
function 'del' and free. At the end, the pointer to the list should be NULL.
*/

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list *current;
	t_list *next_node;

	if (!lst || !del)
		return;
	current = *lst;
	while (current)
	{
		next_node = current->next;
		ft_lstdelone(current, del);
		current = next_node;
	}
	*lst = 0;
}

/*
This function ft_lstiter iterates over a list lst and applies 
the function f to the content of each node. It takes two parameters: 
a pointer to the first node of the list (lst) and a pointer to a 
function (f) that will be applied to each node's content. 
*/
void	ft_lstiter(t_list *lst, void (*f)(void *)) 
{
	if (!lst || !f)
		return;
	while (lst)
	{
		f(lst->content);
		lst = lst->next;
	}
}

/*
function takes a list lst, a function f, and a function del as parameters 
and returns a new list resulting from applying the function f to each node 
of the original list. If the function f returns NULL at any point, the function 
releases the memory allocated for the new list and its content using the del function 
and returns NULL. 
*/
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list *new_lst;
	t_list *elem;

	if (!lst)
		return (0);
	new_lst = 0;
	while (lst)
	{
		elem = ft_lstnew(f(lst->content));
		if (!elem)
		{
			ft_lstclear(&new_lst, del);
			return (0);
		}
		ft_lstadd_back(&new_lst, elem);
		lst = lst->next;
	}
	return (new_lst);
}

/*functions used for main to testing*/
// Function to print the linked list 

void	print_list(t_list *head)
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

// Function to free memory allocated for the linked list 
void	free_list(t_list *head)
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

void del_content(void *content) { 

    free(content); 

} 

// Function to increment the content of a node by one 

void *add_one(void *num)
{
	int *ptr;
	int *result;
	int	i;

	i = (int )num;
    i = i + 1;
	ptr = (int *)i;
    //ptr = (int *)num; >>no funciona 
	result = (int *)malloc(sizeof(int)); 
    if (!result)
	{
		printf("Error");
		return (0); 
    }
	
	result = ptr; 

    return (result); 

}

// Function to print the content of a node 
void	print_content(void *content) 
{
	printf("%s\n", (char *)content); 

} 

int	main(void)
{
	/*FT_LSTDELONE*/
    // Create a node with some content 

    t_list	*node = (t_list *)malloc(sizeof(t_list)); 

    if (node == NULL) 
	{
		printf("Error de memoria");
    } 
    node->content = strdup("Hello, world!"); 
    node->next = NULL; 
    // Print the content of the node before deletion 
    printf("Content of the node before deletion: %s\n", (char *)node->content);
    // Call ft_lstdelone to delete the node 
	ft_lstdelone(node, &del_content); 
    // Print a message after deletion 
    printf("Node deleted successfully.\n"); 
	return 0; 

}