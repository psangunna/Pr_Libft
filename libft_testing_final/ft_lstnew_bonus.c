/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psanguna <psanguna@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 10:05:25 by pamela            #+#    #+#             */
/*   Updated: 2024/04/12 09:54:26 by psanguna         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

typedef struct s_list
{
        void                    *content;
        struct s_list   *next;
}       t_list;

/*
It dynamically allocates memory for a new node in a linked list,
initializes its content, and returns a pointer to the newly created node
*/
t_list	*ft_lstnew(void *content)
{
	t_list	*new_node;

	new_node = (t_list *)malloc(sizeof(t_list));
	if (!new_node)
		return (0);
	new_node->content = content;
	new_node->next = NULL;
	return (new_node);
}


int	main(int argc, const char *argv[])
{
	t_list		*elem;
	int			arg;


	elem = NULL;
	if (argc == 1)
		return (0);
	else if ((arg = atoi(argv[1])) == 1)
	{
		elem =ft_lstnew("Keep dreaming and moving on");
		printf("contenido del node: %s",(unsigned char *)elem->content);
	}
	else if (arg == 2)
	{
		elem = ft_lstnew(&arg);
		printf("contenido del node: %i", arg);
		printf("contenido del node: %i", *(int *)elem->content);
	}
	else if (arg == 3)
	{
		elem = ft_lstnew(NULL);
		printf("contenido del node: %s", (unsigned char *)elem->content);
	}
	free(elem);
	return (0);
}