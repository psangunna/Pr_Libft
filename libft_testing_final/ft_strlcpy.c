/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psanguna <psanguna@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 14:33:25 by psanguna          #+#    #+#             */
/*   Updated: 2024/04/14 18:03:15 by psanguna         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>

size_t	ft_strlen(const char *str);

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	len_src;
	size_t	i;

	len_src = ft_strlen(src);
	i = 0;
	if (size != 0)
	{
		while (src[i] != '\0' && i < (size - 1))
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = '\0';
	}
	return (len_src);
}

void	ft_print_result(int n)
{
	char c;

	if (n >= 10)
		ft_print_result(n / 10);
	c = n % 10 + '0';
	write (1, &c, 1);
}

static void	check_strlcpy(char *dest, char *src, int size, int dest_len)
{
	ft_print_result(ft_strlcpy(dest, src, size));
	write(1, "\n", 1);
	write(1, dest, dest_len);
	free(dest);
}

int	main(int argc, const char *argv[])
{
	char	*dest;
	int		arg;
	int		dest_len;

	dest_len = 15;
	if (!(dest = (char *)malloc(sizeof(*dest) * dest_len)) || argc == 1)
		return (0);
	memset(dest, 0, dest_len);
	memset(dest, 'r', 6);
	if ((arg = atoi(argv[1])) == 1)
		check_strlcpy(dest, "Two", 15, dest_len);
	else if (atoi(argv[1]) == 2)
		check_strlcpy(dest, "", 15, dest_len);
	else if (atoi(argv[1]) == 3)
		check_strlcpy(dest, "Two people", 3, dest_len);
	else if (atoi(argv[1]) == 4)
		check_strlcpy(dest, "Two people shorten the road", 15, dest_len);
	else if (atoi(argv[1]) == 5)
		check_strlcpy(dest, "Two people shorten the road", 0, dest_len);
	else if (arg == 6)
	{
		printf("source string = NULL\n");
		check_strlcpy(dest, NULL, 0, dest_len);
	}
	else if (arg == 7)
	{
		printf("destination string = NULL\n");
		check_strlcpy(NULL, "Two people shorten the road", 0, dest_len);
	}
	return (0);
}

size_t	ft_strlen(const char *str)
{
	size_t	counter;

	counter = 0;
	while (str[counter] != '\0')
	{
		counter++;
	}
	return (counter);
}
