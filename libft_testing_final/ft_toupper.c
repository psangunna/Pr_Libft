/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psanguna <psanguna@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 14:40:05 by psanguna          #+#    #+#             */
/*   Updated: 2024/04/09 17:17:09 by psanguna         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include <stdlib.h>
#include <unistd.h>
#include <ctype.h>
/*
 *It converst a lowercase character to its corresponding uppercase character,
 *otherwise, it returns the character unchanged.
 */
int	ft_toupper(int c)
{
	int	val;

	val = 0;
	if (c >= 'a' && c <= 'z')
	{
		val = c - 32;
		return (val);
	}
	return (c);
}

static void	check_toupper(int start, int end)
{
	int		c;

	while (start <= end)
	{
		c = ft_toupper(start);
		write(1, &c, 1);
		start++;
	}
}

int	main(int argc, const char *argv[])
{
	int		arg;

	if (argc == 1)
		return (0);
	else if ((arg = atoi(argv[1])) == 1)
		check_toupper(0, 47);
	else if (arg == 2)
		check_toupper('0', '9');
	else if (arg == 3)
		check_toupper(58, 64);
	else if (arg == 4)
		check_toupper('A', 'Z');
	else if (arg == 5)
		check_toupper(91, 96);
	else if (arg == 6)
		check_toupper('a', 'z');
	else if (arg == 7)
		check_toupper(123, 127);
	return (0);
}