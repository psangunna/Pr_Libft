/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psanguna <psanguna@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 19:26:19 by psanguna          #+#    #+#             */
/*   Updated: 2024/03/13 19:26:21 by psanguna         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include <unistd.h>

/*
Check if the character is within the range of uppercase or lowercase letters. 
If it's within any of these ranges, it returns 1 (true), 
otherwise, it returns 0 (false).
*/
int	ft_isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
	{
		return (1);
	}
	else
	{
		return (0);
	}
}

int	main(void)
{
	char	input;
	int		result;
	char	output;

	input = 'a';
	result = ft_isalpha(input);
	output = result + '0';
	write(1, &output, 1);
	return (0);
}
