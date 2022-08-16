/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorbke <lorbke@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 16:39:39 by doreshev          #+#    #+#             */
/*   Updated: 2022/08/16 18:06:26 by lorbke           ###   ########.fr       */
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

int	ft_execute(char const *path, char *const *env, int fd[2], char **cmd);

#endif
