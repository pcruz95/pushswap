#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*s_cast;
	unsigned char	c_cast;

	s_cast = (unsigned char *)s;
	c_cast = (unsigned char)c;
	while (n > 0)
	{
		if (*s_cast == c_cast)
		{
			return ((void *)s_cast);
		}
		s_cast++;
		n--;
	}
	return (NULL);
}
