#include "libft.h"

/*
function takes a string s and applies a given function f to each character 
of the string.The function f is passed two arguments: the index of the character 
within the string and the character itself. It then generates a new string 
containing the result of applying the function f to each character successively.
*/
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*result;

	if (!s || !f)
		return (0);
	result = ft_strdup(s);
	if (!result)
		return (0);
	i = 0;
	while (result[i])
	{
		result[i] = f(i, result[i]);
		i++;
	}
	return (result);
}
