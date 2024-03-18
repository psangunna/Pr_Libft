#include <stdlib.h>
#include <stdio.h>
/*
function concatenates two strings by dynamically allocating memory and 
copying characters from both strings into the allocated memory space,
resulting in a single string containing the contents of both input strings
*/
char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	size_t	i;
	size_t	j;
	char	*new_str;

	// Check if either s1 or s2 is NULL
	if (s1 == '\0' || s2 == '\0')
		return (0);
	// Calculate the lengths of s1 and s2
	s1_len = 0;
	while (s1[s1_len] != '\0')
		s1_len++;
	s2_len = 0;
	while (s2[s2_len] != '\0')
		s2_len++;
	// Allocate memory for the new string
	new_str = (char *)malloc((s1_len + s2_len + 1) * sizeof(char));
	if (new_str == '\0')
		return (0);
	// Copy characters from s1 to new_str
	i = 0;
	while (s1[i] != '\0')
	{
		new_str[i] = s1[i];
		i++;
	}
	// Copy characters from s2 to new_str
	j = 0;
	while (s2[j] != '\0')
	{
		new_str[i + j] = s2[j];
		j++;
	}
	// Add null terminator at the end
	new_str[i + j] = '\0';
	return (new_str);
}
/*int	main(void)
{
    // Example strings to concatenate
    char s1[] = "Hello, ";
    char s2[] = "world!";
	char *result;

    // Call ft_strjoin to concatenate s1 and s2
    result = ft_strjoin(s1, s2);

    // Check if ft_strjoin was successful
    if (result == NULL) {
        printf("Error: Memory allocation failed.\n");
        return 1;
    }

    // Print the concatenated string
    printf("Concatenated string: %s\n", result);

    // Free the allocated memory for the result
    free(result);

    return (0);
}*/