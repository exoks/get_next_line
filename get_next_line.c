/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oezzaou <oezzaou@student.1337.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 00:59:04 by oezzaou           #+#    #+#             */
/*   Updated: 2022/10/17 02:07:09 by oezzaou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <string.h>
#include <stdio.h>

char	*read_from_buff(int fd)
{
	char	*buff;
	int	n_byte;

	buff = malloc(BUFFER_SIZE + 1);
	if (!buff)
		return (0);
	n_byte = read(fd, buff, BUFFER_SIZE);
	if (!n_byte)
		return (0);
	buff[n_byte] = 0;
	return (buff);
}

t_buff	*ft_lstlast(t_buff *lst)
{
	while (lst)
	{
		if (lst->next == 0)
			return (lst);
		lst = lst->next;
	}
	return (lst);
}

t_buff	*ft_lstnew(char *buff)
{
	t_buff	*new;

	new = (t_buff *) malloc(sizeof(t_buff));
	if (!new)
		return (0);
	new->buff = buff;
	new->next = 0;
	return (new);
}

t_buff	*ft_lstcreat(int fd, int *counter, char *buff)
{
	t_buff	*lst;
	t_buff	*tmp;

	lst = ft_lstnew(buff);
	while (buff && !strchr(buff, '\n'))
	{
		buff = read_from_buff(fd);
		tmp = ft_lstlast(lst);
		if (tmp)
			tmp->next = ft_lstnew(buff);
		else
			tmp = ft_lstnew(buff);
		(*counter)++;
	}
	return (lst);
}

void	ft_strcat(char *dst, char *src)
{
	int	i;

	i = -1;
	while (dst[++i])
		;
	while (*src)
		dst[i++] = *(src++);
	dst[i] = 0;
}

int	ft_check_line(char *buff)
{
	while (*buff)
	{
		if (*buff == '\n' && *(buff + 1))
			return (EOL_PLUS);
		if (*buff == '\n' && *(buff + 1) == 0)
			return (EOL);
		buff++;
	}
	return (EOF);
}
char	*get_next_line(int fd)
{
	static char	cursor[BUFFER_SIZE];
	t_buff		*list;
	int		counter;
	char		*buff;

	buff = read_from_buff(fd);
	counter = 0;
	list = ft_lstcreat(fd, &counter, buff);
//	printf("counter : %d\n", counter);
//	while (list)
//	{
//		printf("buff : %s\n", list->buff);
//		list = list->next;
//	}
	buff = (char *) calloc((counter * BUFFER_SIZE) + 1, 1);
	if (!buff)
		return (0);
	while (list)
	{
		if (list->buff)
			ft_strcat(buff, list->buff);
//		printf("buff of each node : %s\n", list->buff);
		list = list->next;
	}
	// ft_lstclear : 
//	printf("full buff : %s\n", buff);
	if (ft_check_line(buff) == EOL_PLUS)
	{
		counter = 0;
		while (*buff && *buff != '\n')
			buff++;
		while (*buff)
			cursor[counter++] = *(buff++);
		cursor[counter] = 0;
		printf("cursor : %s\n", cursor);
		return (buff);
	}
	if (ft_check_line(buff) == EOF || ft_check_line(buff) == EOL)
		return (buff);
	return (0);
}

int	main(void)
{
	int	fd;

	fd = open("test.txt", O_CREAT | O_RDWR, 0777);
	if (fd < 0)
		return (0);
 	printf("read : %s\n", get_next_line(fd));
	return (0);
}
