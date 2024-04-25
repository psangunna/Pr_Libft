/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psanguna <psanguna@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 13:11:28 by psanguna          #+#    #+#             */
/*   Updated: 2024/04/09 10:50:33 by psanguna         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include <unistd.h>
#include <stdlib.h>
#include <ctype.h>

int	ft_isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
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

static void	check_isalpha(int start, int end)
{
	while (start <= end)
	{
		ft_print_result(ft_isalpha(start));
		start++;
	}
}

int	main(int argc, const char *argv[])
{
	int	arg;

	if (argc == 1)
		return (0);
	else if ((arg = atoi(argv[1])) == 1)
		check_isalpha(0, 47);
	else if (arg == 2)
		check_isalpha('0', '9');
	else if (arg == 3)
		check_isalpha(58, 64);
	else if (arg == 4)
		check_isalpha('A', 'Z');
	else if (arg == 5)
		check_isalpha(91, 96);
	else if (arg == 6)
		check_isalpha('a', 'z');
	else if (arg == 7)
		check_isalpha(123, 127);
	return (0);
}