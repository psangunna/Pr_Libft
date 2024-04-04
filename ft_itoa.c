/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psanguna <psanguna@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 16:03:26 by psanguna          #+#    #+#             */
/*   Updated: 2024/04/04 16:03:49 by psanguna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

/*
It counts the number of digits of a integer.
*/
static int	count_digits(int n)
{
	int	num_digits;

	if (n == 0)
	{
		num_digits = 1;
	}
	else
	{
		num_digits = 0;
	}
	while (n != 0)
	{
		num_digits++;
		n /= 10;
	}
	return (num_digits);
}

/*
It allocates the integer in a string memory
*/
static void	append_digits(char *str, int n, int num_digits)
{
	int	i;
	int	j;

	i = 0;
	if (n < 0)
	{
		str[i++] = '-';
		num_digits++;
		n = -n;
	}
	str[num_digits] = '\0';
	j = num_digits - 1;
	while (j >= i)
	{
		str[j] = '0' + (n % 10);
		n /= 10;
		j--;
	}
}

/*
function is used to convert an integer (of type int) into a string 
(array of characters) representation. It stands for "integer to ASCII". 
This function takes an integer as input and returns a dynamically allocated 
string that represents that integer.
*/
char	*ft_itoa(int n)
{
	int		num_digits;
	char	*str;

	num_digits = count_digits(n);
	str = (char *)malloc((num_digits + 1) * sizeof(char));
	if (!str)
		return (0);
	append_digits(str, n, num_digits);
	return (str);
}
