/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorbke <lorbke@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 16:39:39 by doreshev          #+#    #+#             */
/*   Updated: 2022/08/20 22:24:54 by lorbke           ###   ########.fr       */
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

char	*ft_strnstr_arr(char **str_arr, char *needle);
char	*ft_find_path(char *path_str, char delim, char *cmd);
char	**ft_get_paths(char **envp, char ***cmd);

char	***ft_init_cmds(char *args[], char delim);
void	ft_execute(int in, int out, char *path, char *const args[], char *const env[]);

#endif
