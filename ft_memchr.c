#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stddef.h>
/*
function scans the initial n bytes of the memory area pointed to by ptr
for the first instance of c. Both c and the bytes of the memory area pointed
to by s are interpreted as unsigned char.
*/
void	*ft_memchr(const void *ptr, int c, size_t n)
{
	unsigned char	*p;
	size_t			i;
	void			*result;

	p = (unsigned char *)ptr;
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
	//The byte 'l' is searched for in the first 4 bytes of the string
    result = ft_memchr(str, byte, length);
	//result = memchr(str, byte, length);
    printf("%s", result);
    return (0);
}