#include <stdio.h>
#include <string.h>
#include <stddef.h>
/*
It compares at most the first n bytes of str1 and str2.
This function return values that are as follows −
- if Return value < 0 then it indicates str1 is less than str2.
- if Return value > 0 then it indicates str2 is less than str1.
- if Return value = 0 then it indicates str1 is equal to str2.
*/
int	ft_strncmp(const char *str1, const char *str2, size_t n)
{
	char	*str_aux1;
	char	*str_aux2;

	str_aux1 = (char *)str1;
	str_aux2 = (char *)str2;
	while (n > 0 && (*str_aux1 || *str_aux2))
	{
		if (*str_aux1 != *str_aux2)
		{
			return (*str_aux1 - *str_aux2);
		}
		str_aux1++;
		str_aux2++;
		n--;
	}
	return (0);
}

int	main()
{
	int		resultado;
	int		n = 13;
	char	a[] = "Hello,\0 worlr!";
	char	b[] = "Hello,\0 world!";
	resultado = strncmp(a,b, n);
	printf("resultado: %i\n",resultado);
	resultado = ft_strncmp(a, b, n);
	printf("resultado: %i\n",resultado);

	return (0);
}