/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipe_heredoc.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorbke <lorbke@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 22:40:07 by lorbke            #+#    #+#             */
/*   Updated: 2022/08/26 21:30:24 by lorbke           ###   ########.fr       */
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

void	ft_pipe_heredoc(int fd[2], char *limiter, int argc)
{
	int		limiter_len;
	int		i;
	char	*line;

	if (pipe(fd) == -1)
		ft_handle_error(2, NULL);
	limiter_len = ft_strlen(limiter);
	line = malloc(1000 * sizeof(char));
	if (line == NULL)
		ft_handle_error(1, NULL);
	i = 0;
	while (1)
	{
		ft_print_heredoc_head(argc);
		i = read(STDOUT_FILENO, line, 1000);
		if (i == -1)
			ft_handle_error(4, NULL);
		line[i] = 0;
		if (ft_strncmp(line, limiter, ft_strlen(line) - 1) == 0
			&& ft_strncmp(line, limiter, limiter_len) == 0)
			break ;
		if (write(fd[1], line, i) == -1)
			ft_handle_error(5, NULL);
	}
	free(line);
}
