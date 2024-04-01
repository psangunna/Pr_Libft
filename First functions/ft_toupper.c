
int	ft_toupper(int c)
{
	int	val;

	val = 0;
	if (c >= 'a' && c <= 'z')
	{
		val = c - 32;
		return (val);
	}
	return (c);
}
