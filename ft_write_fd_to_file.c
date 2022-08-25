/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_to_file_fd.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorbke <lorbke@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 15:28:56 by lorbke            #+#    #+#             */
/*   Updated: 2022/08/23 15:31:29 by lorbke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_write_fd_to_file(int fd_in, char *file_name)
{
	int		fd_out;
	char	*str;
	int		buffer;

	fd_out = open(file_name, O_TRUNC | O_WRONLY);
	buffer = 500;
	while (buffer == 500)
	{
		str = malloc((buffer + 1) * sizeof(char));
		buffer = read(fd_in, str, buffer);
		write(fd_out, str, buffer);
		free(str);
	}
	close(fd_out);
}
