/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psanguna <psanguna@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 15:50:06 by psanguna          #+#    #+#             */
/*   Updated: 2024/04/04 15:50:44 by psanguna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strnstr(const char *str, const char *to_find, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (to_find[0] == '\0')
		return ((char *)str);
	while (str[i] != '\0')
	{
		j = 0;
		while (str[i + j] == to_find[j] && (i + j) < len)
		{
			if (str[i + j] == '\0' && to_find[j] == '\0')
				return ((char *)str + i);
			j++;
		}
		if (to_find[j] == '\0')
			return ((char *)str + i);
		i++;
	}
	return (0);
}
