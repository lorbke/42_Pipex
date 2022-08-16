/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorbke <lorbke@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 17:19:18 by lorbke            #+#    #+#             */
/*   Updated: 2022/08/16 18:31:56 by lorbke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

// ft execute
// - forks
// - executes command
// - returns fd to read command ouptut from
int	ft_execute(char const *path, char *const *env, int fd[2], char **cmd)
{
	int	id;
	char	*str;

	id = fork();
	perror("fork failed");
	if (id == 0)
	{
		close(fd[0]);
		dup2(fd[1], 1);
		execve(path, cmd, env);
		close(fd[1]);
	}
	close(fd[1]);

	read(fd[0], str, 30);
	perror("read failed");
	write(1, &str, 30);
	return(fd[0]);
}

// ft parse_arg
// - parses argv to get something that is manageable for execve


// ft pipex
// - opens pipe
// - loop through input, call execute each loop and pipe last execute return into next one
int	main(int argc, char *argv[])
{
	char const	*path = "/bin/ls";
	char *const	*env = NULL;
	int			fd[2];
	int			i;
	char		**str;
	char		*echo[] = {"echo", NULL};

	fd[0] = open(argv[0], O_RDONLY);
	i = 1;
	while (argv[i + 1] != NULL)
	{
		pipe(fd);
		perror("pipe failed");
		str = ft_split(argv[i], ' ');
		printf("\n!!! %s !!!\n", str[0]);
		printf("\n!!! %s !!!\n", str[1]);
		fd[0] = ft_execute(path, env, fd, str);
		i++;
	}
	fd[1] = open(argv[i], O_RDONLY);
	ft_execute(path, env, fd, echo);
	return (0);
}

// here_doc?? >> will append text instead of > overwrite
