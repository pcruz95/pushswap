#include "libft.h"

int	ft_countdigit(unsigned int number)
{
	size_t	digits;

	if (number == 0)
	{
		return (1);
	}
	digits = 0;
	while (number >= 1)
	{
		number /= 10;
		digits++;
	}
	return (digits);
}
