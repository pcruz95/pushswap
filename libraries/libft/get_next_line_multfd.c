#include "libft.h"

static int	check_errors(int fd, char **line, t_gnl *string)
{
	*line = ft_strdup("");
	if (*line == NULL)
		return (1);
	ft_memset(string, 0, sizeof(*string));
	if ((fd < 0) || (fd > RLIMIT_NOFILE) || (BUFFER_SIZE < 1) || !(line))
		return (1);
	return (0);
}

static int	add_to_line(t_gnl *string, char **line, char **excess, int new_line)
{
	if (new_line)
		*string->break_line_ptr = '\0';
	string->read[string->read_return] = '\0';
	string->temp = ft_strjoin(*line, string->read);
	if (string->temp == NULL)
		return (ERROR);
	free(*line);
	*line = string->temp;
	if (new_line)
	{
		string->temp = ft_strdup(string->break_line_ptr + 1);
		if (string->temp == NULL)
			return (ERROR);
		free(*excess);
		*excess = string->temp;
	}
	return (READ_LINE);
}

static int	add_excess(char **line, t_gnl *string, char **excess, int new_line)
{
	if (new_line)
		*string->break_line_ptr = '\0';
	string->temp = ft_strjoin(*line, *excess);
	if (string->temp == NULL)
		return (ERROR);
	free(*line);
	*line = string->temp;
	if (new_line)
	{
		string->temp = ft_strdup(string->break_line_ptr + 1);
		if (string->temp == NULL)
			return (ERROR);
	}
	free(*excess);
	if (new_line)
		*excess = string->temp;
	else
		*excess = NULL;
	return (READ_LINE);
}

static int	free_excess(t_gnl *string, char **excess)
{
	free(*excess);
	return (string->read_return);
}

int	get_next_line_multfd(int fd, char **line)
{
	static char		*excess[RLIMIT_NOFILE];
	t_gnl			string;

	if (check_errors(fd, line, &string))
		return (-1);
	if (excess[fd] != NULL)
	{
		string.break_line_ptr = ft_strchr(excess[fd], '\n');
		if (string.break_line_ptr)
			return (add_excess(line, &string, &excess[fd], NEW_LINE));
		if ((add_excess(line, &string, &excess[fd], NO_NEW_LINE)) == ERROR)
			return (ERROR);
	}
	string.read_return = read(fd, string.read, BUFFER_SIZE);
	string.break_line_ptr = ft_strchr(string.read, '\n');
	while (((string.read_return > 0) && !(string.break_line_ptr)))
	{
		if (add_to_line(&string, line, &excess[fd], NO_NEW_LINE) == ERROR)
			return (ERROR);
		string.read_return = read(fd, string.read, BUFFER_SIZE);
		string.break_line_ptr = ft_strchr(string.read, '\n');
	}
	if (string.read_return < 1)
		return (free_excess(&string, &excess[fd]));
	return (add_to_line(&string, line, &excess[fd], NEW_LINE));
}
