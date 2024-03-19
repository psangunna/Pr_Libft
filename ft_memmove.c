/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psanguna <psanguna@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 16:08:36 by psanguna          #+#    #+#             */
/*   Updated: 2024/03/19 15:42:57 by psanguna         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include <unistd.h>
#include <string.h>
#include <stddef.h>

/*
It copies n bytes from location pointed by src to the memory block pointed dest.
It handles overlapping memory blocks correctly, meaning it ensures that 
the copying is done safely even if the source and destination memory regions 
overlap
*/
void	ft_memmove(void *dest, const void *src, size_t n)
{
	char	*d;
	size_t	i;
	char	*s;

	d = (char *)dest;
	s = (char *)src;
	if (s < d && s + n > d)
	{
		s += n;
		d += n;
		while (n)
		{
			*--d = *--s;
			n--;
		}
	}
	else
	{
		while (n)
		{
			*d++ = *s++;
			n--;
		}
	}
}

int	main(void)
{
	char	dest[20] = "Hello, world";
	const char	src[20] = "Goodbye";
	//char	str[] = "memmove can be very useful...";

	ft_memmove(dest+5, dest+7, 5);
	write(1,dest,sizeof(dest));
	write(1, "\n", 1);
	//memmove(dest+5, dest+7, 5);
	//write(1, dest, sizeof(dest));
	return (0);
}
