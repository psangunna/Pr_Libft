/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psanguna <psanguna@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 13:50:42 by psanguna          #+#    #+#             */
/*   Updated: 2024/03/19 16:21:12 by psanguna         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/
#include "libft.h"

void	*ft_memset(void *ptr, int c, size_t n)
{
	unsigned char	*p;
	size_t			i;

	p = ptr;
	i = 0;
	while (i < n)
	{
		p[i] = (unsigned char)c;
		i++;
	}
	return (ptr);
}
