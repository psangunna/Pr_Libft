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

char	*ft_strrchr(const char *str, int c)
{
	const char	*last_value;

	last_value = 0;
	while (*str != '\0')
	{
		if (*str == c)
		{
			last_value = str;
		}
		str++;
	}
	return ((char *)last_value);
}
