/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtimsina <rtimsina@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 16:59:05 by rtimsina          #+#    #+#             */
/*   Updated: 2023/01/28 12:52:01 by rtimsina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <unistd.h>
# include <stdlib.h>

char	*ft_strjoin(char *s1, char *s2);
char	*ft_strchr(char *s, int c);
int		ft_strlen(char *str);
char	*get_next_line(int fd);
char	*ft_readed_line(char *start);
char	*ft_move_start(char	*start);
char	*ft_join(char *dest, char *s1, char *s2);

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4
# endif

#endif