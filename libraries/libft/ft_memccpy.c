#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	char	*dest_cast;
	char	*src_cast;
	char	c_cast;

	dest_cast = (char *)dest;
	src_cast = (char *)src;
	c_cast = (char)c;
	while ((*src_cast != c_cast) && (n > 0))
	{
		*dest_cast = *src_cast;
		dest_cast++;
		src_cast++;
		n--;
	}
	if (*src_cast == c_cast)
	{
		*dest_cast = *src_cast;
		dest_cast++;
		return ((void *)dest_cast);
	}
	return (NULL);
}
