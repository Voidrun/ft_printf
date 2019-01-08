long long int 		get_nbr_by_bytes(long long int nbr, int bytes)
{
	long long int	res;
	int				i;

	i = 0;
	res = 0;
	if (nbr < 0)
		nbr = -nbr;
	while (i < bytes)
	{
		if (nbr & (1LL << i))
			res |= (1LL << i);
		i++;
	}
	return (res);
}