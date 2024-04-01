#include "libft.h"

/*
function is used to send a string followed by a newline character 
('\n') to a specified file descriptor (fd) using the write function.
*/
void	ft_putendl_fd(char *s, int fd)
{
	ft_putstr_fd(s, fd);
	ft_putchar_fd('\n', fd);
}
