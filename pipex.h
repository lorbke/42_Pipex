/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorbke <lorbke@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 16:39:39 by doreshev          #+#    #+#             */
/*   Updated: 2022/08/23 15:11:41 by lorbke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

// X_OK

# include <stdio.h>
# include <stdlib.h>
# include <sys/wait.h>
# include <sys/types.h>
# include <signal.h>
# include <unistd.h>
# include <string.h>
# include <fcntl.h>
# include "libft/libft.h"
# include "libft/ft_printf.h"

char	**ft_get_paths(char **envp, char ***cmd);

void	ft_execute(int in, int out, char *path, char *const args[], char *const env[]);

void	ft_write_fd_to_file(int fd_in, char *file_name);

#endif
