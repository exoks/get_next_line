#include "get_next_line_bonus.h"

t_buff	*ft_lstcreat(int fd, int *size);
char	*get_line_from_rest(char *rest);
char	*get_line_from_lst(t_buff *lst, char *rest, int size);
int     ft_is_nl_exist(char *buff);

char    *get_next_line(fd)
{
	static char	rest[OPEN_MAX][BUFFER_SIZE];
	char		*line;
	t_buff		*lst;
	int		size;

	if (fd < 0 || BUFFER_SIZE < 0)
		return (0);
	lst = 0;
	size = 0;
	if (ft_is_nl_exist((char *) rest[fd]))
		return (get_line_from_rest(rest[fd]));
	lst = ft_lstcreat(fd, &size);
	if (!lst && !*rest[fd])
		return (0);
	line = get_line_from_lst(lst, rest[fd], ++size);
	ft_lstclear(&lst);
	return (line);
}

t_buff	*ft_lstcreat(int fd, int *size)
{
	t_buff	*lst;
	int	n_read;
	char	*buff;

	lst = 0;
	n_read = 1;
	buff = 0;
	while (n_read && !ft_is_nl_exist(buff))
	{
		buff = (char *) ft_calloc(BUFFER_SIZE + 1, 1);
		if (!buff)
			return (0);
		n_read = read(fd, buff, BUFFER_SIZE);
		if (n_read == -1 || n_read == 0)
		{
			free(buff);
			if (n_read == -1)
				ft_lstclear(&lst);
			else
				return (lst);
			return (0);
		}
		if (lst)
			(ft_lstlast(lst))->next = ft_lstnew(buff);
		else
			lst = ft_lstnew(buff);
		(*size)++;
	}
	return (lst);
}

char	*get_line_from_rest(char *rest)
{
	char	*line;
	int	l;
	int	i;

	l = -1;
	while (rest[++l] && rest[l] != '\n')
		;
	line = ft_calloc(l + 2, 1);
	if (!line)
		return (0);
	l = -1;
	while (rest[++l] && rest[l] != '\n')
		line[l] = rest[l];
	line[l] = '\n';
	i = 0;
	while (rest[++l])
		rest[i++] = rest[l];
	rest[i] = 0;
//	printf("rest_from_rest:=====> %s\n", rest);
	return (line);
}

char	*get_line_from_lst(t_buff *lst, char *rest, int size)
{
	char	*line;
	int	i;

	line = ft_calloc((size * BUFFER_SIZE) + 1, 1);
	if (!line)
		return (0);
	if (*rest)
		ft_strcat(line, rest);
	*rest = 0;
	while (lst)
	{
		if (lst->buff)
			ft_strcat(line, lst->buff);
		lst = lst->next;
	}
	i = -1;
	while (line[++i] && line[i] != '\n')
		;
	while (line[++i])
	{
		*(rest++) = line[i];
		line[i] = 0;
	}
	*rest = 0;
	return (line);
}

int	ft_is_nl_exist(char *buff)
{
	if (!buff)
		return (0);
	while (*buff && *buff != '\n')
		buff++;
	if (*buff == '\n')
		return (1);
	return (0);
}
/*
char	*get_next_line(fd)
{
	static char 	rest[BUFFER_SIZE + 1];
	char		*line;
	t_buff		*lst;
	int		size;

	if (fd < 0 || BUFFER_SIZE < 0)
		return (0);
	lst = 0;
	counter = size;
	if (ft_is_nl_exist((char *)rest))
		return (get_line_from_rest(rest));
	lst = ft_lstcreat(fd, &size);
	if (!lst && !*rest)
		return (0);
	line = get_line_from_lst(lst, rest, ++counter);
	ft_lstclear(&lst);
	return (line);
}
*/
/*
int	main(void)
{
	char	*s;
	int	fd;

	fd = open("test.txt", O_CREAT | O_RDWR, 0777);
	if (fd < 0)
		return (0);
	s = get_next_line(fd);
	while (s)
	{
		printf("line :=> %s\n", s);
		free(s);
		s = get_next_line(fd);
	}
	while (1);
//	printf("line :=> %s", s);
//	printf("line :=> %s", get_next_line(fd));
//	printf("line :=> %s", get_next_line(fd));
	return (0);
}
*/
