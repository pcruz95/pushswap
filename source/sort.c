#include "../includes/push_swap.h"

void	debug(t_dlist *stack_a, t_dlist *stack_b)
{
	ft_putendl("stack_a");
	ft_dlstiter(stack_a, &ft_putnbr);
	ft_putendl("stack_b");
	ft_dlstiter(stack_b, &ft_putnbr);
}

int	is_sorted(t_dlist *stack)
{
	if (stack)
	{
		while (stack->next != NULL)
		{
			if (stack->content > stack->next->content)
				return (0);
			stack = stack->next;
		}
	}
	return (1);
}

int	is_full(t_dlist *stack, int total_numbers)
{
	int	numbers_in_stack;

	numbers_in_stack = 0;
	while (stack->next != NULL)
	{
		numbers_in_stack++;
		stack = stack->next;
	}
	numbers_in_stack++;
	if (numbers_in_stack == total_numbers)
		return (1);
	return (0);
}

void	lets_sort(t_stack *stack, t_aux *aux)
{
	if (is_sorted(stack->a) && is_full(stack->a, aux->total_num))
		return ;
	if (ft_dlstsize(stack->a) <= 5)
		small_sort(stack, aux, ft_dlstsize(stack->a));
	else
	{
		send_half_to_b(stack, aux);
		return_half_to_a(stack, aux, aux->b.higher_index);
	}
	lets_sort(stack, aux);
}
