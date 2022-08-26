/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_fd_to_file.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorbke <lorbke@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 15:28:56 by lorbke            #+#    #+#             */
/*   Updated: 2022/08/26 21:57:54 by lorbke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_write_fd_to_file(int fd_in, char *file_name, int heredoc)
{
	int		fd_out;
	char	*str;
	int		buffer;

	if (heredoc == 1)
		fd_out = open(file_name, O_APPEND | O_WRONLY | O_CREAT, 0644);
	else
		fd_out = open(file_name, O_TRUNC | O_WRONLY | O_CREAT, 0644);
	if (fd_out == -1)
		ft_handle_error(3);
	buffer = 500;
	while (buffer == 500)
	{
		str = malloc((buffer + 1) * sizeof(char));
		if (str == NULL)
			ft_handle_error(1);
		buffer = read(fd_in, str, buffer);
		if (buffer == -1)
			ft_handle_error(4);
		if (write(fd_out, str, buffer) == -1)
			ft_handle_error(5);
		free(str);
	}
	close(fd_out);
}
