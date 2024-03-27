#include <stdlib.h>
#include <string.h>
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
function searches for the first occurrence of the character c in the string s.
It returns a pointer to the first occurrence of the character if found, or 
a pointer to the null terminator if the character is '\0' (the null terminator).
If the character is not found, it returns NULL
*/
static char	*ft_strchr(const char *str, int c)
{
	char	*str_aux;
	char	char_c;

	str_aux = (char *)str;
	char_c = (char)c;
	while (*str_aux != '\0')
	{
		if (*str_aux == char_c)
			return (str_aux);
		str_aux++;
	}
	if (char_c == '\0')
		return (str_aux);
	return (0);
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
function removes leading and trailing characters from s1 that match any 
character in the set string. It returns a newly allocated string 
containing the trimmed characters.
If memory allocation fails at any point, it returns NULL.
*/
char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	len;
	char	*trimmed;
	char	*s1_aux;

	s1_aux = (char *)s1;
	if (s1_aux == '\0' || set == '\0')
		return (0);
	while (*s1_aux && ft_strchr(set, (int)*s1_aux) != '\0')
		s1_aux++;
	len = ft_strlen(s1);
	while (len > 0 && ft_strchr(set, (int)s1_aux[len - 1]) != '\0')
		len--;
	trimmed = (char *)malloc((len + 1) * sizeof(char));
	if (trimmed == '\0')
		return (0);
	ft_memcpy(trimmed, (void *)s1_aux, len);
	trimmed[len] = '\0';
	return (trimmed);
}

int	main(void)
{
	char	s1[] = "x\t-Hello World?\tx-";
	char	set[] = "x\t";
	char	*trimmed_str;

	trimmed_str = ft_strtrim(s1, set);
	if (trimmed_str == '\0')
	{
		printf("Error: Memory allocation failed.\n");
		return (1);
	}
	printf("Trimmed string: \"%s\"\n", trimmed_str);
	free(trimmed_str);
	return (0);
}