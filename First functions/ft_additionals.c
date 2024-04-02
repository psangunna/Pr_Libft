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
		printf("inside 0\n");
		del(lst->content);
		printf("insidedelone 1 \n");
		free(lst);
		lst = NULL;
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
	/*FT_LSTNEW*/
	printf("\nFT_LSTNEW\n");
	t_list *node;
	// Creamos un nuevo nodo con contenido "Hello, world!"
	node = ft_lstnew("cheers and smile");
	// Verificamos si la creación del nodo fue exitosa 
	if (node)
	{
		// Imprimimos el contenido del nodo
		printf("Contenido del nodo: %s\n", (char *)node->content);
		// Liberamos la memoria del nodo
		free(node);
	}
	else
	{
		printf("Error: No se pudo crear el nodo.\n");
	}
	 
	/*FT_LSTADD_FRONT*/
	printf("\nFT_LSTADD_FRONT\n");
    // Create the first node
	t_list *head1;

	head1 = ft_lstnew("a");
    if (head1 == NULL)
	{
		printf("Error: No se pudo crear el nodo.\n");
	}
    // Print the initial list
	printf("Initial list:\n");
	print_list(head1); 
    // Create a new node
	t_list *new_node;
	
	new_node = ft_lstnew("b"); 
    if (new_node == NULL)
	{
		printf("Error: No se pudo crear el nodo.\n");
	}
    // Add the new node to the front of the list 
    ft_lstadd_front(&head1, new_node); 
	// Print the updated list 
    printf("\nList after adding a new node at the front:\n"); 
	print_list(head1);
    // Free memory 
	free_list(head1); 
	/*FT_LSTSIZE*/
	t_list	*second;
	t_list	*third;
	int		size;

	printf("\nFT_LSTSIZE\n");
	// Create some nodes for the linked list 
    head1 = ft_lstnew("First"); 
    second = ft_lstnew("Second"); 
    third = ft_lstnew("Third"); 
    // Connect the nodes to form a linked list 
    head1->next = second; 
    second->next = third; 
    // Call the function ft_lstsize to get the size of the linked list 
	size = ft_lstsize(head1);
    // Print the size of the linked list
	printf("list:\n");
	print_list(head1); 
    printf("Size of the linked list: %d\n", size);
    // Free memory allocated for the linked list 
    free(head1);
    free(second);
    free(third);


	/*FT_LSTLAST*/
	printf("\nFT_LSTLAST\n");
	t_list *last_node;
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
    } else {
		printf("The list is empty.\n"); 
    }
    // Free memory allocated for the linked list 
    free(head1); 
    free(second); 
    free(third); 

	/*FT_LSTADD_BACK*/
	printf("\nFT_LSTADD_BACK\n");
   // Create the first node 
	head1 = ft_lstnew("First");
    // Print the initial list 
    printf("Initial list:\n"); 
    print_list(head1); 
    // Create a new node
	new_node = ft_lstnew("Second");
    // Add the new node to the back of the list 
    ft_lstadd_back(&head1, new_node); 
    // Print the updated list 
    printf("\nList after adding a new node at the back:\n"); 
    print_list(head1); 
    // Free memory allocated for the linked list 
    free_list(head1);

	/*FT_LSTDELONE*/
	printf("\nFT_LSTDELONE\n");
    // Create a node with some content
	head1 = ft_lstnew("Heythere");
    // Print the content of the node before deletion 
    printf("Content of the node before deletion: %s\n", (char *)head1->content);
    // Call ft_lstdelone to delete the node 
	ft_lstdelone(head1, del_content); 
    // Print a message after deletion 
    printf("Node deleted successfully.\n"); 
	/*FT_LSTCLEAR*/
	t_list *current;
	printf("\nFT_LSTCLEAR\n");
	    // Create a linked list with three nodes
	head1 = ft_lstnew("First");

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

	/*FT_LSTITER*/
	printf("\nFT_LSTITERT\n");

	head1 = ft_lstnew("First");
    head1->next = (t_list *)malloc(sizeof(t_list)); 
    head1->next->content = strdup("Second"); 
    head1->next->next = (t_list *)malloc(sizeof(t_list)); 
    head1->next->next->content = strdup("Third"); 
    head1->next->next->next = NULL;
    // Call ft_lstiter to apply print_content to each node's content 
    printf("Contents of the nodes:\n"); 
    ft_lstiter(head1, &print_content); 
    // Free memory allocated for the linked list 
   	// Liberar la memoria del nuevo nodo
	/*ft_lstdelone(new_node, &del_content);*/
	current = head1; 
	// Liberar la memoria de la lista enlazada
	ft_lstclear(&head1, &del_content);

	/*FT_LSTMAP*/
	printf("\nFT_LSTMAP\n");
	// Create a linked list with three nodes containing integers
	head1 = ft_lstnew((void *)1);
	ft_lstadd_back(&head1, ft_lstnew((void *)2)); 
    ft_lstadd_back(&head1, ft_lstnew((void *)3)); 
    // Print the original list 
	printf("Original list:\n"); 
    current = head1; 
    while (current != NULL)
	{ 

        printf("%d\n", (int)current->content); 

        current = current->next; 

    } 
    // Create a new list by adding one to each element of the original list 
    t_list *new_list = ft_lstmap(head1, &add_one, &del_content); 
    // Print the new list 
    printf("\nNew list after mapping:\n"); 
    current = new_list; 
    while (current != NULL) { 
        printf("%d\n", (int)current->content); 
        current = current->next;
    }
    // Free memory allocated for both lists 
    ft_lstclear(&head1, &del_content); 
    ft_lstclear(&new_list, &del_content);

	return 0; 

}
