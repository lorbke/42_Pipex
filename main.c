/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorbke <lorbke@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 15:38:16 by lorbke            #+#    #+#             */
/*   Updated: 2022/08/23 18:39:19 by lorbke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

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

void	ft_pipe_heredoc(int fd_out, char *delim)
{
	char	*str;
	char	*out;
	int		buffer;
	int		i;

	buffer = 10;
	str = malloc((buffer + 1) * sizeof(char));
	out = malloc((buffer + 1) * sizeof(char));
	*str = 0;
	*out = 0;
	i = 0;
	while (ft_strncmp(str, delim, ft_strlen(delim + 10)) != 0)
	{
		ft_printf("%s", out);
		ft_printf("heredoc>");
		str = malloc((buffer + 1) * sizeof(char));
		i += read(STDOUT_FILENO, str, buffer);
		out = ft_strjoin(out, str);
		free(str);
	}
	write(fd_out, out, i);
}

int	main(int argc, char *argv[], char *envp[])
{
	char	***cmd;
	char	**path;
	int		fd[1024][2];
	int		i;

	if (ft_strncmp(argv[1], "here_doc", 8) == 0)
	{
		if (pipe(fd[0]) == -1)
			perror("pipe failed");
		ft_pipe_heredoc(fd[0][1], argv[2]);
		close(fd[0][1]);
		cmd = ft_init_cmds(&argv[3], ' ');
	}
	else
	{
		fd[0][0] = open(argv[1], O_RDONLY);
		cmd = ft_init_cmds(&argv[2], ' ');
	}
	path = ft_get_paths(envp, cmd);
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
	ft_write_fd_to_file(fd[i][0], argv[argc - 1]);
	while (wait(NULL) > 0);
	return (0);
}

// create outfile if not existing
