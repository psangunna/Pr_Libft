
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
