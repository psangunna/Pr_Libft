#include <unistd.h>
#include <stdio.h>
#include <ctype.h>
/*
function converts an uppercase character 
to its corresponding lowercase character
otherwise, it returns the input character unchanged.
*/
int	ft_tolower(int c)
{
	int	val;

	val = 0;
	if (c >= 'A' && c <= 'Z')
	{
		val = c + (32);
		return (val);
	}
	else
	{
		return (c);
	}
}

int	main(void)
{
	int	lowercase_char;
	int	uppercase_char;

	lowercase_char = 'S';
	uppercase_char = ft_tolower(lowercase_char);
	write(1, &uppercase_char, 1);
	write(1, "\n", 1);
	printf("integer: %d, char: %c",uppercase_char, uppercase_char);
    write(1, "\n", 1);
    uppercase_char = tolower(lowercase_char);
	write(1, &uppercase_char, 1);
	write(1, "\n", 1);
	printf("integer: %d, char: %c",uppercase_char, uppercase_char);
	return (0);
}
