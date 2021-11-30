#include "libft.h"

int	ft_toupper(int c)
{
	if (ft_isalpha(c) == 2)
	{
		return (c - 32);
	}
	else
	{
		return (c);
	}
}
