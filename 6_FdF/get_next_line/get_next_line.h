/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtimsina <rtimsina@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 16:59:05 by rtimsina          #+#    #+#             */
/*   Updated: 2023/05/20 17:54:00 by rtimsina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <libft.h>

char	*gnl_ft_strjoin(char *s1, char *s2);
char	*gnl_ft_strchr(char *s, int c);
int		gnl_ft_strlen(char *str);
char	*get_next_line(int fd);
char	*ft_readed_line(char *start);
char	*ft_move_start(char	*start);
void	*ft_free(char *line, char *tmp);

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4
# endif

#endif
