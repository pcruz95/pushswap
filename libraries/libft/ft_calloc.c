#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t	*pointer;
	size_t	total_size;

	total_size = nmemb * size;
	if ((total_size) > INT_MAX)
	{
		return (NULL);
	}
	pointer = malloc(total_size);
	if (!(pointer))
	{
		return (NULL);
	}
	ft_memset(pointer, 0, total_size);
	return ((void *)pointer);
}
