#include <stdio.h>
#include <string.h>
#include <stddef.h>
/*
It gets the number of characters of the sring
*/
static size_t	ft_strlen(const char *str)
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

/*
It copies the values of n bytes from the location pointed to by
src directly to the memory block pointed to by dest.
*/
static void	ft_memcpy(void *dest, void *src, size_t n)
{
	unsigned char	*d;
	size_t			i;
	unsigned char	*s;

	d = dest;
	i = 0;
	s = src;
	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
}

/*function is used in C to concatenate two strings with a specified maximum 
size, ensuring that the destination buffer does not overflow.*/
size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	len_dest;
	size_t	len_source;
	size_t	rest;
	size_t	rest_cpy;

	len_dest = ft_strlen(dest);
	if (size < len_dest + 1)
		return (size + ft_strlen(src));
	rest = size - len_dest - 1;
	len_source = 0;
	rest_cpy = rest;
	if (rest > ft_strlen(src))
		rest_cpy = ft_strlen(src);
		//printf("%i", rest_cpy);
	ft_memcpy(dest + len_dest, (char *)src, rest_cpy);
	dest[len_dest + rest_cpy] = '\0';
	return (len_dest + rest_cpy);
}

int	main(void)
{
	char	a[13] = "123";
	const char	*b = "";
	size_t len_total;
	//len_total = strlcat(a, b, sizeof(a));
	//printf("length:%i\n",len_total);
	//printf("variable destino:%s",a);

	len_total = ft_strlcat(a, b, 13);
	printf("length:%i\n",len_total);
	printf("variable destino:%s\n",a);
	/*
	Dado que dstsize es 5 y destination ya tiene una longitud de 3,
	tenemos space_left = 5 - 3 - 1 = 1, lo que nos deja un espacio adicional
	para un solo carácter en destination.
	La función ft_strlcat concatenará source al final de destination,
	pero solo hasta que space_left se agote o hasta que se alcance el 
	carácter nulo de source. Entonces, 
	olo un carácter de source será agregado a destination.
	Después de la concatenación, se añade el carácter nulo de terminación 
	a destination. La función devuelve la longitud total de la cadena 
	resultante, que será 3 + 1 = 4.
	*/
	return (0);
}
