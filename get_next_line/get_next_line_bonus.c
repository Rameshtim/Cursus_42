/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtimsina <rtimsina@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 12:33:53 by rtimsina          #+#    #+#             */
/*   Updated: 2023/01/28 12:52:14 by rtimsina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_current_line(char *working_line)
{
	char	*final_line;
	int		i;

	i = 0;
	if (!working_line || !working_line[i])
		return (NULL);
	while (working_line[i] && working_line[i] != '\n')
		i++;
	if (working_line[i] == '\n')
		i++;
	final_line = (char *)malloc((i + 1) * sizeof(char));
	if (!final_line)
		return (NULL);
	i = 0;
	while (working_line[i] && working_line[i] != '\n')
	{
		final_line[i] = working_line[i];
		i++;
	}
	if (working_line[i] == '\n')
		final_line[i++] = '\n';
	final_line[i] = '\0';
	return (final_line);
}

char	*ft_for_next_line(char *cursor_start)
{
	int		i;
	int		j;
	char	*cursor_mover;

	i = 0;
	while (cursor_start[i] && cursor_start[i] != '\n')
		i++;
	if (cursor_start[i] == '\0')
	{
		free(cursor_start);
		return (NULL);
	}
	if (cursor_start[i] == '\n')
		i++;
	cursor_mover = (char *)malloc((ft_strlen(cursor_start) - i + 1));
	if (!cursor_mover)
		return (NULL);
	j = -1;
	while (cursor_start[i + ++j])
		cursor_mover[j] = cursor_start[i + j];
	cursor_mover[j] = '\0';
	free(cursor_start);
	return (cursor_mover);
}

void	*ft_free(char *line, char *tmp)
{
	if (line)
		free(line);
	if (tmp)
		free(tmp);
	line = NULL;
	tmp = NULL;
	return (NULL);
}

char	*get_next_line(int fd)
{
	static char	*line[1024] = {NULL};
	char		*tmp;
	int			line_read;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line_read = 1;
	tmp = (char *)malloc((1 + BUFFER_SIZE) * sizeof(char));
	if (!tmp)
		return (NULL);
	while (!(ft_strchr(line[fd], '\n')) && line_read != 0)
	{
		line_read = read(fd, tmp, BUFFER_SIZE);
		if (line_read == -1)
		{
			line[fd] = ft_free(line[fd], tmp);
			return (NULL);
		}
		tmp[line_read] = '\0';
		line[fd] = ft_strjoin(line[fd], tmp);
	}
	free(tmp);
	tmp = ft_current_line(line[fd]);
	line[fd] = ft_for_next_line(line[fd]);
	return (tmp);
}
