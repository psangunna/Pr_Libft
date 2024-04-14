/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psanguna <psanguna@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 15:59:33 by psanguna          #+#    #+#             */
/*   Updated: 2024/04/12 20:09:47 by psanguna         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include <unistd.h>
#include <string.h>
#include <stdlib.h>

size_t	ft_strlen(const char *str);
void	*ft_memcpy(void *dest, const void *src, size_t n);
char	*ft_strchr(const char *str, int c);
char	*ft_substr(char const *s, unsigned int start, size_t len);
/*
function removes leading and trailing characters from s1 that match any 
character in the set string. It returns a newly allocated string 
containing the trimmed characters.
If memory allocation fails at any point, it returns NULL.
*/
char *ft_strtrim(char const *s1, char const *set)
{
	size_t i; 

	if (!s1 || !set) // Verifica si alguna de las cadenas de entrada es nula.
		return (0); // Si alguna de las cadenas es nula, devuelve un puntero nulo.

	while (*s1 && ft_strchr(set, *s1)) // Itera a través de los caracteres al inicio de la cadena de entrada hasta que no se encuentre un carácter en el conjunto.
		s1++; // Avanza al siguiente carácter en la cadena de entrada.

	i = ft_strlen(s1); // Calcula la longitud de la cadena de entrada después de haber eliminado los caracteres del conjunto al inicio.

	while (i && ft_strchr(set, s1[i])) // Itera a través de los caracteres al final de la cadena de entrada hasta que no se encuentre un carácter en el conjunto.
		i--; // Retrocede al siguiente carácter en la cadena de entrada.

	return (ft_substr(s1, 0, i + 1)); // Devuelve una subcadena de la cadena de entrada que incluye los caracteres entre el inicio y el índice final (inclusivo), después de eliminar los caracteres del conjunto al inicio y al final de la cadena.
}

static void	ft_print_result(char const *s)
{
	int		len;

	len = 0;
	while (s[len])
		len++;
	write(1, s, len);
}

static void	check_strtrim(char *s1, char *set)
{
	char	*strtrim;

	if (!(strtrim = ft_strtrim(s1, set)))
		ft_print_result("NULL");
	else
		ft_print_result(strtrim);
	if (strtrim == s1)
		ft_print_result("\nA new string was not returned");
	else
		free(strtrim);
}

int	main(int argc, const char *argv[])
{
	char	set [] = "\t \n";
	int		arg;

	
	if (argc == 1)
		return (0);
	else if ((arg = atoi(argv[1])) == 1)
	{
		char s1[] = "Eat \n dance \tdream \n rest \t again";
		check_strtrim(s1, set);
	}
	else if (arg == 2)
	{
		char s1[] = "Eat dance dream rest again \n \t ";
		check_strtrim(s1, set);
	}
	else if (arg == 3)
	{
		char s1[] = " \n \t Eat dance dream rest again";
		check_strtrim(s1, set);
	}
	else if (arg == 4)
	{
		char s1[] = "  \n  \t  Eat \n dance \t dream \n rest \t again  \t \n ";
		check_strtrim(s1, set);
	}
	else if (arg == 5)
	{
		char s1[] = "          ";
		check_strtrim(s1, set);
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

char	*ft_strchr(const char *str, int c)
{
	while (*str != '\0' && *str != c)
	{
		str++;
	}
	if (*str == c)
	{
		return ((char *)str);
	}
	return (0);
}