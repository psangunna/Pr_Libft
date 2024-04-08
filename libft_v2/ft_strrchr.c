/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psanguna <psanguna@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 14:46:02 by psanguna          #+#    #+#             */
/*   Updated: 2024/04/04 14:46:11 by psanguna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	const char	*last_value;

	last_value = NULL;
	while (*str)
	{
		if (*str == c)
		{
			last_value = str;
		}
		str++;
	}
	if (*str == c)
	{
		return ((char *)str);
	}
	return ((char *)last_value);
}
