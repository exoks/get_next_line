/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oezzaou <oezzaou@student.1337.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 01:00:59 by oezzaou           #+#    #+#             */
/*   Updated: 2022/10/23 13:29:17 by oezzaou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//====<[ Include guards: ]>=====================================================
#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

//====<[ Headers: ]>============================================================
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <stdlib.h>

//====<[ Struct: buff ]>========================================================
typedef struct s_buff
{
	char			*buff;
	struct s_buff	*next;
}t_buff;

//====<[ Function: prototypes ]>================================================
char	*get_next_line(int fd);
void	*ft_calloc(size_t count, size_t size);
t_buff	*ft_lstnew(char *buff);
t_buff	*ft_lstlast(t_buff *lst);
t_buff	*ft_lstclear(t_buff **head);
char	*ft_strcat(char *dst, char *src);

#endif
//==============================================================================
