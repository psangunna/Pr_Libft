#include <unistd.h>
#include <stdio.h>
#include <string.h>
/*
function searches for the first occurrence of the to find substring in 
the str string, limited to len characters. It returns a pointer to the 
first occurrence of the substring if found, or NULL if the substring 
is not found within the specified length.
*/
char	*ft_strnstr(char *str, char *to_find, unsigned int len)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	if (to_find[0] == '\0')
		return (str);
	while (str[i] != '\0' && i < len)
	{
		j = 0;
		while (str[i + j] == to_find[j] && to_find[j] != '\0' && i + j < len)
		{
			if (to_find[j + 1] == '\0')
				return (&str[i]);
			j++;
		}
		i++;
	}
	return (0);
}
/*int	main(void)
{
	char	*a = "El cielo gris";
	char	*b = "lo";
	char	*r;
	unsigned int	max_length;

	max_length = 9;
	r = ft_strnstr(a, b, max_length);
	//printf("resultado:%s\n",r);
	//r = strnstr(a, b, max_length);
	printf("resultado:%s",r);
	return (0);
}*/