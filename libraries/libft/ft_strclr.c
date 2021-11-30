#include "libft.h"

void	ft_strclr(char *s)
{
	size_t	length;
	size_t	i;

	if (!s)
		return ;
	length = ft_strlen(s);
	i = 0;
	while (i < length)
	{
		s[i] = '\0';
		i++;
	}
}
