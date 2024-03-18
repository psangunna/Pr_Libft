/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psanguna <psanguna@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 19:15:30 by psanguna          #+#    #+#             */
/*   Updated: 2024/03/13 19:20:26 by psanguna         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include <unistd.h>
/*
function is used to set a block of memory to zero. 
*/
void	ft_bzero(void *ptr, int num)
{
	unsigned char	*p;
	int				i;

	p = ptr;
	i = 0;
	while (i < num)
	{
		p[i] = 0;
		i++;
	}
	//return (ptr);
}

int	main(void)
{
	char	buffer[20];

	ft_bzero(buffer, sizeof(buffer));
	write(1, buffer, sizeof(buffer));
	return (0);
}
