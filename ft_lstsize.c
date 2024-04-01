#include "libft.h"

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
