

int		ft_strlen_w(int *str)
{
	int	i;

	i = 0;
	if (str)
	{
		while (*str)
		{
			i++;
			str++;
		}
	}
	return (i);
}
