#include <stdlib.h>
#include <stdio.h>
/*
function is used to convert an integer (of type int) into a string 
(array of characters) representation. It stands for "integer to ASCII". 
This function takes an integer as input and returns a dynamically allocated 
string that represents that integer
*/
// Función para contar el número de dígitos en un entero
static int	ft_count_digits(int n)
{
	int	num_digits;

	if (n == 0)
	{
		num_digits = 1;
	}
	else
	{
		num_digits = 0;
	}
	while (n != 0)
	{
		num_digits++;
		n /= 10;
	}
	return (num_digits);
}

static void	ft_append_digits(char *str, int n, int num_digits)
{
	int	sign;
	int	i;
	int	j;

	sign = 1;
	i = 0;
	if (n < 0)
	{
		sign = -1;
		str[i++] = '-';
		num_digits++;
	}
	str[num_digits] = '\0';
	j = num_digits - 1;
	while (j >= i)
	{
		str[j] = '0' + (sign * (n % 10));
		n /= 10;
		j--;
	}
}

char	*ft_itoa(int n)
{
	int		num_digits;
	char	*str;

	num_digits = ft_count_digits(n);
	str = (char *)malloc((num_digits + 1) * sizeof(char));
	if (str == '\0')
		return (0);
	ft_append_digits(str, n, num_digits);
	return (str);
}

int	main(void)
{
	int num = -1093;
	char *str = ft_itoa(num);
	if (str)
	{
		printf("Integer: %d, String: %s\n", num, str);
		free(str);
	}
	else
	{
		printf("Memory allocation failed.\n");
	}
	return (0);
}