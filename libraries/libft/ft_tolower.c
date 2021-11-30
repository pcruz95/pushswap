#include "libft.h"

int	ft_tolower(int c)
{
	if (ft_isalpha(c) == 1)
	{
		return (c + 32);
	}
	else
	{
		return (c);
	}
}
