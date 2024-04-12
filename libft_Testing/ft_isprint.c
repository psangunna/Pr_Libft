/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psanguna <psanguna@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 13:22:06 by psanguna          #+#    #+#             */
/*   Updated: 2024/04/09 11:13:53 by psanguna         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include <stdlib.h>
#include <unistd.h>
#include <ctype.h>

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
	return (0);
}

static void	ft_print_result(int n)
{
	if (n)
		write(1, "1", 1);
	else
		write(1, "0", 1);
}

static void	check_isprint(int start, int end)
{
	while (start <= end)
	{
		ft_print_result(ft_isprint(start));
		start++;
	}
}

int	main(int argc, const char *argv[])
{
	int	arg;

	if (argc == 1)
		return (0);
	else if ((arg = atoi(argv[1])) == 1)
		check_isprint(0, 47);
	else if (arg == 2)
		check_isprint('0', '9');
	else if (arg == 3)
		check_isprint(58, 64);
	else if (arg == 4)
		check_isprint('A', 'Z');
	else if (arg == 5)
		check_isprint(91, 96);
	else if (arg == 6)
		check_isprint('a', 'z');
	else if (arg == 7)
		check_isprint(123, 127);
	return (0);
}