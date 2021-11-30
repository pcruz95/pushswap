#include "libft.h"

void	ft_dlstdelone(t_dlist *lst, void (*del)(int))
{
	if (lst == NULL)
		return ;
	del(lst->content);
	free(lst);
}
