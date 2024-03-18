/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psanguna <psanguna@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 19:29:59 by psanguna          #+#    #+#             */
/*   Updated: 2024/03/18 11:05:04 by psanguna         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include <unistd.h>
#include <string.h>
/*
function is used to copy a block of memory from one location to another.
It stands for "memory copy"
*/
void	ft_memcpy(void *dest, void *src, int num)
{
	unsigned char	*d;
	int				i;
	unsigned char	*s;

	d = dest;
	i = 0;
	s = src;
	while (i <num)
	{
		d[i] = s[i];
		i++;
	}
}

int	main(void)
{
	char	dest[20] = "Hey";
	char	src[20] = "Hello, world";

	ft_memcpy(dest, src, sizeof(src));
	write(1, dest, sizeof(dest));
	//memcpy(dest, src, sizeof(src));
	//write(1, dest, sizeof(dest));
	return (0);
}
