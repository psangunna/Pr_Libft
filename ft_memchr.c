#include <unistd.h>
#include <stdio.h>
#include <string.h>
/*
function scans the initial n bytes of the memory area pointed to by s 
for the first instance of c. Both c and the bytes of the memory area pointed
to by s are interpreted as unsigned char.
*/
void	*ft_memchr(void *s, int c, unsigned int n)
{
	unsigned char	*p;
	unsigned int	i;
	void			*result;

	p = s;
	i = 0;
	while (i < n)
	{
		if (p[i] == (unsigned char)c)
		{
			result = p + i;
			return (result);
		}
		i++;
	}
	return (0);
}

int	main(void)
{
    char			*str = "Hello, world!";
    int				byte;
    unsigned int	length;
	char 			*result;

    byte = 'l';
    length = 4;
    result = ft_memchr(str, byte, length);
	//result = memchr(str, byte, length);
    printf("%s", result);
    return (0);
}