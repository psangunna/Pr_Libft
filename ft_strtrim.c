/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psanguna <psanguna@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 15:59:33 by psanguna          #+#    #+#             */
/*   Updated: 2024/04/04 15:59:49 by psanguna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

/*
function removes leading and trailing characters from s1 that match any 
character in the set string. It returns a newly allocated string 
containing the trimmed characters.
If memory allocation fails at any point, it returns NULL.
*/
char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	len;
	size_t	start;
	size_t	end;

	if (!s1 || !set)
		return (0);
	len = 0;
	start = 0;
	end = ft_strlen(s1);
	while (s1[start] != '\0' && ft_strchr(set, s1[start]))
		start++;
	while (end > start && ft_strchr(set, s1[end - 1]))
		end--;
	len = end - start;
	return (ft_substr(s1, start, len));
}
