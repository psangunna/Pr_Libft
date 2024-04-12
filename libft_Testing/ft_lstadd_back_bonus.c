/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psanguna <psanguna@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 10:08:28 by pamela            #+#    #+#             */
/*   Updated: 2024/04/12 11:27:36 by psanguna         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct s_list
{
        void                    *content;
        struct s_list   *next;
}       t_list;

static t_list	*ft_lstlast(t_list *lst);
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



static t_list *crearLista()
{
	t_list *cabeza = NULL;
	return (cabeza);
}

static t_list *CrearNodo(void *x)
{
	t_list *a;

	a = (t_list*)malloc(sizeof(t_list));
	if (!a)
		return (0);
	a->content = x,
	a->next = NULL;
	return (a);
}

static void imprimirLista(t_list *cabeza)
{
	t_list *actual;
	printf("la lista es: \n");
	for (actual = cabeza; actual != NULL; actual = actual->next)
	{
		printf("%d", *(int *)actual->content);
	}
	printf("\n\n");
}

int	main(void)
{
	t_list *cab;
	t_list *node;
	int *valor;
	int i;

	cab = crearLista();
	for (i=0; i<10; i++)
	{
		valor = (int *)malloc(sizeof(int)); // Allocate memory for an int
        if (!valor)
            return (0); // Memory allocation failed
        *valor = i; // Store the value of i
        node = CrearNodo(valor);
		//printf("%d",  *(int *)node->content);
		if (node)
			ft_lstadd_back(&cab,node);
			//printf("%d",  *(int *)cab->content);
	}
	imprimirLista(cab);

	// Free memory
    t_list *temp;
    while (cab)
    {
        temp = cab->next;
        free(cab->content); // Free the memory allocated for the int value
        free(cab); // Free the memory allocated for the node
        cab = temp;
    }
	return (0);
}

static t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (0);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}