/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psanguna <psanguna@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 19:16:06 by psanguna          #+#    #+#             */
/*   Updated: 2024/03/16 20:02:21 by psanguna         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

/*#include <stdio.h>
#include <string.h>*/

static int	ft_strlen(char *str)
{
	int	n;

	n = 0;
	while (*str++)
		n++;
	return (n);
}

/*function is used in C to concatenate two strings with a specified maximum 
size, ensuring that the destination buffer does not overflow.*/
unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	len_dest;
	unsigned int	len_source;
	unsigned int	rest;

	len_dest = ft_strlen(dest);
	if (size < len_dest + 1)
		return (size + ft_strlen(src));
	rest = size - len_dest - 1;
	len_source = 0;
	while (src[len_source] != '\0' && rest > 0)
	{
		dest[len_dest] = src[len_source];
		len_dest++;
		len_source++;
		rest--;
	}
	dest[len_dest] = '\0';
	return (len_dest);
}
/*int	main(void)
{
	char	a[13] = "123";
	char	*b = " azul";
	unsigned int len_total;
	//len_total = strlcat(a, b, sizeof(a));
	//printf("length:%i\n",len_total);
	//printf("variable destino:%s",a);
	//length:8 variable destino:123 azul%

	len_total = ft_strlcat(a, b, sizeof(a));
	printf("length:%i\n",len_total);
	printf("variable destino:%s\n",a);
	return (0);
}*/
