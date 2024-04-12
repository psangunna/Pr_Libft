/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psanguna <psanguna@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 16:02:25 by psanguna          #+#    #+#             */
/*   Updated: 2024/04/12 20:16:13 by psanguna         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

size_t	ft_strlen(const char *str);
void	*ft_memcpy(void *dest, const void *src, size_t n);
char	*ft_substr(char const *s, unsigned int start, size_t len);
/*This function counts the number of words in a string delimited 
by a specified character.*/
#include <stdlib.h>

// Función auxiliar para contar las palabras en la cadena 's' delimitadas por el caracter 'c'
static size_t	count_words(char const *s, char c)
{
    size_t count = 0; // Inicializa el contador de palabras
    int in_word = 0; // Variable para rastrear si estamos dentro de una palabra o no

    // Itera a través de la cadena 's'
    while (*s)
    {
        if (*s == c) // Si el carácter actual es el delimitador 'c'
        {
            in_word = 0; // Estamos fuera de una palabra
        }
        else
        {
            if (!in_word) // Si estamos fuera de una palabra y encontramos un carácter no delimitador
            {
                count++; // Incrementa el contador de palabras
                in_word = 1; // Estamos dentro de una palabra
            }
        }
        s++; // Mueve el puntero al siguiente carácter
    }
    return count; // Devuelve el contador de palabras
}

// Función auxiliar para liberar la memoria asignada para el array de strings 'split'
static void	free_split(char **split, size_t i)
{
    while (i > 0)
    {
        free(split[i - 1]); // Libera la memoria asignada para cada string en 'split'
        i--;
    }
    free(split); // Libera la memoria asignada para 'split' en sí
}

// Función auxiliar para procesar cada palabra en la cadena 's', delimitada por 'c', y almacenarlas en el array 'split'
static int	treat_word(const char *s, char c, char **split, size_t word_count)
{
    const char *start; // Puntero al inicio de la palabra
    size_t len; // Longitud de la palabra
    size_t i = 0; // Índice para recorrer 'split'

    // Itera a través de 's' para dividir las palabras y almacenarlas en 'split'
    while (*s && i < word_count)
    {
        while (*s == c)
            s++; // Salta los delimitadores
        start = s; // Guarda el inicio de la palabra
        while (*s && *s != c)
            s++; // Avanza hasta el próximo delimitador o el final de la cadena
        len = s - start; // Calcula la longitud de la palabra
        split[i] = ft_substr(start, 0, len); // Almacena la palabra en 'split'
        if (!split[i]) // Verifica si la asignación de memoria falló
        {
            free_split(split, i); // Libera la memoria asignada anteriormente
            return 0; // Devuelve 0 para indicar un error
        }
        i++; // Incrementa el índice
    }
    split[i] = NULL; // Establece el último elemento de 'split' como NULL para marcar el final del array
    return 1; // Devuelve 1 para indicar éxito
}

// Función principal para dividir la cadena 's' en un array de substrings basados en el delimitador 'c'
char	**ft_split(char const *s, char c)
{
    size_t word_count; // Número de palabras en 's'
    char **split; // Array de punteros a strings

    if (!s || !c)
        return NULL; // Verifica si 's' o 'c' son nulos

    word_count = count_words(s, c); // Calcula el número de palabras en 's'
    split = (char **)malloc((word_count + 1) * sizeof(char *)); // Asigna memoria para 'split'
    if (!split)
        return NULL; // Devuelve NULL si falla la asignación de memoria

    if (!treat_word(s, c, split, word_count)) // Procesa cada palabra y las almacena en 'split'
        return NULL; // Devuelve NULL si ocurre un error durante el procesamiento de palabras

    return split; // Devuelve 'split' que contiene las palabras divididas de 's'
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
