#include "get_next_line.h"

t_buff	*ft_lstnew(char *buff)
{
	t_buff	*node;

	node = (t_buff *) malloc(sizeof(t_buff));
	if (!node)
		return (0);
	node->buff = buff;
	node->next = 0;
	return (node);
}

t_buff	*ft_lstlast(t_buff *lst)
{
	while (lst)
	{
		if (!lst->next)
			return (lst);
		lst = lst->next;
	}
	return (lst);
}

void	ft_lstclear(t_buff **head)
{
	t_buff	*tmp;

	while (*head)
	{
		tmp = (*head)->next;
		free((*head)->buff);
		free(*head);
		*head = tmp;
	}
	head = 0;
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*pt;
	size_t	i;

	pt = (void*) malloc(count * size);
	if (!pt)
		return (0);
	i = 0;
	while (i < (count * size))
		*((char *)pt + i++) = 0;
	return (pt);
}
/*
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
*/

char	*ft_strcat(char *dst, char *src)
{
	int	i;

	i = -1;
	while(dst[++i])
		;
	while (*src)
		dst[i++] = *(src++);
	dst[i] = 0;
	return (dst);
}
/*
#include <stdio.h>
int	main(int ac, char **av)
{
	char	*pt = ft_calloc(11, 1);
	for(int i = 0; i < 11; i++)
		printf("%d ", pt[0]);
	printf("\n");
	t_buff	*node = ft_lstnew("hello world");
	printf("buff => %s\n", node->buff);
	printf("%d\n", ft_is_nl_exist(""));
	return (0);
}
*/
