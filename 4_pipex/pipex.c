/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtimsina <rtimsina@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 09:36:44 by rtimsina          #+#    #+#             */
/*   Updated: 2023/03/06 11:46:03 by rtimsina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	child_process(char **argv, char **envp, int *fd)
{
	int	file_in;

	file_in = open(argv[1], O_RDONLY);
	if (file_in == -1)
		perror ("Error");
	dup2(fd[1], STDOUT_FILENO);
	dup2(file_in, STDIN_FILENO);
	close(fd[0]);
	execute(argv[2], envp);
}

void	parent_process(char **argv, char **envp, int *fd)
{
	int	file_out;
	int	file_check;

	file_check = open(argv[1], O_RDONLY);
	if (file_check == -1)
		perror ("Error");
	close(file_check);
	file_out = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (file_out == -1)
		error("Error");
	dup2(fd[0], STDIN_FILENO);
	dup2(file_out, STDOUT_FILENO);
	close(fd[1]);
	execute(argv[3], envp);
}

int	file_check(char *argv[])
{
	int	file_in;

	file_in = open(argv[1], O_RDONLY);
	if (file_in == -1)
	{
		perror ("Error");
		return (0);
	}
	close(file_in);
	return (1);
}

int	main(int argc, char *argv[], char *envp[])
{
	int		fd[2];
	pid_t	pid1;
	int		file_in;

	if (argc == 5)
	{
		file_in = file_check(argv);
		if (file_in == 0)
			return (0);
		if (pipe(fd) == -1)
			error("Error");
		pid1 = fork();
		if (pid1 == -1)
			error("Error");
		if (pid1 == 0)
			child_process(argv, envp, fd);
		waitpid(pid1, NULL, 0);
		parent_process(argv, envp, fd);
	}
	else
		write(1, "Bad Arguments\n", 15);
	return (0);
}
