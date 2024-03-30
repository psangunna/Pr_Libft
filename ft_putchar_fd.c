#include "libft.h"

/*
function sends a single character to a specified file descriptor 
using the write function.
*/
void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
