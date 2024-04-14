/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psanguna <psanguna@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 14:42:06 by psanguna          #+#    #+#             */
/*   Updated: 2024/04/09 17:20:37 by psanguna         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include <stdlib.h>
#include <unistd.h>
#include <ctype.h>

/*
 *It converst an uppercase character to its corresponding lowercase character,
 *otherwise, it returns the input character unchanged.
 */
int	ft_tolower(int c)
{
	int	val;

	val = 0;
	if (c >= 'A' && c <= 'Z')
	{
		val = c + 32;
		return (val);
	}
	return (c);
}

static void	check_tolower(int start, int end)
{
	int		c;

	while (start <= end)
	{
		c = ft_tolower(start);
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
		check_tolower(0, 47);
	else if (arg == 2)
		check_tolower('0', '9');
	else if (arg == 3)
		check_tolower(58, 64);
	else if (arg == 4)
		check_tolower('A', 'Z');
	else if (arg == 5)
		check_tolower(91, 96);
	else if (arg == 6)
		check_tolower('a', 'z');
	else if (arg == 7)
		check_tolower(123, 127);
	return (0);
}