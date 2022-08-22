/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_to_file_fd.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorbke <lorbke@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 15:28:56 by lorbke            #+#    #+#             */
/*   Updated: 2022/08/22 15:55:52 by lorbke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static char	*ft_read_to_str(int fd)
{
	char	*str;
	int		buffer_size;
	int		n;

	buffer_size = 2;
	str = malloc((buffer_size + 1) * sizeof(char));
	n = read(fd, str, buffer_size);
	while (n >= buffer_size)
	{
		buffer_size *= 2;
		str = ft_reallocf(str, n + buffer_size + 1);
		n += read(fd, &str[n], buffer_size);
	}
	str[n] = 0;
	return (str);
}

int	ft_write_to_file_fd(int fd, char *file_name)
{
	int		fd_out;
	int		n;
	char	*out;

	out = ft_read_to_str(fd);
	fd_out = open(file_name, O_TRUNC | O_WRONLY);
	n = write(fd_out, out, ft_strlen(out));
	close(fd_out);
	return (n);
}
