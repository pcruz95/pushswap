#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*string;
	size_t	length;
	size_t	i;

	if (!s)
		return (NULL);
	length = ft_strlen(s);
	string = (char *)malloc(length + 1);
	if (string == NULL)
		return (NULL);
	i = 0;
	while (i < length)
	{
		string[i] = s[i];
		i++;
	}
	string[length] = '\0';
	return (string);
}
