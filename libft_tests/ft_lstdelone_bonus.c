/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psanguna <psanguna@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 10:09:18 by pamela            #+#    #+#             */
/*   Updated: 2024/04/12 11:40:07 by psanguna         ###   ########.fr       */
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
/*
function to free memory allocated for the content of a node.
It takes a node lst and a function pointer del as parameters.
It checks if both parameters are not NULL, and if they are valid, 
it frees the memory allocated for the content of the node using the
provided del function, and then frees the memory allocated for the node itself. 
*/
void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (lst && del)
	{
		del(lst->content);
		free(lst);
	}
}

int	main(void)
{
    t_list	*head2 = (t_list *)malloc(sizeof(t_list)); 
    if (head2== NULL) 
	{
		printf("Error de memoria");
    } 
    head2->content = strdup("Hey, there!"); 
    head2->next = NULL; 
    // Print the content of the node before deletion
	printf("Content of the node before deletion: %s\n", (char *)head2->content);
    // Call ft_lstdelone to delete the node 
	ft_lstdelone(head2, del_content); 
    // Print a message after deletion 
	printf("Node deleted successfully.\n");
}


static void		del_content(void *content)
{
	free(content);
}