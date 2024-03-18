/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psanguna <psanguna@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 15:44:16 by psanguna          #+#    #+#             */
/*   Updated: 2024/03/18 15:58:07 by psanguna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include <stddef.h>
#include <stdio.h>
#include <string.h>
/*
function fils the first n  bytes of the object pointed (ptr) 
with zero (null bytes). 
*/
void	ft_bzero(void *ptr, size_t n)
{
	unsigned char	*p;
	size_t			i;

	p = ptr;
	i = 0;
	while (i < n)
	{
		p[i] = 0;
		i++;
	}
}

int	main(void)
{
	char	buffer[20];

	ft_bzero(buffer, sizeof(buffer));
	write(1, "resultado:", 12);
	write(1, buffer, sizeof(buffer));
	bzero(buffer, 20);
	printf("resultado:%s", buffer);
	return (0);
}
