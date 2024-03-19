#include <unistd.h>
#include <stdio.h>
#include <string.h>

/*
function searches for the first occurrence of the character c in the string s.
It returns a pointer to the first occurrence of the character if found, or 
a pointer to the null terminator if the character is '\0' (the null terminator).
If the character is not found, it returns NULL
*/
char	*ft_strchr(const char *str, int c)
{
	char	*str_aux;
	char	char_c;

	str_aux = (char *)str;
	char_c = (char)c;
	while (*str_aux != '\0')
	{
		if (*str_aux == char_c)
		{
			return (str_aux);
		}
		str_aux++;
	}
	if (char_c == '\0')
	{
		return (str_aux);
	}
	return (0);
}

int	main(void)
{
    char *str = "Hello, world!";
    int character;
	char *result;

    character = ',';
	result = ft_strchr(str, character);
   	printf("%s", result);
	
	//result = strchr(str, character);
	//printf("%s", result);
	return (0);
}