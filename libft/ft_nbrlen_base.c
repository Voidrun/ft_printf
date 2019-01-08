#include "libft.h"

int	ft_nbrlen_base(long long int nbr, char *base)
{
	int len;
	int	base_len;

	len = 0;
	if (nbr == 0)
		return (1);
	if (nbr < 0)
		len++;
	if (base)
	{
		base_len = ft_strlen(base);
		while (nbr != 0)
		{
			nbr = nbr / base_len;
			len++;
		}
	}
	return (len);
}