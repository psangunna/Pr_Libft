#include "libft.h"

char	*ft_strdup(const char *str)
{
	size_t			len;
	char			*new_str;

	if (*str == '\0')
		return (0);
	len = ft_strlen(str) + 1;
	new_str = (char *)malloc(len * sizeof(char));
	if (!new_str)
		return (0);
	ft_memcpy(new_str, str, len);
	return (new_str);
}
