int			ft_strchri(const char *s, const char c)
{
	int		i;

	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return (i);
		i++;
	}
	if (s[i] == '\0' && c == '\0')
		return (i);
	else
		return (-1);
}
