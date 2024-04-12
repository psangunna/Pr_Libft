/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psanguna <psanguna@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 20:03:42 by psanguna          #+#    #+#             */
/*   Updated: 2024/04/09 13:06:51 by psanguna         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>

/*
 *It copies 'n' characters from 'src' to 'dest', but for overlapping memory
 *blocks. It is a safer approach tha memcpy.
 */
void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*s;
	unsigned char	*d;
	size_t	i;

	s = (unsigned char *)src;
	d = (unsigned char *)dst;
	if (!src || !dst)
		return (0);
	i = 0;
	if (d > s)
	{
		while (len-- > 0)
			d[len] = s[len];
	}
	else
	{
		while (i < len)
		{
			d[i] = s[i];
			i++;
		}
	}
	return (dst);
}

static void		check_memmove(void *dest, void *src, int n)
{
	printf("destination string: %s - source string: %s\n", (unsigned char *)dest, (unsigned char *)src);
	if (dest != ft_memmove(dest, src, n))
		write(1, "dest's adress was not returned\n", 31);
	write(1, dest, 33);
}

int	main(int argc, const char *argv[])
{
	char	src[] = "Keep moving and dreaming everyday";
	char	*dest;
	int		arg;

	dest = src + 1;
	if (argc == 1)
		return (0);
	else if ((arg = atoi(argv[1])) == 1)
		check_memmove(dest, "creatinging", 5);
	else if (arg == 2)
		check_memmove(dest, "cre\0ati\0\0ng\0ing", 10);
	else if (arg == 3)
		check_memmove(dest, src, 8);
	else if (arg == 4)
		check_memmove(src, dest, 8);
	else if (arg == 5)
	{
		printf("number to copy = 0\n");
		check_memmove(src, dest, 0);
	}
	else if (arg == 6)
	{
		printf("source string = NULL\n");
		check_memmove(src, NULL, 8);
	}
	else if (arg == 7)
	{
		printf("destination string = NULL\n");
		check_memmove(NULL, dest, 8);
	}
	return (0);
}