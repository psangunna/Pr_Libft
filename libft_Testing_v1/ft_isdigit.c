/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psanguna <psanguna@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 13:12:34 by psanguna          #+#    #+#             */
/*   Updated: 2024/04/09 11:10:23 by psanguna         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include <stdlib.h>
#include <unistd.h>
#include <ctype.h>

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
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

static void	check_isdigit(int start, int end)
{
	while (start <= end)
	{
		ft_print_result(ft_isdigit(start));
		start++;
	}
}

int	main(int argc, const char *argv[])
{
	int	arg;

	if (argc == 1)
		return (0);
	else if ((arg = atoi(argv[1])) == 1)
		check_isdigit(0, 49);
	else if (arg == 2)
		check_isdigit('0', '9');
	else if (arg == 3)
		check_isdigit(58, 64);
	else if (arg == 4)
		check_isdigit('A', 'Z');
	else if (arg == 5)
		check_isdigit(91, 96);
	else if (arg == 6)
		check_isdigit('a', 'z');
	else if (arg == 7)
		check_isdigit(123, 127);
	return (0);
}