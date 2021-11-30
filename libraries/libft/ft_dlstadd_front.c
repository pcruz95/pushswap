#include "libft.h"

void	ft_dlstadd_front(t_dlist **lst, t_dlist *new)
{
	t_dlist	*temp;

	temp = *lst;
	*lst = new;
	new->next = temp;
	temp->previous = new;
}
