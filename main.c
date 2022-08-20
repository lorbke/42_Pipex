/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorbke <lorbke@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 15:38:16 by lorbke            #+#    #+#             */
/*   Updated: 2022/08/20 23:27:34 by lorbke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

// manage path
// set file as input
// set file as output
// execute

// error handling (malloc errors)

char	***ft_init_cmds(char *args[], char delim)
{
	char	***cmd;
	int		i;

	i = 0;
	while (args[i])
		i++;
	cmd = (char ***)malloc(sizeof(char **) * i + 1);
	i = 0;
	while (args[i])
	{
		cmd[i] = ft_split(args[i], delim);
		i++;
	}
	cmd[i] = 0;
	return (cmd);
}

void	ft_execute(int in, int out, char *path, char *const args[], char *const env[])
{
	int pid;

	pid = fork();
	if (pid < 0)
		perror("fork failed");
	if (pid == 0)
	{
		if (dup2(in, STDIN_FILENO) == -1)
			perror("dup2 failed");
		if (dup2(out, STDOUT_FILENO) == -1)
			perror("dup2 failed");
		close(in);
		close(out);
		if (execve(path, args, env) == -1)
			perror("execve failed");
	}
	// waitpid(pid, NULL, 0);
}

int	main(int argc, char *argv[], char *envp[])
{
	char	***cmd;
	char	**path;
	int		fd[1024][2];

	cmd = ft_init_cmds(&argv[2], ' ');
	path = ft_get_paths(envp, cmd);

	// pre while logic
	if (pipe(fd[0]) == -1)
		perror("pipe failed");
	fd[0][1] = open(argv[1], O_RDONLY);
	close(fd[0][1]);

	// while logic
	int i = 0;
	while (cmd[i])
	{
		if (pipe(fd[i + 1]) == -1)
			perror("pipe failed");
		ft_execute(fd[i][0], fd[i + 1][1], path[i], cmd[i], envp);
		close(fd[i][0]);
		close(fd[i + 1][1]);
		i++;
	}

	// post while logic
	char	*out;
	out = malloc(100);
	if (read(fd[i][0], out, 100) == -1)
		perror("read failed");
	printf("%s\n", out);
	close(fd[i][0]);
	return (0);
}
