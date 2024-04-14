#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

size_t	ft_strlen(const char *str);
void	*ft_memcpy(void *dest, const void *src, size_t n);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strdup(const char *str);
/*This function counts the number of words in a string delimited 
by a specified character.*/
static size_t	count_words(char const *s, char c)
{
	size_t	count;
	int		in_word;

	count = 0;
	in_word = 0;
	while (*s)
	{
		if (*s == c)
		{
			in_word = 0;
		}
		else
		{
			if (!in_word)
			{
				count++;
				in_word = 1;
			}
		}
		s++;
	}
	return (count);
}

/*It deallocates memory allocated for the array of strings split*/
static void	free_split(char **split, size_t i)
{
	while (i > 0)
	{
		free(split[i - 1]);
		i--;
	}
	free (split);
}

/*It processes each word in the string s, delimited by the character c, 
and stores them in the array split.*/
static int	treat_word(const char *s, char c, char **split, size_t word_count)
{
	const char	*start;
	size_t		len;
	size_t		i;

	i = 0;
	while (*s && i < word_count)
	{
		while (*s == c)
			s++;
		start = s;
		while (*s && *s != c)
			s++;
		len = s - start;
		split[i] = ft_substr(start, 0, len);
		if (!split[i])
		{
			free_split(split, i);
			return (0);
		}
		i++;
	}
	split[i] = NULL;
	return (1);
}

/*The delimiter is a null*/
static int	treat_null_del(const char *s, char **split)
{
	split[0] = ft_strdup(s);
	if (!split[0])
	{
		free(split);
		return (0);
	}
	split[1] = NULL;
	return (1);
}

/*This function splits a string into an array of substrings 
based on a specified delimiter character.*/
char	**ft_split(char const *s, char c)
{
	size_t		word_count;
	char		**split;

	split = NULL;
	if (!s)
		return (0);
	if (c == '\0')
		word_count = 1;
	else
		word_count = count_words(s, c);
	split = (char **)malloc((word_count + 1) * sizeof(char *));
	if (!split)
		return (0);
	if (c == '\0')
	{
		if (!treat_null_del(s, split))
			return (0);
	}
	else
	{
		if (!treat_word(s, c, split, word_count))
			return (0);
	}
	return (split);
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

char	*ft_strdup(const char *str)
{
	size_t			len;
	char			*new_str;

	if (!str)
		return (0);
	len = ft_strlen(str) + 1;
	new_str = (char *)malloc(len * sizeof(char));
	if (!new_str)
		return (0);
	ft_memcpy(new_str, str, len);
	return (new_str);
}


static int	treat_null_del(const char *s, char **split)
{
	split[0] = ft_strdup(s);
	if (!split[0])
	{
		free(split);
		return (0);
	}
	split[1] = NULL;
	return (1);
}

/*This function splits a string into an array of substrings 
based on a specified delimiter character.*/
char	**ft_split(char const *s, char c)
{
	size_t		word_count;
	char		**split;

	split = NULL;
	if (!s)
		return (0);
	if (c == '\0')
		word_count = 1;
	else
		word_count = count_words(s, c);
	split = (char **)malloc((word_count + 1) * sizeof(char *));
	if (!split)
		return (0);
	if (c == '\0')
	{
		if (!treat_null_del(s, split))
			return (0);
	}
	else
	{
		if (!treat_word(s, c, split, word_count))
			return (0);
	}
	return (split);
}
