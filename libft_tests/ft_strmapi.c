/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psanguna <psanguna@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 16:04:11 by psanguna          #+#    #+#             */
/*   Updated: 2024/04/29 10:44:23 by pamela           ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

size_t	ft_strlen(const char *str);
void	*ft_memcpy(void *dest, const void *src, size_t n);
char	*ft_strdup(const char *str);
/*
function takes a string s and applies a given function f to each character 
of the string.The function f is passed two arguments: the index of the character 
within the string and the character itself. It then generates a new string 
containing the result of applying the function f to each character successively.
*/
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*result;

	if (!s || !f)
		return (0);
	result = ft_strdup(s);
	if (!result)
		return (0);
	i = 0;
	while (result[i])
	{
		result[i] = f(i, result[i]);
		i++;
	}
	return (result);
}

static void	ft_print_result(char const *s)
{
	int		len;

	len = 0;
	while (s[len])
		len++;
	write(1, s, len);
}

static char	mapi(unsigned int i, char c)
{
	(void)i;//The variable is not used. This prevents errors during compilation.
	if (c >= 'a' && c <= 'z')
		return (c - 32);
	else if (c >= 'A' && c <= 'Z')
		return (c + 32);
	else
		return (c);
}

int	main(int argc, const char *argv[])
{
	char	*str;
	char	*strmapi;

	str = (char *)malloc(sizeof(*str) * 12);
	if (argc == 1 || !str)
	{
		printf("here");
		return (0);		
	}
	else if (atoi(argv[1]) == 1)
	{
		strcpy(str, "Smile & fun");
		if (!(strmapi = ft_strmapi(str, &mapi)))
			ft_print_result("NULL");
		else
		{
			ft_print_result(strmapi);
			if (strmapi[11] != '\0')
				ft_print_result("\nString is not null terminated");
			if (strmapi == str)
				ft_print_result("\nA new string was not returned");
			else
				free(strmapi);
		}
	}
	free(str);
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
