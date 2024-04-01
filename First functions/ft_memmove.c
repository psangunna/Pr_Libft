/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psanguna <psanguna@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 16:08:36 by psanguna          #+#    #+#             */
/*   Updated: 2024/03/26 18:06:45 by psanguna         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/
#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t					i;
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
