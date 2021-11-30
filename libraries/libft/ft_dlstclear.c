#include "libft.h"

void	ft_dlstclear(t_dlist **lst)
{
	t_dlist	*aux;
	t_dlist	*temp;

	aux = *lst;
	if (aux == NULL)
		return ;
	while (aux != NULL)
	{
		temp = aux->next;
		free(aux);
		aux = temp;
	}
	*lst = NULL;
}
