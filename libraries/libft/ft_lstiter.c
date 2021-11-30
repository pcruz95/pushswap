#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(const char *))
{
	t_list	*aux;

	if (lst == NULL)
		return ;
	aux = lst;
	while (aux != NULL)
	{
		f(aux->content);
		aux = aux->next;
	}
}
