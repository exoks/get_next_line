/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oezzaou <oezzaou@student.1337.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 01:00:59 by oezzaou           #+#    #+#             */
/*   Updated: 2022/10/17 02:57:05 by oezzaou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# define EOL_PLUS 1
# define EOL 2
# define EOF 0
typedef struct s_buff
{
	char		*buff;
	struct s_buff 	*next;
}	t_buff;

char	*get_next_line(int fd);
#endif
