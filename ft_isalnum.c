/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psanguna <psanguna@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 13:17:11 by psanguna          #+#    #+#             */
/*   Updated: 2024/03/18 13:18:36 by psanguna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include <ctype.h>
#include <stdio.h>
/*
Check if the character is a letter (uppercase or lowercase) or a digit
If it's a letter or a digit, return 1 (true), otherwise return 0 (false)
*/
int	ft_isalnum(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')
		|| (c >= '0' && c <= '9'))
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

	input = '-';
	result = ft_isalnum(input);
	output = result + '0';
	write(1, &output, 1);
	write(1, "\n", 1);
	result = 0;
	result = isalnum(input);
	output = result + '0';
	write(1, &output, 1);
	write(1, "\n", 1);
	return (0);
}*/
