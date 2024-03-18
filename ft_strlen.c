/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psanguna <psanguna@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 13:30:19 by psanguna          #+#    #+#             */
/*   Updated: 2024/03/18 15:58:33 by psanguna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stddef.h>
#include <stdio.h>
#include <string.h>
/*
It gets the number of characters of the sring
*/
size_t	ft_strlen(const char *str)
{
	size_t	counter;
	char	*str_aux;

	counter = 0;
	str_aux = (char *)str;
	while (*str_aux != '\0')
	{
		str_aux++;
		counter++;
	}
	return (counter);
}

/*int	main(void)
{
	const char	s[13] = "Hola a todos";

	printf("s = %s\n", s);
	printf("len(s) = %lu\n", ft_strlen(s));
	return (0);
}*/
