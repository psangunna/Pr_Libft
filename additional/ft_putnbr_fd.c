#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

/*
function is used to send an integer to a specified file descriptor (fd) 
using the write function.
*/
static void	ft_putchar(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
	{
		ft_putchar('-', fd);
		ft_putnbr_fd(-(n / 10), fd);
		ft_putnbr_fd(-(n % 10), fd);
	}
	else if (n < 0)
	{
		ft_putchar('-', fd);
		ft_putnbr_fd(-n, fd);
	}
	else if (n >= 10)
	{
		ft_putnbr_fd(n / 10, fd);
		ft_putnbr_fd(n % 10, fd);
	}
	else
	{
		ft_putchar(n + '0', fd);
	}
}

int	main(void)
{
	int	fd;
	int number;
	
	fd = open("output.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd == -1)
	{
		write(1, "Error al abrir el archivo\n", 27);
		return (1);
	}
	
	// Número a escribir
	number = -2147483648;
	
	// Llamar a ft_putnbr_fd para escribir el número en el archivo
	ft_putnbr_fd(number, fd);
	
	// Cerrar el archivo
	close(fd);
	
	printf("Número '%d' escrito en el archivo 'output.txt'\n", number);
	
	return (0);
}
