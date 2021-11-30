#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	t_list	*aux;
	int		size;

	aux = lst;
	size = 0;
	while (aux != NULL)
	{
		size++;
		aux = aux->next;
	}
	return (size);
}
