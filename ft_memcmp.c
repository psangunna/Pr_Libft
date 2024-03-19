#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stddef.h>
/*
function compares the first n bytes of the memory areas str1 and str2 byte 
by byte.If all bytes are equal, it returns 0. If a difference is found, 
it returns the difference between the mismatched bytes.
*/
int	ft_memcmp(const void *ptr1, const void *ptr2, size_t n)
{
	unsigned char	*p1;
	unsigned char	*p2;
	size_t			i;

	i = 0;
	p1 = (unsigned char *)ptr1;
	p2 = (unsigned char *)ptr2;
	while (i < n)
	{
		if (p1[i] != p2[i])
		{
			return (p1[i] - p2[i]);
		}
		i++;
	}
	return (0);
}

int	main(void)
{
	char *str1 = "Hello,\0 worlr!";
	char *str2 = "Hello,\0 world!";
	unsigned int length;
	int result;
	

	length = 13;
	result = ft_memcmp(str1, str2, length);
	
	if (result == 0)
	{
		printf("Strings are equal: %d", result);
	}
	else if (result < 0)
	{
		printf("str1 is less than str2: %d", result);
	}
	else
	{
		printf("str1 is greater than str2; %d", result);
	}

	return (0);
}
