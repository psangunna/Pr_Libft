/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psanguna <psanguna@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 10:07:09 by pamela            #+#    #+#             */
/*   Updated: 2024/04/29 11:05:23 by pamela           ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>

typedef struct s_list
{
    void			*content;
    struct s_list   *next;
}t_list;

/*
Adds a new node at the beginning of a linked list.
*/
void	ft_lstadd_front(t_list **lst, t_list *new)
{
	//printf("%d",  *(int *)new->content);
	if (!new)
		return ;
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
			ft_lstadd_front(&cab,node);
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
