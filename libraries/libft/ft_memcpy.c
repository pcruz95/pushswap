#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char	*dest_cast;
	char	*src_cast;

	if (!(dest) && !(src) && (n > 0))
		return (NULL);
	dest_cast = (char *)dest;
	src_cast = (char *)src;
	while (n > 0)
	{
		*dest_cast = *src_cast;
		dest_cast++;
		src_cast++;
		n--;
	}
	return (dest);
}
