/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execute.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorbke <lorbke@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 15:30:13 by lorbke            #+#    #+#             */
/*   Updated: 2022/08/23 13:39:03 by lorbke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_execute(int in, int out, char *path, char *const args[], char *const env[])
{
	int	pid;

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
}
