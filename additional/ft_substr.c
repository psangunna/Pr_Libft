#include <stdlib.h>
#include <stdio.h>
/*Function takes a string s, a starting index start(It usually starts counting from 0, not from 1), 
and a maximum length len as input parameters. 
It then creates and returns a substring of s based on these parameters.*/
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	s_len;
	size_t	sub_len;
	char	*substr;
	size_t	i;

	if (s == '\0')
		return (0);

	s_len = 0;
	while (s[s_len] != '\0')
	{
		s_len++;
	}
	if (start >= s_len)
		return (0);

	sub_len = len;
	if (start + len > s_len)
		sub_len = s_len - start;

	// Reservar memoria para la substring
	substr = (char *)malloc((sub_len + 1) * sizeof(char));
	if (substr == '\0')
		return (0);

	// Copiar la substring desde s
	i = 0;
	while (i < sub_len)
	{
		substr[i] = s[start + i];
		i++;
	}
	substr[sub_len] = '\0'; // Agregar el terminador nulo al final

	return (substr);
}

int	main(void)
{
    // Cadena de ejemplo para probar ft_substr
    char str[] = "Ejemplo de cadena para probar la funcion ft_substr";

    // Índice de inicio y longitud máxima para la substring
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