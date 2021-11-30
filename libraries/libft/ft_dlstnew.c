#include "libft.h"
#include "../../includes/push_swap.h"

t_dlist	*ft_dlstnew(int content)
{
	t_dlist	*pointer;

	pointer = (t_dlist *)malloc(sizeof(t_dlist));
	if (!(pointer))
		return_error();
	pointer->content = content;
	pointer->next = NULL;
	pointer->previous = NULL;
	return (pointer);
}
