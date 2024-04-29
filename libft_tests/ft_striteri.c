/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psanguna <psanguna@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 16:05:04 by psanguna          #+#    #+#             */
/*   Updated: 2024/04/29 10:43:52 by pamela           ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
/*
function iterates over each character of the string s and applies a given 
function f to each character. The function f is passed two arguments: 
the index of the character within the string and a pointer to the character 
itself. This function f can modify the character if necessary.
*/
void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	if (!s || !f)
		return ;
	i = 0;
	while (s[i])
	{
		f(i, &s[i]);
		i++;
	}
}

/* Función de ejemplo para utilizar con ft_striteri */
/*void	print_index_and_char(unsigned int index, char *c)
{
	printf("Character at index %u is '%c'\n", index, *c);
}*/

static void		ft_print_result(char const *s)
{
	int		len;

	len = 0;
	while (s[len])
		len++;
	write(1, s, len);
}

static void		iter(unsigned int i, char *c)
{
	(void)i;
	if (*c >= 'a' && *c <= 'z')
		*c = *c - 32;
	else if (*c >= 'A' && *c <= 'Z')
		*c = *c + 32;
}

int	main(int argc, const char *argv[])
{
	char	*str;
	
	str = (char *)malloc(sizeof(*str) * 12);
	if (argc == 1 || !str)
		return (0);
	else if (atoi(argv[1]) == 1)
	{
		strcpy(str, "Smile & fun");
		ft_striteri(str, &iter);
		ft_print_result(str);
	}
	free(str);
	return (0);
}
