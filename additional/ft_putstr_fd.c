#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

/*
function sends a string to a specified file descriptor using the write function.
*/
void	ft_putstr_fd(char *s, int fd)
{
	while (*s != '\0')
	{
		write(fd, s, 1);
		s++;
	}
	/*
	int i;

	if (!s)
		return ;
	i = 0;
	while (s[i])
	{
		ft_putchar_fd(s[i], fd);
		i++;
	}
	*/
}

int main(void)
{
	int     fd;
	char    *str;

	// Abrir un archivo para escribir
	fd = open("output.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd == -1)
	{
		write(1, "Error al abrir el archivo\n", 27);
		return (1);
	}
	
	// Cadena a escribir
	str = "Hello, World!";

	// Llamar a ft_putstr_fd para escribir la cadena en el archivo
	ft_putstr_fd(str, fd);
	
	// Cerrar el archivo
	close(fd);
	
	printf("Cadena '%s' escrita en el archivo 'output.txt'\n", str);
	
	return (0);
}