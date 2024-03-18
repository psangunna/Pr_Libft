/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psanguna <psanguna@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 13:19:12 by psanguna          #+#    #+#             */
/*   Updated: 2024/03/18 13:21:41 by psanguna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include <ctype.h>

/*
Check if the character is within the ASCII range (0 to 127)
If it's within this range, return 1 (true), otherwise return 0 (false)
*/
int	ft_isascii(int c)
{
	if ((c >= 0 && c <= 127))
	{
		return (1);
	}
	else
	{
		return (0);
	}
}

/*int	main(void)
{
	char	input;
	int		result;
	char	output;

	input = 'A';
	//input = '€'
	result = ft_isascii(input);
	output = result + '0';
	write(1, &output, 1);
	write(1, "\n", 1);
	result = isascii(input);
	output = result + '0';
	write(1, &output, 1);
	write(1, "\n", 1);
	return (0);
}*/
