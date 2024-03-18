#include <stdlib.h>
#include <stdio.h>

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

static char    *ft_strchr(const char *s, int c)
{
	while (*s != '\0')
	{
		if (*s == c)
		{
			return (char *)s; // Return a pointer to the first occurrence of the character
		}
		s++; // Move to the next character in the string
	}
	if (c == '\0')
	{
		return (char *)s; // Return a pointer to the null terminator if the character is '\0'
	}
	return (0); // Return NULL if the character is not found
}
/*
function removes leading and trailing characters from s1 that match any character 
in the set string. It returns a newly allocated string containing 
the trimmed characters.
If memory allocation fails at any point, it returns NULL.
*/
char    *ft_strtrim(char const *s1, char const *set)
{
	size_t  s1_len;
	size_t  set_len;
	size_t  start_index;
	size_t  end_index;
	size_t  trimmed_len; 
	char    *trimmed_str;
	size_t  i;
	// Check if either s1 or set is NULL
	if (s1 == '\0' || set == '\0')
		return (0);

	// Find the length of s1 and set
	s1_len = ft_strlen((char *)s1);
	set_len = ft_strlen((char *)set);
	
	// Calculate the number of characters to trim from the beginning
	start_index = 0;
	while (start_index < s1_len && ft_strchr(set, s1[start_index]) != '\0')
	{
		start_index++;
	}
	// Calculate the number of characters to trim from the end
	end_index = s1_len;
	while (end_index > start_index && ft_strchr(set, s1[end_index - 1]) != '\0')
	{
		end_index--;
	}

	// Calculate the length of the trimmed string
	trimmed_len = end_index - start_index;

	// Allocate memory for the trimmed string
	trimmed_str = (char *)malloc((trimmed_len + 1) * sizeof(char));
	if (trimmed_str == '\0')
		return (0);

	// Copy the trimmed characters to the new string
	i = 0;
	while (i < trimmed_len)
	{
		trimmed_str[i] = s1[start_index + i];
		i++;
	}

	trimmed_str[trimmed_len] = '\0'; // Add null terminator
	return (trimmed_str);
}
int main(void)
{
	// Example string to trim and set of characters to trim
	char s1[] = "  \t  Example string to trim  \n  ";
	char set[] = " \n";

	// Call ft_strtrim to trim s1 using set
	char *trimmed_str = ft_strtrim(s1, set);

	// Check if ft_strtrim was successful
	if (trimmed_str == NULL) {
		printf("Error: Memory allocation failed.\n");
		return (1);
	}

	// Print the trimmed string
	printf("Trimmed string: \"%s\"\n", trimmed_str);

	// Free the allocated memory for the trimmed string
	free(trimmed_str);

	return (0);
}