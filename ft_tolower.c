
int	ft_tolower(int c)
{
	int	val;

	val = 0;
	if (c >= 'A' && c <= 'Z')
	{
		val = c + 32;
		return (val);
	}
	return (c);
}
