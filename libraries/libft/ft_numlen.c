#include "libft.h"

int	ft_numlen(int number)
{
	size_t	digits;

	digits = 0;
	if (number == 0)
		return (1);
	else if (number < 0)
	{
		digits++;
		number *= -1;
	}
	while (number >= 1)
	{
		number /= 10;
		digits++;
	}
	return (digits);
}
