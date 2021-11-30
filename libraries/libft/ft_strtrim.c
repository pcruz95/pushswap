#include "libft.h"

char	*ft_strtrim(char const *s, char const *set)
{
	size_t	end;
	size_t	length;

	if (!s || !set)
		return (0);
	while ((*s) && (ft_strchr(set, *s)))
	{
		s++;
	}
	end = ft_strlen(s);
	while ((end) && (ft_strchr(set, s[end])))
	{
		end--;
	}
	length = end + 1;
	return (ft_substr(s, 0, length));
}
