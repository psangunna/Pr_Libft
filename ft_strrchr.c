#include <unistd.h>
#include <stdio.h>
#include <string.h>

/*
function searches for the last occurrence of the character c in the string s. 
It returns a pointer to the last occurrence of the character if found, 
or a pointer to the null terminator if the character is '\0' (the null terminator).
If the character is not found, it returns NULL.
*/
char	*ft_strrchr(char *s, int c)
{
    char *last_value;

    last_value = 0;
	while (*s != '\0')
	{
		if (*s == c)
		{
			last_value = s;
		}
		s++;
	}
	if (c == '\0')
	{
		return (s);
	}
	return (last_value);
}

int	main(void)
{
    char *str = "Hello, world!";
    int character;
	char *result;

    character = 'r';
	result = ft_strrchr(str, character);
   	printf("%s", result);
	
	//result = strrchr(str, character);
	//printf("%s", result);
	return (0);
}