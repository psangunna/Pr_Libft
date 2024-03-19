#include <unistd.h>
#include <stdio.h>
#include <stddef.h>
#include <string.h>
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

/*
This function copies a source string into a destination string with a 
specified maximum size. If the source string is longer than the specified 
maximum size minus one, it is truncated to fit into the destination string, 
ensuring that the destination string is properly terminated with the null 
character '\0'.
Return the total length of the string they tried to create (src).
*/
size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	len_src;

	len_src = ft_strlen(src);
	if (len_src + 1 < size)
	{
		ft_memcpy(dest, src, len_src + 1);
	}
	else if (size != 0)
	{
		ft_memcpy(dest, src, size - 1);
		dest[size - 1] = '\0';
	}
	return (len_src);
}

int	main(void)
{
	char	x[3];
	char	z[] = "Buenos tardess";
	unsigned int		len;
	int		size;

	size = (sizeof(x) / sizeof(x[0]));
	printf("long de string destino: %i\n",size);
	len = ft_strlcpy(x, z, size);
	printf("resultado long de string origen: %i\n",len);
	printf("valor de destino: %s\n",x);
	size = sizeof(x) / sizeof(x[0]);
	printf("long de string destino: %i\n",size);
	return (0);
}
