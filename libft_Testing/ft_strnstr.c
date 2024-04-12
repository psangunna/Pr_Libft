/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psanguna <psanguna@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 15:50:06 by psanguna          #+#    #+#             */
/*   Updated: 2024/04/12 19:51:46 by psanguna         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include <stdlib.h>
#include <unistd.h>

char	*ft_strnstr(const char *str, const char *to_find, size_t len)
{
	size_t	i;
	size_t	j;

	if (!str) //evalua si el puntero es nulo
		return (0);
	if (!*to_find)//verifica que el primer caracter de la cadena es nulo
		return ((char *)str);
	i = 0;
	while (str[i] && i < len) //Bucle principal: recorre la cadena principal hasta alcanzar el final o la longitud máxima.
	{
		j = 0;
		//// Bucle interno: compara cada carácter de la subcadena con la cadena principal.
		while (str[i + j] == to_find[j] && (i + j) < len)
		{
			// Si se alcanza el final tanto de la cadena principal como de la subcadena, se encontró la subcadena dentro de la cadena principal
			if (str[i + j] == '\0' && to_find[j] == '\0')
				//Devuelve un puntero al comienzo de la coincidencia encontrada en la cadena principal
				return ((char *)str + i);
			j++;
		}
		// Si se llega al final de la subcadena, se encontró la subcadena dentro de la cadena principal.
		if (to_find[j] == '\0')
			// Devuelve un puntero al comienzo de la coincidencia encontrada en la cadena principal.
			return ((char *)str + i);
		i++;
	}
	return (0);
}

static void		ft_print_result(char const *s)
{
	int		len;

	len = 0;
	while (s[len])
		len++;
	write(1, s, len);
}

static void	check_strnstr(char *big, char *little, int len)
{
	const char *str;

	if (!(str = ft_strnstr(big, little, len)))
		ft_print_result("NULL");
	else
		ft_print_result(str);
}

int	main(int argc, const char *argv[])
{
	int			arg;

	if (argc == 1)
		return (0);
	else if ((arg = atoi(argv[1])) == 1)
		check_strnstr("Even black hens lay white eggs", "Even", 15);
	else if (arg == 2)
		check_strnstr("Even black hens lay white eggs", "black", 15);
	else if (arg == 3)
		check_strnstr("Even black hens lay white eggs", "black", 35);
	else if (arg == 4)
		check_strnstr("Even black hens lay white eggs", "", 10);
	else if (arg == 5)
		check_strnstr("Even black hens lay white eggs", "blackk", 30);
	else if (arg == 6)
		check_strnstr("Even black hens lay white eggs", "hens", 30);
	else if (arg == 7)
		check_strnstr("Even black hens lay white eggs", "white", 30);
	else if (arg == 8)
		check_strnstr("Even black hens lay white eggs", "lay", 10);
	else if (arg == 9)
		check_strnstr("Even black hens lay white eggs", "hens", 15);
	else if (arg == 10)
		check_strnstr("Even black hens lay white eggs", "hens", 0);
	return (0);
}