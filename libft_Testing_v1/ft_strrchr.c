/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psanguna <psanguna@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 14:46:02 by psanguna          #+#    #+#             */
/*   Updated: 2024/04/12 18:58:57 by psanguna         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include <stdlib.h>
#include <unistd.h>
#include <string.h>

char	*ft_strrchr(const char *str, int c)
{
	const char	*last_value;

	last_value = NULL;
	while (*str)
	{
		if (*str == (char)c)
		{
			last_value = str;
		}
		str++;
	}
	//El último carácter en la cadena coincida con c, last_value contendrá la dirección del carácter nulo '\0', que no es lo que queremos. 
	//En lugar de eso, se devolverá un puntero al último carácter coincidente antes del carácter nulo.
	if (*str == (char)c)
	{
		return ((char *)str);
	}
	return ((char *)last_value);
}

static void	ft_print_result(char const *s)
{
	int		len;

	len = 0;
	while (s[len])
		len++;
	write(1, s, len);
}

static void	check_strrchr(char *s, int c, int offset)
{
	char		*str;
	
	if (!(str = ft_strrchr(s, c)))
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
		check_strrchr(str2, 'b', 0);
	else if (arg == 2)
		check_strrchr(str2, 'o', 4);
	else if (arg == 3)
	{
		char	str3[]= "bonjourno";

		check_strrchr(str3, 'o', 8);
	}
	else if (arg == 4)
		check_strrchr(str2, 'j', 3);
	else if (arg == 5)
		check_strrchr(str2, 's', 0);
	else if (arg == 6)
		check_strrchr(str2, '\0', 7);
	else if (arg == 7)
	{
		char	str3[] = "";

		check_strrchr(str3, '\0', 0);
	}
	else if (arg == 8)
		check_strrchr("test", 357, 0);
	return (0);
}