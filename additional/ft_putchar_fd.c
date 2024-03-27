#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
/*
function sends a single character to a specified file descriptor 
using the write function.
*/
void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

int	main(void)
{
	int		fd;
	char	character;

	fd = open("output.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd == -1)
	{
		// 1 is the file descriptor for stdout
		write(1, "Error al abrir el archivo\n", 27); 
		return (1);
	}
	character = 'A';
	ft_putchar_fd(character, fd);
	close(fd);
	printf("Caracter '%c' escrito en el archivo 'output.txt'\n", character);
	return (0);
}
