/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psanguna <psanguna@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 09:57:33 by pamela            #+#    #+#             */
/*   Updated: 2024/04/15 12:44:44 by pamela           ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include <stdlib.h>
#include <unistd.h>

// Función auxiliar para obtener el tamaño necesario para la representación de un número entero como cadena
static int	get_number_size(int n)
{
    int size;

    size = 0;
    // Si el número es menor o igual a cero, se necesita espacio adicional para el signo negativo
    if (n <= 0)
        size++;
    // Calcular el tamaño de la cadena contando los dígitos del número
    while (n != 0)
    {
        n = n / 10;
        size++;
    }
    return (size);
}

// Función auxiliar para llenar la cadena con los dígitos del número
static void	fill_result_string(int size, int offset, int n, char *result)
{
    // Rellenar la cadena desde la posición 'size' hasta 'offset' con los dígitos del número
    while (size > offset)
    {
        result[size - 1] = n % 10 + '0'; // Convertir el dígito numérico en su representación de carácter
        n = n / 10;
        size--;
    }
}

// Función principal para convertir un entero en una cadena
char	*ft_itoa(int n)
{
    int res;
    int size;
    char *result;

    offset = 0;
    // Calcular el tamaño necesario para la cadena
    size = get_number_size(n);
    // Asignar memoria para la cadena resultante, más un carácter adicional para el nulo terminador
    result = (char *)malloc((size + 1) * sizeof(char));
    if (!result)
        return (0); // Devolver NULL si falla la asignación de memoria
    // Manejar el caso especial si 'n' es el valor mínimo representable
    if (n == -2147483648)
    {
        result[0] = '-';
        result[1] = '2';
        n = 147483648;
        offset = 2;
    }
    // Si 'n' es negativo, establecer el primer carácter de 'str' como '-'
    if (n < 0)
    {
        result[0] = '-';
        offset = 1;
        n = -n;
    }
    // Rellenar 'str' con los dígitos de 'n'
    fill_result_string(size, offset, n, result);
    // Agregar el nulo terminador al final de 'str'
    result[size] = '\0';
    return (result); // Devolver un puntero a la cadena resultante
}


static void	ft_print_result(char *s)
{
	int		len;

	if (!s)
		write(1, "NULL", 4);
	else
	{
		len = 0;
		while (s[len])
			len++;
		write(1, s, len);
		free(s);
	}
}

int	main(int argc, const char *argv[])
{
	int		arg;

	if (argc == 1)
		return (0);
	else if ((arg = atoi(argv[1])) == 1)
		ft_print_result(ft_itoa(0));
	else if (arg == 2)
		ft_print_result(ft_itoa(9));
	else if (arg == 3)
		ft_print_result(ft_itoa(-9));
	else if (arg == 4)
		ft_print_result(ft_itoa(10));
	else if (arg == 5)
		ft_print_result(ft_itoa(-10));
	else if (arg == 6)
		ft_print_result(ft_itoa(8124));
	else if (arg == 7)
		ft_print_result(ft_itoa(-9874));
	else if (arg == 8)
		ft_print_result(ft_itoa(543000));
	else if (arg == 9)
		ft_print_result(ft_itoa(-2147483648LL));
	else if (arg == 10)
		ft_print_result(ft_itoa(2147483647));
	return (0);
}
