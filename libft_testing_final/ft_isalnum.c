/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psanguna <psanguna@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 13:17:11 by psanguna          #+#    #+#             */
/*   Updated: 2024/04/09 11:10:20 by psanguna         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include <stdlib.h>
#include <unistd.h>
#include <ctype.h>

int	ft_isalnum(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')
		|| (c >= '0' && c <= '9'))
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

static void	check_isalnum(int start, int end)
{
	while (start <= end)
	{
		ft_print_result(ft_isalnum(start));
		start++;
	}
}

int	main(int argc, const char *argv[])
{
	int	arg;

	if (argc == 1)
		return (0);
	else if ((arg = atoi(argv[1])) == 1)
		check_isalnum(0, 47);
	else if (arg == 2)
		check_isalnum('0', '9');
	else if (arg == 3)
		check_isalnum(58, 64);
	else if (arg == 4)
		check_isalnum('A', 'Z');
	else if (arg == 5)
		check_isalnum(91, 96);
	else if (arg == 6)
		check_isalnum('a', 'z');
	else if (arg == 7)
		check_isalnum(123, 127);
	return (0);
}