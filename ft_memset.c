/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psanguna <psanguna@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 19:33:23 by psanguna          #+#    #+#             */
/*   Updated: 2024/03/16 18:10:10 by psanguna         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include <unistd.h>
#include <string.h>

/*
function is used to fill a block (size) of memory with a particular value.
*/
void	*ft_memset(void *ptr, int value, int num)
{
	unsigned char	*p;
	int				i;

	p = ptr;
	i = 0;
	while (i < num)
	{
		p[i] = (unsigned char)value;
		i++;
	}
}

int	main(void)
{
	char	buffer[20];

	ft_memset(buffer, 0xABABABAB, sizeof(buffer));
	write(1, buffer, sizeof(buffer));
	//memset(buffer, 0xABABABAB, sizeof(buffer));
	//write(1, buffer, sizeof(buffer));
	return (0);
}
