#include "libft.h"

void	ft_dlstiter(t_dlist *lst, void (*f)(int))
{
	t_dlist	*aux;

	if (lst == NULL)
		return ;
	aux = lst;
	while (aux != NULL)
	{
		f(aux->content);
		ft_putchar('\n');
		aux = aux->next;
	}
}

void	ft_dlstiter_reverse(t_dlist *lst, void (*f)(int))
{
	t_dlist	*aux;

	if (lst == NULL)
		return ;
	aux = lst;
	while (aux->next != NULL)
		aux = aux->next;
	while (aux != NULL)
	{
		f(aux->content);
		ft_putchar('\n');
		aux = aux->previous;
	}
}
