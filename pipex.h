/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorbke <lorbke@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/07 16:39:39 by lorbke            #+#    #+#             */
/*   Updated: 2022/08/30 15:17:51 by lorbke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdlib.h>
# include <sys/wait.h>
# include <sys/types.h>
# include <signal.h>
# include <unistd.h>
# include <string.h>
# include <fcntl.h>
# include "libft/libft.h"
# include "libft/ft_printf.h"

void	ft_handle_error(int i, char *cmd);
void	ft_pipe_heredoc(int fd[2], char *limiter, int argc);
char	**ft_get_paths(char **envp, char ***cmd);
int		ft_exec_pipe(int fd_in, int fd_out, char ***cmd, char *envp[]);
void	ft_write_fd_to_file(int fd_in, char *file_name, int heredoc);

#endif
