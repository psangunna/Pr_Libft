#include "libft.h"

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
