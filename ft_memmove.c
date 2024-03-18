/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psanguna <psanguna@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 18:07:52 by psanguna          #+#    #+#             */
/*   Updated: 2024/03/16 18:10:41 by psanguna         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include <unistd.h>
#include <string.h>

/*
function is used to copy a block of memory from one location to another. 
It handles overlapping memory blocks correctly, meaning it ensures that 
the copying is done safely even if the source and destination memory regions 
overlap
 */
void	ft_memmove(void *dest, void *src, int num)
{
	char	*d;
	int		i;
	char	*s;

	d = (char *)dest;
	s = (char *)src;
	if (s < d && s + num > d)
	{
		s += num;
		d += num;
		while (num)
		{
			*--d = *--s;
			num--;
		}
	}
	else
	{
		while (num)
		{
			*d++ = *s++;
			num--;
		}
	}
}

int	main(void)
{
	char	dest[20] = "Hello, world";
	char	src[20] = "Goodbye";

	ft_memmove(dest, src, 6);
	//memmove(dest, src, 6);
	write(1, dest, sizeof(dest));
	return (0);
}
