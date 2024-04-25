/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psanguna <psanguna@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 16:02:25 by psanguna          #+#    #+#             */
/*   Updated: 2024/04/15 12:39:07 by psanguna         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

size_t	ft_strlen(const char *str);
void	*ft_memcpy(void *dest, const void *src, size_t n);
char	*ft_substr(char const *s, unsigned int start, size_t len);

/* Helper function to count the words in a string */
static size_t count_words(char const *str, char delimiter)
{
    size_t word_count; // Variable para contar el número de palabras
    size_t index; // Índice para recorrer la cadena de caracteres

    word_count = 0; // Inicializa el contador de palabras
    index = 0; // Inicializa el índice
    while (str[index]) // Itera hasta llegar al final de la cadena
    {
        if (str[index] != delimiter) // Si el carácter actual no es el delimitador
        {
            word_count++; // Incrementa el contador de palabras
            while (str[index] && str[index] != delimiter) // Avanza hasta el próximo delimitador o el final de la cadena
                index++; // Avanza al siguiente carácter
        }
        else if (str[index] == delimiter) // Si el carácter actual es el delimitador
            index++; // Avanza al siguiente carácter
    }
    return (word_count); // Retorna el número total de palabras encontradas
}

/* Helper function to get the length of a word */
static size_t get_word_length(char const *str, char delimiter)
{
    size_t length; // Variable para almacenar la longitud de la palabra

    length = 0; // Inicializa la longitud de la palabra
    while (str[length] && str[length] != delimiter) // Itera hasta encontrar un delimitador o el final de la cadena
        length++; // Incrementa la longitud de la palabra
    return (length); // Retorna la longitud de la palabra encontrada
}

/* Helper function to free the memory of an array of strings */
static void free_string_array(size_t size, char **array)
{
    while (size > 0) // Itera sobre el arreglo de cadenas de caracteres
    {
        size--; // Decrementa el índice
        free(array[size]); // Libera la memoria de la cadena de caracteres actual
    }
    free(array); // Libera la memoria del arreglo de punteros
}

/* Helper function to split a string into an array of substrings */
static char **split_string(char const *str, char delimiter,
                           char **array, size_t word_count)
{
    size_t str_index; // Índice para recorrer la cadena de caracteres
    size_t array_index; // Índice para recorrer el arreglo de punteros

    str_index = 0; // Inicializa el índice para recorrer la cadena de caracteres
    array_index = 0; // Inicializa el índice para recorrer el arreglo de punteros
    while (array_index < word_count) // Itera hasta alcanzar el número total de palabras
    {
        while (str[str_index] && str[str_index] == delimiter) // Avanza hasta el próximo delimitador o el final de la cadena
            str_index++; // Avanza al siguiente carácter
        array[array_index] = ft_substr(str, str_index, // Almacena la subcadena en el arreglo de punteros
                                       get_word_length(&str[str_index], delimiter)); // Obtiene la longitud de la palabra
        if (!array[array_index]) // Si no se pudo asignar memoria para la subcadena
        {
            free_string_array(array_index, array); // Libera la memoria asignada hasta el momento
            return (0); // Retorna NULL
        }
        while (str[str_index] && str[str_index] != delimiter) // Avanza hasta el próximo delimitador o el final de la cadena
            str_index++; // Avanza al siguiente carácter
        array_index++; // Avanza al siguiente índice del arreglo de punteros
    }
    array[array_index] = NULL; // Establece el último elemento del arreglo de punteros como NULL o '\0'
    return (array); // Retorna el arreglo de punteros
}

/* Main function to split a string into an array of substrings */
char **ft_split(char const *str, char delimiter)
{
    char **array; // Arreglo de punteros para almacenar las subcadenas
    size_t word_count; // Número total de palabras en la cadena

    if (!str) // Verifica si la cadena es nula
        return (0); // Retorna NULL
    word_count = count_words(str, delimiter); // Cuenta el número de palabras en la cadena
    array = (char **)malloc(sizeof(char *) * (word_count + 1)); // Asigna memoria para el arreglo de punteros
    if (!array) // Si no se pudo asignar memoria
        return (0); // Retorna NULL
    array = split_string(str, delimiter, array, word_count); // Divide la cadena en subcadenas y las almacena en el arreglo
    return (array); // Retorna el arreglo de punteros
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
