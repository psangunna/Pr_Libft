/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psanguna <psanguna@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 14:44:22 by psanguna          #+#    #+#             */
/*   Updated: 2024/04/09 17:29:44 by psanguna         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include <stdlib.h>
#include <unistd.h>
#include <string.h>
/*
function searches for the first occurrence of the character c in the string s.
It returns a pointer to the first occurrence of the character if found, or 
a pointer to the null terminator if the character is '\0' (the null terminator).
If the character is not found, it returns NULL
*/
char	*ft_strchr(const char *str, int c)
{
	while (*str != '\0' && *str != (char)c)
	{
		str++;
	}
	if (*str == (char)c)
	{
		return ((char *)str);
	}
	return (0);
}

static void		ft_print_result(char const *s)
{
	int		len;

	len = 0;
	while (s[len])
		len++;
	write(1, s, len);
}

static void	check_strchr(char *s, int c, int offset)
{
	char		*str;

	if (!(str = ft_strchr(s, c)))
		ft_print_result("NULL");
	else
	{
		ft_print_result(str);
		/*if (str != (s + offset))
			ft_print_result("\nReturn value is false");*/
	}
}

int	main(int argc, const char *argv[])
{
	char		str2[] = "bonjour";
	int			arg;

	if (argc == 1)
		return (0);
	else if ((arg = atoi(argv[1])) == 1)
		check_strchr(str2, 'b', 0);
	else if (arg == 2)
		check_strchr(str2, 'o', 1);
	else if (arg == 3)
		check_strchr(str2, 'j', 3);
	else if (arg == 4)
		check_strchr(str2, 's', 0);
	else if (arg == 5)
		check_strchr("teste", 357, 7);
	else if (arg == 6)
	{
		char	str3[] = "";

		check_strchr(str3, '\0', 0);
	}
	return (0);
}
