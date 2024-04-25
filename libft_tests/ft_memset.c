/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psanguna <psanguna@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 14:19:54 by psanguna          #+#    #+#             */
/*   Updated: 2024/04/09 11:44:08 by psanguna         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include <stdlib.h>
#include <unistd.h>
#include <string.h>
/*
 *It fills the first argument with the value of second argument.
 *The value is copied as many time as n indicates
 */
void	*ft_memset(void *ptr, int c, size_t n)
{
	unsigned char	*p;
	size_t			i;

	p = (unsigned char	*)ptr;
	i = 0;
	while (i < n)
	{
		p[i] = (unsigned char)c;
		i++;
	}
	return (ptr);
}

static void	check_memset(void *mem, int c, int n, int mem_size)
{
	if (mem != ft_memset(mem, c, n))
		write(1, "mem's adress was not returned\n", 30);
	write(1, mem, mem_size);
	free(mem);
}

int	main(int argc, const char *argv[])
{
	void	*mem;
	int		arg;
	int		mem_size;

	mem_size = 15;
	if (!(mem = malloc(sizeof(*mem) * mem_size)) || argc == 1)
		return (0);
	memset(mem, 'j', mem_size);
	if ((arg = atoi(argv[1])) == 1)
		check_memset(mem, 'c', 5, mem_size);
	else if (arg == 2)
		check_memset(mem, 'c', 14, mem_size);
	else if (arg == 3)
		check_memset(mem, '\n', 6, mem_size);
	else if (arg == 4)
		check_memset(mem, '\0', 1, mem_size);
	return (0);
}