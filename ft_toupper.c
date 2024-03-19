#include <unistd.h>
#include <stdio.h>
#include <ctype.h>
/*
function converts a lowercase character to its 
corresponding uppercase character,
otherwise, it returns the input character unchanged
*/
int	ft_toupper(int c)
{
	int	val;

	val = 0;
	if (c >= 'a' && c <= 'z')
	{
		val = c - (32);
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

	lowercase_char = 'r';
	uppercase_char = ft_toupper(lowercase_char);
	write(1, &uppercase_char, 1);
	write(1, "\n", 1);
	printf("integer: %d, char: %c",uppercase_char, uppercase_char);
	uppercase_char = toupper(lowercase_char);
	write(1, &uppercase_char, 1);
	write(1, "\n", 1);
	printf("integer: %d, char: %c",uppercase_char, uppercase_char);
	return (0);
}
