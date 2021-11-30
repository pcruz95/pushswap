#include "../libft.h"

static int	find_length(char *str, char *pointer)
{
	int	length;

	length = 0;
	while (str[length] != pointer[0])
		length++;
	return (length);
}

static int	ft_printf_recursive(char *str, va_list args, size_t length)
{
	char	*percent_pointer;
	char	*str_aux;

	percent_pointer = ft_strchr(str, '%');
	if (!(percent_pointer))
	{
		length += ft_strlen(str);
		ft_putstr(str);
		return (length);
	}
	str_aux = ft_substr(str, 0, find_length(str, percent_pointer));
	if (!(str_aux))
		return (ERROR);
	ft_putstr(str_aux);
	length += ft_strlen(str_aux);
	free(str_aux);
	length = flags_parser(&percent_pointer, args, length);
	if (length == ERROR)
		return (ERROR);
	return (ft_printf_recursive(percent_pointer, args, length));
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		return_num;

	va_start(args, str);
	return_num = ft_printf_recursive((char *)str, args, 0);
	va_end(args);
	return (return_num);
}
