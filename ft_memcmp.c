#include <unistd.h>
#include <stdio.h>
#include <string.h>
/*
function compares the first n bytes of the memory areas s1 and s2 byte by byte.
If all bytes are equal, it returns 0. If a difference is found, it returns 
the difference between the mismatched bytes.
*/
int	ft_memcmp(void *s1, void *s2, unsigned int n)
{
	unsigned char	*p1;
	unsigned char	*p2;
	unsigned int	i;

	i = 0;
	p1 = s1;
	p2 = s2;
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

/*int	main(void)
{
	char *str1 = "Hello, worlr!";
	char *str2 = "Hello, world!";
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
}*/
