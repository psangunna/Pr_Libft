/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psanguna <psanguna@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 16:06:29 by psanguna          #+#    #+#             */
/*   Updated: 2024/04/12 13:22:15 by psanguna         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include <stdlib.h>
#include <unistd.h>

void	ft_putchar_fd(char c, int fd);
/*
function sends a string to a specified file descriptor using the write function.
*/
void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	if (!s)
		return ;
	i = 0;
	while (s[i])
	{
		ft_putchar_fd(s[i], fd);
		i++;
	}
}

int		main(int argc, const char *argv[])
{
	int		arg;

	if (argc == 1)
		return (0);
	else if ((arg = atoi(argv[1])) == 1)
		ft_putstr_fd("Two people shorten the road", 2);
	else if (arg == 2)
		ft_putstr_fd("  Two\npeople\rshorten\tthe road  ", 1);
	else if (arg == 3)
		ft_putstr_fd("", 2);
	else if (arg == 4)
		ft_putstr_fd("Two people shor\0ten the road", 1);
	return (0);
}

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}