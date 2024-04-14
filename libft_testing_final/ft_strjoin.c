/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psanguna <psanguna@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 15:58:28 by psanguna          #+#    #+#             */
/*   Updated: 2024/04/12 20:07:06 by psanguna         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include <unistd.h>
#include <string.h>
#include <stdlib.h>

size_t	ft_strlen(const char *str);
void	*ft_memcpy(void *dest, const void *src, size_t n);
char	*ft_substr(char const *s, unsigned int start, size_t len);
/*
function concatenates two strings by dynamically allocating memory and 
copying characters from both strings into the allocated memory space,
resulting in a single string containing the contents of both input strings
*/
char *ft_strjoin(char const *s1, char const *s2)
{
	size_t s1_len;
	size_t s2_len;
	char *new_str;

	if (!s1 || !s2) // Verifica si alguna de las cadenas de entrada es nula.
		return (0); // Si alguna de las cadenas es nula, devuelve un puntero nulo.

	s1_len = ft_strlen(s1); // Calcula la longitud de la primera cadena.
	s2_len = ft_strlen(s2); // Calcula la longitud de la segunda cadena.

	new_str = (char *)malloc((s1_len + s2_len + 1) * sizeof(char)); // Asigna memoria para la cadena resultante, más un carácter adicional para el nulo terminador.
	if (!new_str) // Verifica si la asignación de memoria fue exitosa.
		return (0); // Si no lo fue, devuelve un puntero nulo.

	ft_memcpy(new_str, s1, s1_len); // Copia la primera cadena en la cadena resultante.
	ft_memcpy(new_str + s1_len, s2, s2_len); // Copia la segunda cadena después de la primera cadena en la cadena resultante.
	new_str[s1_len + s2_len] = '\0'; // Agrega el nulo terminador al final de la cadena resultante.

	return (new_str); // Devuelve un puntero a la cadena resultante.
}

static void	ft_print_result(char const *s)
{
	int		len;

	len = 0;
	while (s[len])
		len++;
	write(1, s, len);
}

static void	check_strjoin(char *s1, char *s2)
{
	char	*strjoin;

	if (!(strjoin = ft_strjoin(s1, s2)))
		ft_print_result("NULL");
	else
		ft_print_result(strjoin);
	if (strjoin == s1 || strjoin == s2)
		ft_print_result("\nA new string was not returned");
	else
		free(strjoin);
}

int	main(int argc, const char *argv[])
{
	char	s1[] = "Hey everyone";
	char	s2[] = "have a good one";
	int		arg;

	if (argc == 1)
		return (0);
	else if ((arg = atoi(argv[1])) == 1)
	{
		check_strjoin(s1, s2);
	}
	else if (arg == 2)
	{
		s1[0] = '\0';
		check_strjoin(s1, s2);
	}
	else if (arg == 3)
	{
		s2[0] = '\0';
		check_strjoin(s1, s2);
	}
	else if (arg == 4)
	{
		s1[0] = '\0';
		s2[0] = '\0';
		check_strjoin(s1, s2);
	}
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