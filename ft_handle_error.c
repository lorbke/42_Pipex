/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_error.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorbke <lorbke@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 21:58:09 by lorbke            #+#    #+#             */
/*   Updated: 2022/08/26 21:58:31 by lorbke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_handle_error(int i, char *cmd)
{
	if (i == 0)
		ft_printf("pipex: wrong number of arguments.");
	if (i == 1)
		perror("pipex: malloc() failed");
	if (i == 2)
		perror("pipex: pipe() failed");
	if (i == 3)
		perror("pipex: open() failed");
	if (i == 4)
		perror("pipex: read() failed");
	if (i == 5)
		perror("pipex: write() failed");
	if (i == 6)
		perror("pipex: fork() failed");
	if (i == 7)
		perror("pipex: dup2() failed");
	if (i == 8)
		perror("pipex: execve() failed");
	if (i == 9)
		ft_printf("pipex: path could not be found");
	if (i == 10)
		ft_printf("pipex: command not found: %s", cmd);
	exit(i);
}
