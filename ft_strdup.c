#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static int	ft_strlen(char *str)
{
	int	counter;

	counter = 0;
	while (*str != '\0')
	{
		str++;
		counter++;
	}
	return (counter);
}

static char	*ft_strcpy(char *dest, char *src)
{
	char	*dest_aux;

	dest_aux = dest;
	while (*src != '\0')
	{
		*dest = *src;
		dest++;
		src++;
	}
	*dest = '\0';
	return (dest_aux);
}
/*
function duplicates a string. It dynamically allocates memory for a new string, 
copies the content of the input string into the allocated memory, 
and returns a pointer to the new string.
*/

char	*ft_strdup(char *str)
{
	unsigned int	len;
	char			*new_str;

	len = ft_strlen(str) + 1;
	new_str = malloc(len);
	if (new_str != '\0')
	{
		ft_strcpy(new_str, str);
	}
	return (new_str);
}
/*int	main(void)
{
	char *original;
	char *duplicate;

	original = "Hello, world!";
    // Duplicate the string
    duplicate = strdup(original);
    //duplicate = ft_strdup(original);
    if (duplicate != NULL) {
        printf("Original: %s\n", original);
        printf("Duplicate: %s\n", duplicate);
        
        // Remember to free the allocated memory when done
        free(duplicate);
    } else {
        printf("Memory allocation failed.\n");
    }
	return (0);
}*/