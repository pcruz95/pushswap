#include "libft.h"

t_dlist	*ft_dlstmap(t_dlist *lst, int(*f)(int), void (*del)(int))
{
	t_dlist	*new_list;
	t_dlist	*temp;

	new_list = NULL;
	while (lst != NULL)
	{
		temp = ft_dlstnew(f(lst->content));
		if (temp == NULL)
		{
			if (new_list != NULL)
			{
				ft_dlstclear(&new_list);
			}
			return (NULL);
		}
		ft_dlstadd_back(&new_list, temp);
		lst = lst->next;
	}
	return (new_list);
}
