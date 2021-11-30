#include "../includes/push_swap.h"

static int	is_repeated(t_dlist *lst, int number)
{
	t_dlist	*aux;

	if (lst == NULL)
		return (0);
	aux = lst;
	while (aux != NULL)
	{
		if ((int)aux->content == number)
			return (1);
		aux = aux->next;
	}
	return (0);
}

void	init_stack_a(int argc, char **argv, t_dlist	**stack_a)
{
	int	number;
	int	i;

	i = 0;
	number = (int)ft_atoi(argv[i]);
	*stack_a = ft_dlstnew(number);
	while (i < (argc - 1))
	{
		i++;
		number = (int)ft_atoi(argv[i]);
		if (is_repeated(*stack_a, number))
			return_error();
		else
			ft_dlstadd_back(stack_a, ft_dlstnew(number));
	}
}
