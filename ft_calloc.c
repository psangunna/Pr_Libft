#include "libft.h"

void	*ft_calloc(size_t nelem, size_t elsize)
{
	size_t	total_size;
	void	*ptr;

	total_size = nelem * elsize;
	ptr = malloc(total_size);
	if (!ptr)
		return (0);
	ft_memset(ptr, 0, total_size);
	return (ptr);
}
