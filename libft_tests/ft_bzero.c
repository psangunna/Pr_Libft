/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psanguna <psanguna@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 15:44:16 by psanguna          #+#    #+#             */
/*   Updated: 2024/04/09 11:58:17 by psanguna         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>

void	*ft_memset(void *ptr, int c, size_t n);

/*
 *It fills the first n bytes of the object pointed with zero (null)
 */
void	ft_bzero(void *ptr, size_t n)
{
	ft_memset(ptr, '\0', n);
}


static void	check_bzero(void *mem, int c, int len, int n_bzero)
{
	memset(mem, c, len);
	printf("string origin:%s\n", (unsigned char *)mem);
	ft_bzero(mem, n_bzero);
	printf("string final:%s\n", (unsigned char *)mem);
}

int	main(int argc, const char *argv[])
{
	void	*mem;
	int		len;
	int		arg;

	len = 5;
	if (argc == 1 || !(mem = malloc(sizeof(*mem) * len)))
		return (0);
	if ((arg = atoi(argv[1])) == 1)
		check_bzero(mem, 'e', len, 5);
	else if (arg == 2)
		check_bzero(mem, 'e', len, 0);
	free(mem);
	return (0);
}

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