
char	*ft_strchr(const char *str, int c)
{
	while (*str != '\0' && *str != c)
	{
		str++;
	}
	if (*str == c)
	{
		return ((char *)str);
	}
	return (0);
}
