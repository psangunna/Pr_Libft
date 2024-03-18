/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psanguna <psanguna@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 16:02:17 by psanguna          #+#    #+#             */
/*   Updated: 2024/03/18 16:07:44 by psanguna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stddef.h>
#include <unistd.h>
#include <string.h>
/*
It copies the values of n bytes from the location pointed to by
src directly to the memory block pointed to by dest.
*/
void	ft_memcpy(void *dest, void *src, size_t n)
{
	unsigned char	*d;
	size_t			i;
	unsigned char	*s;

	d = dest;
	i = 0;
	s = src;
	while (i < n)
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
	write(1, "\n", 1);
	memcpy(dest, src, sizeof(src));
	write(1, dest, sizeof(dest));
	return (0);
}
