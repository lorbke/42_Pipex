/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec_pipe.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorbke <lorbke@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 15:30:13 by lorbke            #+#    #+#             */
/*   Updated: 2022/08/30 17:58:16 by lorbke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	ft_free_path(char **path)
{
	int	i;

	i = 0;
	while (path[i])
	{
		free(path[i]);
		i++;
	}
	free(path);
}

static void	ft_free_cmd(char ***cmd)
{
	int	i;
	int	j;

	i = 0;
	while (cmd[i])
	{
		j = 0;
		while (cmd[i][j])
		{
			free(cmd[i][j]);
			j++;
		}
		free(cmd[i]);
		i++;
	}
	free(cmd);
}

static void	ft_execute(int fd[2], char *path, char **cmd, char *envp[])
{
	int	pid;

	pid = fork();
	if (pid == -1)
		ft_handle_error(6, NULL);
	if (pid == 0)
	{
		if (dup2(fd[0], STDIN_FILENO) == -1)
			ft_handle_error(7, NULL);
		if (dup2(fd[1], STDOUT_FILENO) == -1)
			ft_handle_error(7, NULL);
		close(fd[0]);
		close(fd[1]);
		if (execve(path, cmd, envp) == -1)
			ft_handle_error(8, NULL);
	}
}

int	ft_exec_pipe(int fd_in, int fd_out, char ***cmd, char *envp[])
{
	char	**path;
	int		fd[1024][2];
	int		fd_temp[2];
	int		i;

	path = ft_get_paths(envp, cmd);
	fd[0][0] = fd_in;
	i = 0;
	while (cmd[i])
	{
		if (pipe(fd[i + 1]) == -1)
	ft_handle_error(2, NULL);
		fd_temp[0] = fd[i][0];
		if (cmd[i + 1])
			fd_temp[1] = fd[i + 1][1];
		else
			fd_temp[1] = fd_out;
		ft_execute(fd_temp, path[i], cmd[i], envp);
		close(fd[i][0]);
		close(fd[i + 1][1]);
		i++;
	}
	ft_free_path(path);
	ft_free_cmd(cmd);
	return (fd[i][0]);
}
