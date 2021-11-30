#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*s1_cast;
	unsigned char	*s2_cast;

	i = 0;
	s1_cast = (unsigned char *)s1;
	s2_cast = (unsigned char *)s2;
	while ((s1_cast[i] != '\0' || s2_cast[i] != '\0') && i < n)
	{
		if (s1_cast[i] != s2_cast[i])
		{
			return (s1_cast[i] - s2_cast[i]);
		}
		i++;
	}
	return (0);
}
