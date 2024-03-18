/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psanguna <psanguna@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 13:12:34 by psanguna          #+#    #+#             */
/*   Updated: 2024/03/18 13:16:43 by psanguna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include <ctype.h>
/*
We check if the character is within the range of digits (0 to 9).
If it's within this range, it returns 1 (true), otherwise, it returns 0 (false).
*/
int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
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

	input = 'R';
	result = ft_isdigit(input);
	output = result + '0';
	write(1, &output, 1);
	write(1, "\n", 1);
	result = isdigit(input);
	output = result + '0';
	write(1, &output, 1);
	return (0);
}*/
