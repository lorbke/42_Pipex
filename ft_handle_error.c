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

void	ft_handle_error(int i)
{
	if (i == 0)
		ft_printf("Error: Wrong number of arguments.");
	if (i == 1)
		perror("Error: malloc() failed");
	if (i == 2)
		perror("Error: pipe() failed");
	if (i == 3)
		perror("Error: open() failed");
	if (i == 4)
		perror("Error: read() failed");
	if (i == 5)
		perror("Error: write() failed");
	if (i == 6)
		perror("Error: fork() failed");
	if (i == 7)
		perror("Error: dup2() failed");
	if (i == 8)
		perror("Error: execve() failed");
	if (i == 9)
		ft_printf("Error: path could not be found");
	if (i == 10)
		ft_printf("Error: command not found");
	exit(i);
}
