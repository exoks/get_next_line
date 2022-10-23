/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oezzaou <oezzaou@student.1337.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 01:00:59 by oezzaou           #+#    #+#             */
/*   Updated: 2022/10/23 01:46:20 by oezzaou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

typedef struct s_buff
{
	char			*buff;
	struct s_buff	*next;
}t_buff;

char	*get_next_line(int fd);
void	*ft_calloc(size_t count, size_t size);
int		ft_is_nl_exist(char *buff);
t_buff	*ft_lstnew(char *buff);
t_buff	*ft_lstlast(t_buff *lst);
void	ft_lstclear(t_buff **head);
t_buff	*ft_lstcreat(int fd, int *counter);
char	*ft_strcat(char *dst, char *src);
#endif
