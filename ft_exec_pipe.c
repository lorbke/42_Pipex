/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec_pipe.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorbke <lorbke@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 15:30:13 by lorbke            #+#    #+#             */
/*   Updated: 2022/08/25 23:30:27 by lorbke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	ft_execute(int fd[2], char *path, char **cmd, char *envp[])
{
	int	pid;

	pid = fork();
	if (pid < 0)
		perror("fork failed");
	if (pid == 0)
	{
		if (dup2(fd[0], STDIN_FILENO) == -1)
			perror("dup2 failed");
		if (dup2(fd[1], STDOUT_FILENO) == -1)
			perror("dup2 failed");
		close(fd[0]);
		close(fd[1]);
		if (execve(path, cmd, envp) == -1)
			perror("execve failed");
	}
}

// takes beginning of pipe and returns end of pipe
int	ft_exec_pipe(int fd_in, int argc, char ***cmd, char *envp[])
{
	char	**path;
	int		fd[1024][2];
	int		fd_temp[2];
	int		i;

	path = ft_get_paths(envp, cmd);
	fd[0][0] = fd_in;
	i = 0;
	while (cmd[i + 1])
	{
		if (pipe(fd[i + 1]) == -1)
			perror("pipe failed");
		fd_temp[0] = fd[i][0];
		fd_temp[1] = fd[i + 1][1];
		ft_execute(fd_temp, path[i], cmd[i], envp);
		close(fd[i][0]);
		close(fd[i + 1][1]);
		i++;
	}
	return (fd[i][0]);
}
