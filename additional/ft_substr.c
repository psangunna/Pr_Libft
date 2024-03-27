#include <stdlib.h>
#include <stdio.h>
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

/*Function takes a string s, a starting index start(It usually starts 
counting from 0, not from 1), and a maximum length len as input parameters. 
It then creates and returns a substring of s based on these parameters.
*/
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	s_len;
	size_t	sub_len;
	char	*substr;
	size_t	i;

	if (s == '\0')
		return (0);
	s_len = ft_strlen(s);
	// Si el indice de inicio es mayor o igual 
	//que la longitud de la cadena, devolver una cadena vacia
	if (start >= s_len)
		return (0);
	//Ajustar la longitud si es mayor que la longitud restante de la cadena
	sub_len = len;
	if (start + len > s_len)
		sub_len = s_len - start;
	substr = (char *)malloc((sub_len + 1) * sizeof(char));
	if (substr == '\0')
		return (0);
	// Copiar la substring desde s
	ft_memcpy(substr, (void *)(s + start), sub_len);
	substr[sub_len] = '\0';
	return (substr);
}

int	main(void)
{
    // Cadena de ejemplo para probar ft_substr
    char str[] = "Ejemplo de cadena para probar la funcion ft_substr";

    // indice de inicio y longitud maxima para la substring
    unsigned int	start_index;
    size_t	max_length;
	char	*substring;

	start_index = 10;
	max_length = 15;
    // Llamada a ft_substr
	substring = ft_substr(str, start_index, max_length);

    if (substring == NULL) {
        printf("Error: No se pudo crear la substring.\n");
        return (1);
    }

    // Imprimir la substring resultante
    printf("Substring: %s\n", substring);

    // Liberar la memoria asignada a la substring
    free(substring);
    return (0);
}