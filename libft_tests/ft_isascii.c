/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psanguna <psanguna@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 13:19:12 by psanguna          #+#    #+#             */
/*   Updated: 2024/04/09 11:04:51 by psanguna         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include <stdlib.h>
#include <unistd.h>
#include <ctype.h>

int	ft_isascii(int c)
{
	if ((c >= 0 && c <= 127))
	{
		return (1);
	}
	return (0);
}

static void		ft_print_result(int n)
{
	if (n)
		write(1, "1", 1);
	else
		write(1, "0", 1);
}

static void		check_isascii(int start, int end)
{
	while (start <= end)
	{
		ft_print_result(ft_isascii(start));
		start++;
	}
}

int				main(int argc, const char *argv[])
{
	int		arg;

	if (argc == 1)
		return (0);
	else if ((arg = atoi(argv[1])) == 1)
		check_isascii(0, 47);
	else if (arg == 2)
		check_isascii('0', '9');
	else if (arg == 3)
		check_isascii(58, 64);
	else if (arg == 4)
		check_isascii('A', 'Z');
	else if (arg == 5)
		check_isascii(91, 96);
	else if (arg == 6)
		check_isascii('a', 'z');
	else if (arg == 7)
		check_isascii(123, 127);
	else if (arg == 8)
		check_isascii(128, 138);
	return (0);
}