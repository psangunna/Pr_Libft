#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

/*
function is used to send a string followed by a newline character 
('\n') to a specified file descriptor (fd) using the write function.
*/
void	ft_putendl_fd(char *s, int fd)
{
	while (*s != '\0')
	{
		write(fd, s, 1);
		s++;
	}
	write(fd, "\n", 1);
}

int	main(void)
{
	int		fd;
	char	*str;

	fd = open("output.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd == -1)
	{
		write(1, "Error al abrir el archivo\n", 27);
		return 1;
	}
	// Cadena a escribir
	str = "Hello, World!";
	ft_putendl_fd(str, fd);
	
	// Cerrar el archivo
	close(fd);
	
	printf("Cadena '%s' escrita en el archivo 'output.txt' con un salto de línea\n", str);
	return (0);
}