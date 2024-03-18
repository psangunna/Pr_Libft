#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

static void	*ft_memset(void *ptr, int value, int num)
{
	unsigned char	*p;
	int				i;

	p = ptr;
	i = 0;
	while (i < num)
	{
		p[i] = (unsigned char)value;
		i++;
	}
}
/*
function dynamically allocates memory for an array of elements and 
initializes them to zero.
nelem − This is the number of elements to be allocated.
elsize − This is the size of elements.
*/

void	*ft_calloc(unsigned int nelem, unsigned int elsize)
{
	unsigned int	total_size;
	void			*ptr;

	total_size = nelem * elsize;
	ptr = malloc(total_size);
	if (ptr != '\0')
	{
		ft_memset(ptr, 0, total_size);
	}
	return (ptr);
}
int	main(void)
{
    int *arr;
    unsigned int n;
	unsigned int i;

	n = 5;
    // Allocate memory for array of 5 integers
    //arr = (int *)ft_calloc(n, sizeof(int));
	arr = (int *)calloc(n, sizeof(int));
    if (arr == NULL)
	{
        printf("Memory allocation failed\n");
        return (1);
    }

    // Printing the initialized array
    printf("Initialized array:\n");
	i = 0;
    while (i < n)
	{
        printf("%d ", arr[i]);
		i++;
    }
    printf("\n");

    free(arr); // Free allocated memory

    return (0);
}
