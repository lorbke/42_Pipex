/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorbke <lorbke@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 15:38:16 by lorbke            #+#    #+#             */
/*   Updated: 2022/08/25 23:42:22 by lorbke           ###   ########.fr       */
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

int	main(int argc, char *argv[], char *envp[])
{
	int		i;
	int		fd[2];
	int		fd_out;
	char	***cmd;

	i = 2;
	if (ft_strncmp(argv[1], "here_doc", ft_strlen(argv[1])) == 0)
	{
		ft_pipe_heredoc(fd, argv[i], argc);
		i++;
	}
	else
		fd[0] = open(argv[1], O_RDONLY);
	cmd = ft_init_cmds(&argv[i], ' ');
	fd_out = ft_exec_pipe(fd[0], argc, cmd, envp);
	ft_write_fd_to_file(fd_out, argv[argc - 1]);
	while (wait(NULL) > 0);
	return (0);
}

// create outfile if not existing
// append when heredoc
// wrong number of arguments check
// here_doc limiter check
