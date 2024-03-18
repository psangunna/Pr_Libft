/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psanguna <psanguna@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 13:22:06 by psanguna          #+#    #+#             */
/*   Updated: 2024/03/18 13:23:44 by psanguna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

/*
Check if the character is a printable ASCII character 
(ASCII codes 32 to 126 inclusive)
If it's within this range, return 1 (true), otherwise return 0 (false)
*/
int	ft_isprint(int c)
{
	if ((c >= 32 && c <= 126))
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
	//input = '\t'
	result = ft_isalnum(input);
	output = result + '0';
	write(1, &output, 1);
	
	return (0);
}*/
