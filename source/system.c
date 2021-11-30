#include "../includes/push_swap.h"

void	return_error(void)
{
	ft_putstr_fd("Error\n", 2);
	exit(1);
}

void	clear(t_stack *stack, t_aux *aux)
{
	ft_dlstclear(&stack->a);
	ft_dlstclear(&stack->b);
	ft_lstclear(&stack->instr, &free);
	free(aux->ordered_array);
}
