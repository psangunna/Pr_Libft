/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psanguna <psanguna@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 13:50:42 by psanguna          #+#    #+#             */
/*   Updated: 2024/03/18 15:59:14 by psanguna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include <string.h>
#include <stddef.h>

/*
function fills ptr with value of c. 
The value of c is copied as times as n indicates.
*/
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
}

int	main(void)
{
	char	buffer[20];

	ft_memset(buffer, 'F', sizeof(buffer));
	write(1, buffer, sizeof(buffer));
	write(1, "\n", 1);
	memset(buffer, 'D', sizeof(buffer));
	write(1, buffer, sizeof(buffer));
	return (0);
}
