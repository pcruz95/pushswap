#include "libft.h"

void	ft_putnbr_unsigned(unsigned int nb)
{
	if (nb / 10 < 1)
	{
		ft_putchar(nb + '0');
	}
	else
	{
		ft_putnbr_unsigned(nb / 10);
		ft_putnbr_unsigned(nb % 10);
	}
}
