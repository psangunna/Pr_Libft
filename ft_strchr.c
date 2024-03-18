#include <unistd.h>
#include <stdio.h>
#include <string.h>

/*
function searches for the first occurrence of the character c in the string s.
It returns a pointer to the first occurrence of the character if found, or 
a pointer to the null terminator if the character is '\0' (the null terminator).
If the character is not found, it returns NULL
*/
char	*ft_strchr(char *s, int c)
{
	while (*s != '\0')
	{
		if (*s == c)
		{
			return (s);
		}
		s++;
	}
	if (c == '\0')
	{
		return (s);
	}
	return (0);
}

int	main(void)
{
    char *str = "Hello, world!";
    int character;
	char *result;

    character = 'm';
	result = ft_strchr(str, character);
   	printf("%s", result);
	
	//result = strchr(str, character);
	//printf("%s", result);
	return (0);
}