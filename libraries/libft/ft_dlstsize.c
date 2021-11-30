#include "libft.h"

int	ft_dlstsize(t_dlist *lst)
{
	t_dlist	*aux;
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
