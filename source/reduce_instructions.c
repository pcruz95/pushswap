#include "../includes/push_swap.h"

static void	replace(t_list **instr, char *content)
{
	t_list	*new_node;
	t_list	*orphan_node;

	new_node = *instr;
	new_node->content = content;
	orphan_node = new_node->next;
	new_node->next = new_node->next->next;
	free(orphan_node);
	*instr = new_node;
}

static void	replace_instructions(t_list **instr, char *id)
{
	if ((ft_strnequ(id, "rra", 3)) || (ft_strnequ(id, "rrb", 3)))
		replace(instr, "rrr\n");
	if ((ft_strnequ(id, "ra", 2)) || (ft_strnequ(id, "rb", 2)))
		replace(instr, "rr\n");
	if ((ft_strnequ(id, "sa", 2)) || (ft_strnequ(id, "sb", 2)))
		replace(instr, "ss\n");
}

static int	next_is_a_match(char *id, char *id_next)
{
	if ((ft_strnequ(id, "rra", 3)) && (ft_strnequ(id_next, "rrb", 3)))
		return (1);
	if ((ft_strnequ(id, "ra", 2)) && (ft_strnequ(id_next, "rb", 2)))
		return (1);
	if ((ft_strnequ(id, "sa", 2)) && (ft_strnequ(id_next, "sb", 2)))
		return (1);
	if ((ft_strnequ(id, "rrb", 3)) && (ft_strnequ(id_next, "rra", 3)))
		return (1);
	if ((ft_strnequ(id, "rb", 2)) && (ft_strnequ(id_next, "ra", 2)))
		return (1);
	if ((ft_strnequ(id, "sb", 2)) && (ft_strnequ(id_next, "sa", 2)))
		return (1);
	return (0);
}

static int	is_reducible(char *id)
{
	if ((ft_strnequ(id, "pa", 2)) || (ft_strnequ(id, "pb", 2)))
		return (0);
	return (1);
}

void	reduce_instructions(t_list **instructions)
{
	t_list	*instr;

	instr = *instructions;
	while (instr)
	{
		if (is_reducible(instr->content))
			if (instr->next)
				if (next_is_a_match(instr->content, instr->next->content))
					replace_instructions(&instr, instr->content);
		instr = instr->next;
	}
}
