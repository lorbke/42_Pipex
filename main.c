/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorbke <lorbke@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 15:38:16 by lorbke            #+#    #+#             */
/*   Updated: 2022/08/30 14:40:55 by lorbke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static char	***ft_init_cmds(char *args[], char delim)
{
	char	***cmd;
	int		i;

	i = 0;
	while (args[i + 1])
		i++;
	cmd = malloc(sizeof(char **) * (i + 1));
	if (cmd == NULL)
		ft_handle_error(1, NULL);
	i = 0;
	while (args[i + 1])
	{
		cmd[i] = ft_split(args[i], delim);
		if (cmd[i] == NULL)
			ft_handle_error(1, NULL);
		i++;
	}
	cmd[i] = NULL;
	return (cmd);
}

static int	ft_open_outfile(char *file_name, int heredoc)
{
	int	fd;

	if (heredoc == 1)
		fd = open(file_name, O_APPEND | O_WRONLY | O_CREAT, 0644);
	else
		fd = open(file_name, O_TRUNC | O_WRONLY | O_CREAT, 0644);
	return (fd);
}

int	main(int argc, char *argv[], char *envp[])
{
	int		i;
	int		fd[2];
	int		fd_out;
	char	***cmd;

	i = 0;
	if (argc < 5)
		ft_handle_error(0, NULL);
	if (ft_strncmp(argv[1], "here_doc", ft_strlen(argv[1])) == 0)
	{
		ft_pipe_heredoc(fd, argv[(i++) + 2], argc);
		close(fd[1]);
	}
	else
	{
		fd[0] = open(argv[1], O_RDONLY);
		if (fd[0] == -1)
			ft_handle_error(3, NULL);
	}
	cmd = ft_init_cmds(&argv[i + 2], ' ');
	fd_out = ft_open_outfile(argv[argc - 1], i);
	ft_exec_pipe(fd[0], fd_out, cmd, envp);
	while (wait(NULL) > 0)
		;
	return (0);
}
