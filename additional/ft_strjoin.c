#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>

/*
It gets the number of characters of the sring
*/
static size_t	ft_strlen(const char *str)
{
	size_t	counter;
	char	*str_aux;

	counter = 0;
	str_aux = (char *)str;
	while (*str_aux != '\0')
	{
		str_aux++;
		counter++;
	}
	return (counter);
}

/*
It copies the values of n bytes from the location pointed to by
src directly to the memory block pointed to by dest.
*/
static void	ft_memcpy(void *dest, void *src, size_t n)
{
	unsigned char	*d;
	size_t			i;
	unsigned char	*s;

	d = dest;
	i = 0;
	s = src;
	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
}

/*
function concatenates two strings by dynamically allocating memory and 
copying characters from both strings into the allocated memory space,
resulting in a single string containing the contents of both input strings
*/
char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	char	*new_str;

	if (s1 == ('\0') || s2 == ('\0'))
		return (0);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	new_str = (char *)malloc((s1_len + s2_len + 1) * sizeof(char));
	if (!new_str)
		return (0);
	ft_memcpy(new_str, (void *)s1, s1_len);
	ft_memcpy(new_str + s1_len, (void *)s2, s2_len);
	new_str[s1_len + s2_len] = '\0';
	return (new_str);
}

int	main(void)
{
	const char	s1[] = "Hello, ";
	const char	s2[] = "world!";
	char		*result;

	result = ft_strjoin(s1, s2);
	if (!result)
	{
		printf("Error: Falló la asignación de memoria.\n");
		return (1);
	}
	printf("Cadena concatenada: %s\n", result);
	free(result);
	return (0);
}
