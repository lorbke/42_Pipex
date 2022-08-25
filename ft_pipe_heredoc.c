/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipe_heredoc.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorbke <lorbke@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 22:40:07 by lorbke            #+#    #+#             */
/*   Updated: 2022/08/25 22:59:37 by lorbke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	ft_print_heredoc_head(int argc)
{
	while (argc - 4 > 1)
	{
		ft_printf("pipe ");
		argc--;
	}
	ft_printf("heredoc>");
}

void	ft_pipe_heredoc(int fd[2], char *delim, int argc)
{
	int		delim_len;
	int		i;
	int		buffer_size;
	char	*line;

	if (pipe(fd) == -1)
		perror("pipe failed");
	delim_len = ft_strlen(delim);
	buffer_size = 1000;
	line = malloc(buffer_size * sizeof(char));
	i = 0;
	while (1)
	{
		ft_print_heredoc_head(argc);
		i = read(STDOUT_FILENO, line, buffer_size);
		line[i] = 0;
		if (ft_strncmp(line, delim, ft_strlen(line) - 1) == 0
			&& ft_strncmp(line, delim, delim_len) == 0)
			break ;
		write(fd[1], line, i);
	}
	free(line);
	close(fd[1]);
}
