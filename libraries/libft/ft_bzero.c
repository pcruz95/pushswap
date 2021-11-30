#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	char	*s_cast;

	s_cast = (char *)s;
	while (n > 0)
	{
		*s_cast = '\0';
		s_cast++;
		n--;
	}
}
