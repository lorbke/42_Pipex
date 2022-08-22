/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorbke <lorbke@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 16:39:39 by doreshev          #+#    #+#             */
/*   Updated: 2022/08/22 15:34:48 by lorbke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

// # ifndef PATH_SH
// #  define PATH_SH "/bin/ls"
// # endif

// # ifndef PATH_ENV
// #  define PATH_ENV NULL
// # endif

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

int		ft_write_to_file_fd(int fd, char *file_name);

#endif
