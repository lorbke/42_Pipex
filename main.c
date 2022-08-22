/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorbke <lorbke@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 15:38:16 by lorbke            #+#    #+#             */
/*   Updated: 2022/08/22 16:40:38 by lorbke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

// manage path
// set file as input
// set file as output
// execute

// error handling (malloc errors)
// frees
// defines in header

static char	***ft_init_cmds(char *args[], char delim)
{
	char	***cmd;
	int		i;

	i = 0;
	while (args[i])
		i++;
	cmd = malloc(sizeof(char **) * i + 1);
	i = 0;
	while (args[i])
	{
		cmd[i] = ft_split(args[i], delim);
		i++;
	}
	cmd[i] = 0;
	return (cmd);
}

int	main(int argc, char *argv[], char *envp[])
{
	char	***cmd;
	char	**path;
	int		fd[1024][2];
	int		i;

	cmd = ft_init_cmds(&argv[2], ' ');
	path = ft_get_paths(envp, cmd);
	fd[0][0] = open(argv[1], O_RDONLY);
	i = 0;
	while (cmd[i + 1])
	{
		if (pipe(fd[i + 1]) == -1)
			perror("pipe failed");
		ft_execute(fd[i][0], fd[i + 1][1], path[i], cmd[i], envp);
		close(fd[i][0]);
		close(fd[i + 1][1]);
		i++;
	}
	waitpid(-1, NULL, 0);
	ft_write_to_file_fd(fd[i][0], argv[argc - 1]);
	return (0);
}
