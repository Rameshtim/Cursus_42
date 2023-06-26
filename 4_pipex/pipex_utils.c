/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtimsina <rtimsina@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 10:50:52 by rtimsina          #+#    #+#             */
/*   Updated: 2023/03/06 11:54:00 by rtimsina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*path_giver(char **multi_path, char *cmd)
{
	int		i;
	char	*path;
	char	*joining_path;

	i = 0;
	while (multi_path[i])
	{
		if (access(cmd, F_OK) == 0)
			return (cmd);
		joining_path = ft_strjoin(multi_path[i], "/");
		path = ft_strjoin(joining_path, cmd);
		free(joining_path);
		if (access(path, F_OK) == 0)
			return (path);
		free(path);
		i++;
	}
	return (0);
}	

char	*find_path(char *cmd, char **envp)
{
	char	**multi_path;
	char	*path;
	int		i;

	i = 0;
	path = NULL;
	while (ft_strnstr(envp[i], "PATH", 4) == 0)
		i++;
	multi_path = ft_split(envp[i] + 5, ':');
	path = path_giver(multi_path, cmd);
	if (path)
		return (path);
	i = -1;
	while (multi_path[++i])
		free(multi_path[i]);
	free(multi_path);
	return (0);
}

void	error(char *s)
{
	perror(s);
	exit(EXIT_FAILURE);
}

void	execute(char *argv, char **envp)
{
	char	**cmd;
	int		i;
	char	*path;

	i = -1;
	if (!argv[0] || (argv[0] == ' ' && !argv[1]))
		error("command not found");
	cmd = ft_split(argv, ' ');
	path = find_path(cmd[0], envp);
	if (!path)
	{
		while (cmd[++i])
			free(cmd[i]);
		free(cmd);
		error("command not found");
	}
	if (execve(path, cmd, envp) == -1)
		error("execve error");
}
