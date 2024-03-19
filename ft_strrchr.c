#include <unistd.h>
#include <stdio.h>
#include <string.h>

/*
function searches for the last occurrence of the character c in the string s. 
It returns a pointer to the last occurrence of the character if found, 
or a pointer to the null terminator if the character is '\0' 
(the null terminator).
If the character is not found, it returns NULL.
*/
char	*ft_strrchr(const char *str, int c)
{
	char	*str_aux;
	char	char_c;
	char	*last_value;

	last_value = 0;
	str_aux = (char *)str;
	char_c = (char)c;
	while (*str_aux != '\0')
	{
		if (*str_aux == char_c)
		{
			last_value = str_aux;
		}
		str_aux++;
	}
	if (char_c == '\0')
	{
		return (str_aux);
	}
	return (last_value);
}

int	main(void)
{
    char *str = "Hello, world!";
    int character;
	char *result;

    character = 'l';
	result = ft_strrchr(str, character);
   	printf("%s", result);
	
	//result = strrchr(str, character);
	//printf("%s", result);
	return (0);
}