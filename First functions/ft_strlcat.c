#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	len_dest;
	size_t	i;
	size_t	len_total;

	if (size <= ft_strlen(dest))
		return (size + ft_strlen(src));
	len_dest = ft_strlen(dest);
	len_total = len_dest + ft_strlen(src);
	i = 0;
	while (src[i] != '\0' && len_dest + 1 < size)
	{
		dest[len_dest] = src[i];
		len_dest++;
		i++;
	}
	dest[len_dest] = '\0';
	return (len_total);
}
