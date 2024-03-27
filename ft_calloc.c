#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

/*
function fills str with value of c. 
The value of c is copied as times as n indicates.
*/
static void	*ft_memset(void *ptr, int c, size_t n)
{
	unsigned char	*p;
	size_t			i;

	p = ptr;
	i = 0;
	while (i < n)
	{
		p[i] = (unsigned char)c;
		i++;
	}
}

/*
function dynamically allocates memory for an array of elements and 
initializes them to zero.
nelem − This is the number of elements to be allocated.
elsize − This is the size of elements.
*/
void	*ft_calloc(size_t nelem, size_t elsize)
{
	size_t	total_size;
	void	*ptr;

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
    arr = (int *)ft_calloc(n, sizeof(int));
	//arr = (int *)calloc(n, sizeof(int));
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
