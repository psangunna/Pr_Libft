/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psanguna <psanguna@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 14:47:30 by psanguna          #+#    #+#             */
/*   Updated: 2024/04/09 17:58:50 by psanguna         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>

/*
*It finds the first ocurrence of c in the initial n bytes of the
* object pointed to by 'ptr'.
*/
void	*ft_memchr(const void *ptr, int c, size_t n)
{
	const unsigned char	*p;
	size_t				i;

	p = (const unsigned char *)ptr;
	i = 0;
	while (i < n)
	{
		if (p[i] == (unsigned char)c)
		{
			return ((void *)(p + i));
		}
		i++;
	}
	return (0);
}

static void	ft_print_result(const char *s)
{
	int		len;

	len = 0;
	while (s[len])
		len++;
	write(1, s, len);
}

static void	check_memchr(void *s, char c, int n)
{
	const char *str;

	str = ft_memchr(s, c, n);
	if (!str)
		ft_print_result("NULL");
	else
		ft_print_result(str);
}

int	main(int argc, const char *argv[])
{
	int			arg;

	if (argc == 1)
		return (0);
	else if ((arg = atoi(argv[1])) == 1)
		check_memchr("bonjour", 'b', 4);
	else if (arg == 2)
		check_memchr("bonjour", 'o', 7);
	else if (arg == 3)
		check_memchr("bonjourno", 'n', 2);
	else if (arg == 4)
		check_memchr("bonjour", 'j', 6);
	else if (arg == 5)
		check_memchr("bonjour", 's', 7);
	else if (arg == 6)
	{
		int tab[7] = {-49, 49, 1, -1, 0, -2, 2};

		printf("%s", (char *)ft_memchr(tab, -1, 7));
	}
	return (0);
}