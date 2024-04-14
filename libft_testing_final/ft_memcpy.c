/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psanguna <psanguna@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 16:02:17 by psanguna          #+#    #+#             */
/*   Updated: 2024/04/14 18:08:42 by psanguna         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>

/*
 *It copies 'n' bytes from the location pointed to by 'src' 
 *directly to the memory block pointed to by 'dest'.
 */
void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;

	if (!src && !dest)
	{
		return (0);
	}
	i = 0;
	while (i < n)
	{
		((unsigned char *)dest)[i] = ((unsigned char *)src)[i];
		i++;
	}
	return (dest);
}

static void		check_memcpy(void *dest, void *src, int n)
{
	if (dest != ft_memcpy(dest, src, n))
		write(1, "dest's adress was not returned\n", 31);
	write(1, dest, 30);
	write(1, "\n", 1);
	free(dest);
}

int	main(int argc, const char *argv[])
{
	void	*mem;
	int		arg;

	if (!(mem = malloc(sizeof(*mem) * 30)) || argc == 1)
		return (0);
	memset(mem, 'j', 30);
	printf("destination string : %s\n", (unsigned char *)mem);
	if ((arg = atoi(argv[1])) == 1)
		check_memcpy(mem, "zyxwvutsrqponmlkjihgfedcba", 14);
	else if (arg == 2)
		check_memcpy(mem, "zyxwvutst", 0);
	else if (arg == 3)
		check_memcpy(mem, "zy\0xw\0vu\0\0tsr", 11);
	else if (arg == 4)
	{
		printf("source string = NULL\n");
		check_memcpy(mem, NULL, 11);
	}
	else if (arg == 5)
	{
		printf("destination string = NULL\n");
		check_memcpy((void *)0, "zyxwvutsrqponmlkjihgfedcba", 11);
	}
	else if (arg == 6)
	{
		printf("source string = NULL and size 0\n");
		check_memcpy(mem, NULL, 0);
	}

	return (0);
}