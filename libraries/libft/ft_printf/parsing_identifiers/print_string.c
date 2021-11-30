#include "../../libft.h"

static void	print_s(t_flags *flag, char **string)
{
	int		length;
	char	c;

	c = ' ';
	if (flag->zero_padding && !(flag->left_align))
		c = '0';
	length = ft_strlen(*string);
	if ((flag->left_align) && (flag->precision != 0))
		ft_putstr(*string);
	while (flag->min_width > length)
	{
		ft_putchar(c);
		flag->length++;
		flag->min_width--;
	}
	if (!(flag->left_align) && (flag->precision != 0))
		ft_putstr(*string);
	flag->length += length;
}

int	print_string(t_flags *flag, va_list args)
{
	char	*string;

	if (flag->precision > -1)
		string = ft_substr(va_arg(args, char *), 0, flag->precision);
	else
		string = ft_strdup(va_arg(args, char *));
	if (string == NULL)
	{
		free(string);
		if (flag->precision < 0)
			flag->precision = 6;
		string = ft_substr("(null)", 0, flag->precision);
		if (string == NULL)
			return (ERROR);
	}
	print_s(flag, &string);
	free(string);
	return (1);
}
