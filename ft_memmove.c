/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psanguna <psanguna@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 14:30:26 by psanguna          #+#    #+#             */
/*   Updated: 2024/04/04 14:32:50 by psanguna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

/*
 *It copies 'n' characters from 'src' to 'dest', but for overlapping memory
 *blocks. It is a safer approach tha memcpy.
 */
void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*d;
	unsigned char	*s;

	i = 0;
	d = (unsigned char *)dest;
	s = (unsigned char *)src;
	if (d < s || d >= (s + n))
	{
		while (i < n)
		{
			*d++ = *s++;
			i++;
		}
	}
	else
	{
		d += n;
		s += n;
		while (n--)
		{
			*(d--) = *(s--);
		}
	}
	return (dest);
}
