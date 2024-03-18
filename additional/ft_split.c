#include <stdlib.h>
#include <stdio.h>

// Function to get the number of words in a string
static int	ft_count_words(char const *s, char c)
{
	int	count;
	int	in_word;

	count = 0;
	in_word = 0;
	while (*s)
	{
		if (*s != c)
		{
			if (!in_word)
			{
				count++;
				in_word = 1;
			}
		}
		else
		{
			in_word = 0;
		}
		s++;
	}
	return (count);
}

// Function to get the length of a word
static int	ft_word_length(char const *s, char c)
{
	int	len;

	len = 0;
	while (*s && *s != c)
	{
		len++;
		s++;
	}
	return (len);
}

// Function to free memory allocated for array of strings
static void	ft_free_array(char **str_array, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		free(str_array[i]);
		i++;
	}
	free(str_array);
}

/*
function splits a given string s into 
an array of strings based on a specified delimiter c. 
*/
char	**ft_split(char const *s, char c)
{
	int		num_words;
	int		i;
	int		j;
	char	**str_array;
	int		word_len;

	if (s == '\0')
		return (0);
	num_words = ft_count_words(s, c);
	str_array = (char **)malloc((num_words + 1) * sizeof(char *));
	if (str_array == '\0')
		return (0);
	i = 0;
	while (*s)
	{
		if (*s != c)
		{
			word_len = ft_word_length(s, c);
			str_array[i] = (char *)malloc((word_len + 1) * sizeof(char));
			if (str_array[i] == '\0')
			{
				ft_free_array(str_array, i);
				return (0);
			}
			j = 0;
			while (j< word_len)
			{
				str_array[i][j] = *s;
				j++;
				s++;
			}
			str_array[i][word_len] = '\0';
			i++;
		}
		else
		{
			s++;
		}
	}
	str_array[num_words] = '\0';
	return (str_array);
}

int	main(void)
{
    // Example string to split and delimiter character
    char s[] = "Hello,world,this,is,an,example";
    char delimiter = ',';

    // Call ft_split to split s using delimiter
    char **result = ft_split(s, delimiter);

    // Check if ft_split was successful
    if (result == NULL) {
        printf("Error: Memory allocation failed.\n");
        return 1;
    }

    // Print the array of strings
    for (int i = 0; result[i] != NULL; i++) {
        printf("%s\n", result[i]);
    }

    // Free the memory allocated for the array of strings
    ft_free_array(result, ft_count_words(s, delimiter));

    return 0;
}