#include <stdlib.h>
#include <stdio.h>
/*
function takes a string s and applies a given function f to each character 
of the string.The function f is passed two arguments: the index of the character 
within the string and the character itself. It then generates a new string 
containing the result of applying the function f to each character successively.
*/
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	len;
	unsigned int	i;
	char			*result;

	if (s == '\0' || f == '\0')
		return (0);
	len = 0;
	while (s[len] != '\0')
		len++;
	result = (char *)malloc((len + 1) * sizeof(char));
	if (result == '\0')
		return (0);
	i = 0;
	while (s[i] != '\0')
	{
		result[i] = f(i, s[i]);
		i++;
	}
	result[i] = '\0';
	return (result);
}

// Función de ejemplo para aplicar a cada carácter
char	add_one(unsigned int index, char c)
{
	return (c + 1); // Incrementa el valor del carácter en 1
}

/*int	main(void)
{
	char *input_string = "hello, world!";
	char *result_string = ft_strmapi(input_string, &add_one);
	
	if (result_string != '\0')
	{
		printf("Cadena resultante: %s\n", result_string);
		// Liberar la memoria asignada a la cadena resultante
		free(result_string);
	} else {
		printf("Error: No se pudo asignar memoria para la cadena resultante.\n");
	}
	return (0);
}*/