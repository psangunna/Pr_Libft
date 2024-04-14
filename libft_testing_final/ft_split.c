/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psanguna <psanguna@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 16:02:25 by psanguna          #+#    #+#             */
/*   Updated: 2024/04/14 19:24:54 by psanguna         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

size_t	ft_strlen(const char *str);
void	*ft_memcpy(void *dest, const void *src, size_t n);
char	*ft_substr(char const *s, unsigned int start, size_t len);

// Helper function to count the words in a string
static size_t count_words(char const *str, char delimiter)
{
    size_t word_count;
    size_t index;

    // Initialize variables to store word count and index
    word_count = 0;
    index = 0;

    // Iterate through the string until null terminator is encountered
    while (str[index])
    {
        // If the current character is not the delimiter, increment word count
        if (str[index] != delimiter)
        {
            word_count++;

            // Advance index until delimiter or null terminator is encountered, skipping over the current word
            while (str[index] && str[index] != delimiter)
                index++;
        }
        // If the current character is the delimiter, move to the next character
        else if (str[index] == delimiter)
            index++;
    }

    // Return the total word count in the string
    return (word_count);
}

// Helper function to get the length of a word
static size_t get_word_length(char const *str, char delimiter)
{
    size_t length;

    // Initialize variable to store word length
    length = 0;

    // Calculate the length of the word until the delimiter or null terminator is encountered
    while (str[length] && str[length] != delimiter)
        length++;

    // Return the length of the word
    return (length);
}

// Helper function to free the memory of an array of strings
static void free_string_array(size_t size, char **array)
{
    // Free memory allocated for each string in the array
    while (size > 0)
    {
        size--;
        free(array[size]);
    }

    // Free memory allocated for the array itself
    free(array);
}

// Helper function to split a string into an array of substrings
static char **split_string(char const *str, char delimiter, char **array, size_t word_count)
{
    size_t str_index;
    size_t array_index;

    // Initialize variables to store string and array indices
    str_index = 0;
    array_index = 0;

    // Iterate through the string to split it into substrings
    while (array_index < word_count)
    {
        // Skip over delimiter characters at the beginning of a substring
        while (str[str_index] && str[str_index] == delimiter)
            str_index++;

        // Extract the substring for the current word and store it in the array
        array[array_index] = ft_substr(str, str_index, get_word_length(&str[str_index], delimiter));

        // If memory allocation fails, free previously allocated memory and return NULL
        if (!array[array_index])
        {
            free_string_array(array_index, array);
            return (0);
        }

        // Move to the next word in the string
        while (str[str_index] && str[str_index] != delimiter)
            str_index++;

        // Move to the next index in the array
        array_index++;
    }

    // Set the last element of the array to NULL to mark the end
    array[array_index] = NULL;

    // Return the array of substrings
    return (array);
}

/*Main function splits a string into an array of substrings 
based on a specified delimiter character.*/
char **ft_split(char const *str, char delimiter)
{
    char **array;
    size_t word_count;

    // Check if the input string is NULL
    if (!str)
        return (0);

    // Count the number of words in the string
    word_count = count_words(str, delimiter);

    // Allocate memory for the array of strings
    array = (char **)malloc(sizeof(char *) * (word_count + 1));

    // Check if memory allocation fails
    if (!array)
        return (0);

    // Split the string into an array of substrings
    array = split_string(str, delimiter, array, word_count);

    // Return the array of substrings
    return (array);
}

static void	ft_print_result(char const *s)
{
	int		len;

	len = 0;
	while (s[len])
		len++;
	write(1, s, len);
}

static void	ft_print_tabstr(char **tabstr)
{
	int		i;

	i = 0;
	while (tabstr[i] != NULL)
	{
		ft_print_result(tabstr[i]);
		write(1, "\n", 1);
		free(tabstr[i]);
		i++;
	}
	free(tabstr);
}

static void			check_split(char *s, char c)
{
	char	**tabstr;

	if (!(tabstr = ft_split(s, c)))
		ft_print_result("NULL");
	else
		ft_print_tabstr(tabstr);
}

int	main(int argc, const char *argv[])
{
	int		arg;

	if (argc == 1)
		return (0);
	if ((arg = atoi(argv[1])) == 1)
		check_split("          ", ' ');
	else if (arg == 2)
		check_split("May your heart be light and happy, may your smile be big and wide, and may your pockets always have a coin or two inside.", ' ');
	else if (arg == 3)
		check_split("   May your heart be light and happy, may your smile be big and wide. And may your pockets always have a coin or two inside.   ", ' ');
	else if (arg == 4)
		check_split("May your heart be light and happy, may your smile be big and wide, and may your pockets always have a coin or two inside..", 'i');
	else if (arg == 5)
		check_split("May your heart be light and happy, may your smile be big and wide, and may your pockets always have a coin or two inside.", 'y');
	else if (arg == 6)
		check_split("tripouille", 0);
	return (0);
}

size_t	ft_strlen(const char *str)
{
	size_t	counter;

	counter = 0;
	while (str[counter] != '\0')
	{
		counter++;
	}
	return (counter);
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;

	if (!dest || !src)
		return (0);
	i = 0;
	while (i < n)
	{
		((unsigned char *)dest)[i] = ((unsigned char *)src)[i];
		i++;
	}
	return (dest);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	s_len;
	size_t	sub_len;
	char	*substr;

	if (!s)
		return (0);
	s_len = ft_strlen(s);
	if (start >= s_len)
	{
		substr = (char *)malloc(sizeof(char));
		if (!substr)
			return (0);
		substr[0] = '\0';
		return (substr);
	}
	sub_len = len;
	if (start + len > s_len)
		sub_len = s_len - start;
	substr = (char *)malloc((sub_len + 1) * sizeof(char));
	if (!substr)
		return (0);
	ft_memcpy(substr, s + start, sub_len);
	substr[sub_len] = '\0';
	return (substr);
}
