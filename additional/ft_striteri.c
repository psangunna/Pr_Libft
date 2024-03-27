#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>

/*
function iterates over each character of the string s and applies a given 
function f to each character. The function f is passed two arguments: 
the index of the character within the string and a pointer to the character 
itself. This function f can modify the character if necessary.
*/
void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	if (s == '\0' || f == '\0')
		return ;
	i = 0;
	while (s[i] != '\0')
	{
		f(i, &s[i]);
		i++;
	}
}

// Función de ejemplo para imprimir el índice y el carácter
void	print_index_and_character(unsigned int index, char *c)
{
	printf("Caracter en el indice %u: %c\n", index, *c);
}

int	main(void)
{
	char str[] = "Hello, World!";

	// Llamar a la función ft_striteri con la función print_index_and_character
	ft_striteri(str, &print_index_and_character);
	return (0);
}