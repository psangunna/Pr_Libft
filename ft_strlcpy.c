#include <unistd.h>
#include <stdio.h>

/*
This function copies a source string into a destination string with a 
specified maximum size. If the source string is longer than the specified 
maximum size minus one, it is truncated to fit into the destination string, 
ensuring that the destination string is properly terminated with the null 
character '\0'.
*/
unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	len_src;

	i = 0;
	while (i < size - 1 && src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	len_src = 0;
	while (src[len_src] != '\0')
	{
		len_src++;
	}
	return (len_src);
}

/*int	main(void)
{
	char	x[2];
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
}*/