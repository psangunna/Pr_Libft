#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

static char	*ft_strcpy(char *dest, const char *src)
{
	char	*src_aux;
	char	*dest_aux;

	dest_aux = dest;
	src_aux = (char *)src;
	while (*src_aux != '\0')
	{
		*dest_aux = *src_aux;
		dest_aux++;
		src_aux++;
	}
	*dest_aux = '\0';
	return (dest);
}

/*
function duplicates a string. It dynamically allocates memory for a new string, 
copies the content of the input string into the allocated memory, 
and returns a pointer to the new string.
*/
char	*ft_strdup(const char *str)
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

int	main(void)
{
	char *original;
	char *duplicate;

	original = "Hello, world!";
    // Duplicate the string
    //duplicate = strdup(original);
    duplicate = ft_strdup(original);
    if (duplicate != NULL) {
        printf("Original: %s\n", original);
        printf("Duplicate: %s\n", duplicate);
        
        // Remember to free the allocated memory when done
        free(duplicate);
    } else {
        printf("Memory allocation failed.\n");
    }
	return (0);
}