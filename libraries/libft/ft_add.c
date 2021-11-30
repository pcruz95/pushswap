#include "libft.h"

int	ft_add(int args, ...)
{
	va_list	ap;
	int		i;
	int		sum;

	va_start(ap, args);
	i = 0;
	sum = 0;
	while (i < args)
	{
		sum += va_arg(ap, int);
		i++;
	}
	va_end(ap);
	return (sum);
}
