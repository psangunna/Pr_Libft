/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psanguna <psanguna@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 20:43:40 by psanguna          #+#    #+#             */
/*   Updated: 2024/03/16 20:36:16 by psanguna         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include <stdio.h>
#include <string.h>*/

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	while (n > 0 && (*s1 || *s2))
	{
		if (*s1 != *s2)
		{
			return (*s1 - *s2);
		}
		s1++;
		s2++;
		n--;
	}
	return (0);
}
/*int	main()
{
	int		resultado;
	int		n = 4;
	char	a[] = "r";
	char	b[] = "";
	resultado = strncmp(a,b, n);
	printf("resultado: %i\n",resultado);
	resultado = ft_strncmp(a, b, n);
	printf("resultado: %i\n",resultado);

	return (0);
}*/