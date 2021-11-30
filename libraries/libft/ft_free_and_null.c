#include "libft.h"

void	ft_free_and_null(void **pointer)
{
	if (*pointer)
		free(*pointer);
	*pointer = NULL;
}
