#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int	ft_atoi(const char *str)
{
	int	sig;
	int	i;
	int	r;

	i = 0;
	sig = 1;
	r = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
	{
		i++;
	}
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sig *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		r = r * 10 + (str[i++] - '0');
	}
	return (sig * r);
}

int	main(void)
{
	char	*digit;
	int		resultado;

	digit = "\n\t-1234yt";
	resultado = ft_atoi(digit);
	//resultado = ft_atoi(digit);
	printf("%i", resultado);
	return (0);
}