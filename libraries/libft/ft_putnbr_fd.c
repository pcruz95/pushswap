#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	number;

	if (n < 0)
	{
		number = n * -1;
		ft_putchar_fd('-', fd);
	}
	else
	{
		number = n;
	}
	if (number / 10 < 1)
	{
		ft_putchar_fd((number + '0'), fd);
	}
	else
	{
		ft_putnbr_fd(number / 10, fd);
		ft_putnbr_fd(number % 10, fd);
	}
}
