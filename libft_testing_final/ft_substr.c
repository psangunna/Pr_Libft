/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psanguna <psanguna@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 15:57:11 by psanguna          #+#    #+#             */
/*   Updated: 2024/04/12 20:04:49 by psanguna         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include <unistd.h>
#include <string.h>
#include <stdlib.h>

size_t	ft_strlen(const char *str);
void	*ft_memcpy(void *dest, const void *src, size_t n);
/*Function takes a string s, a starting index start(It usually starts 
counting from 0, not from 1), and a maximum length len as input parameters. 
It then creates and returns a substring of s based on these parameters.*/
char *ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t s_len;
	size_t sub_len;
	char *substr;

	if (!s) // Verifica si la cadena de entrada es nula.
		return (0); // Si es nula, devuelve un puntero nulo.

	s_len = ft_strlen(s); 
	if (start >= s_len) // Verifica si el índice de inicio está más allá del final de la cadena de entrada.
	{
		substr = (char *)malloc(sizeof(char)); // Asigna memoria para una cadena vacía.
		if (!substr) // Verifica si la asignación de memoria fue exitosa.
			return (0); // Si no lo fue, devuelve un puntero nulo.
		substr[0] = '\0'; // Establece el primer carácter de la cadena vacía como nulo terminador.
		return (substr); // Devuelve el puntero a la cadena vacía.
	}
	sub_len = len; // Inicializa la longitud de la subcadena como la longitud especificada por el usuario.
	if (start + len > s_len) // Verifica si la subcadena se extiende más allá del final de la cadena de entrada.
		sub_len = s_len - start; // Si es así, ajusta la longitud de la subcadena para que termine en el final de la cadena de entrada.
	substr = (char *)malloc((sub_len + 1) * sizeof(char)); // Asigna memoria para la subcadena, más un carácter adicional para el nulo terminador.
	if (!substr) // Verifica si la asignación de memoria fue exitosa.
		return (0); // Si no lo fue, devuelve un puntero nulo.
	ft_memcpy(substr, s + start, sub_len); // Copia la subcadena de la cadena de entrada a la subcadena resultante.
	substr[sub_len] = '\0'; // Agrega el nulo terminador al final de la subcadena resultante.
	return (substr); // Devuelve el puntero a la subcadena resultante.
}

static void		ft_print_result(char const *s)
{
	int		len;

	len = 0;
	while (s[len])
		len++;
	write(1, s, len);
}

static void		check_substr(char *str, int start, int len)
{
	char	*substr;

	if (!(substr = ft_substr(str, start, len)))
		ft_print_result("NULL");
	else
		ft_print_result(substr);
	if (str == substr)
		ft_print_result("\nA new string was not returned");
	else
		free(substr);
}

int				main(int argc, const char *argv[])
{
	char	str[] = "Keep dreaming and moving everyday";
	int		arg;

	if (argc == 1)
		return (0);
	else if ((arg = atoi(argv[1])) == 1)
		check_substr(str, 0, 10);
	else if (arg == 2)
		check_substr(str, 7, 10);
	else if (arg == 3)
		check_substr(str, 7, 0);
	else if (arg == 4)
		check_substr(str, 0, 0);
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