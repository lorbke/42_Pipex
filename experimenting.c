/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   experimenting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorbke <lorbke@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 19:17:48 by lorbke            #+#    #+#             */
/*   Updated: 2022/08/16 18:59:25 by lorbke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

// functions: open, close, read, write, malloc, free, perror, strerror, access, dup,
// dup2, execve, exit, fork, pipe, unlink, wait, waitpid, printf
//
// perror prints error message
// strerror prints error message but selects message from array of strings
// access checks files for permission rights
// dup will copy the file descriptor of a file, dup2 does same but takes new fd as parameter
// exit will terminate the calling process and closes all related fds
// fork will create a new process (child) which runs concurrently with the parent process
// pipe works just like in shell, output of one process will be piped into another
// unlink will delete a name from the filesystem
// wait blocks a process until a child is created successfully or after signal is received
// waitpid allows calling thread to obtain status info for a child process
// execve for executing every possible shell command

// understand the input
// < is redirecting input, > is redirecting output
// >> will append text instead of > overwrite

int	main(int argc, char *argv[])
{
	// execve variables
	char		*path = "/bin/ls";
	char *const	args[] = {"ls", "-l", NULL};
	char *const	args2[] = {"wc", "-l", NULL};
	char *const env[] = {NULL};
	// fd[0] = read end of pipe
	// fd[1] = write end of pipe
	int			fd[2];
	int			id;
	char		out[1000];

	// open the pipe
	if (pipe(fd) == -1)
	{
		perror("pipe failed");
	 	return (1);
	}
	// create new process, current fds get inherited by it
	id = fork();
	if (id == -1)
	{
		perror("fork failed");
	 	return (2);
	}
	// 0 = child process, everything following is executed in the child
	if (id == 0)
	{
		// since fds are inherited, each process has its own fds,
		// read fd of fork is not used, therefore closed immediately
		close(fd[0]);
		// execve needs the correct fd, therefore duplicate (???)
		dup2(fd[1], 1);
		if (execve(path, args, env) == -1)
		{
			perror("execve failed");
			return (3);
		}
		close(fd[1]);
	}
	// this is for further execution of the parent process, which is
	// also executed, even if a child was created, because there are
	// now two programs
	else
	{
		close(fd[1]);
		if (pipe(fd) == -1)
		{
			perror("pipe failed");
	 		return (1);
		}
		id = fork();
		if (id == -1)
		{
			perror("fork failed");
	 		return (2);
		}
		// 0 = child process, everything following is executed in the child
		if (id == 0)
		{
			// since fds are inherited, each process has its own fds,
			// read fd of fork is not used, therefore closed immediately
			// execve needs the correct fd, therefore duplicate (???)
			dup2(fd[1], 1);
			dup2(fd[0], 0);
			close(fd[0]);
			if (execve(path, args2, env) == -1)
			{
				perror("execve failed");
				return (3);
			}
			close(fd[1]);
		}
		else
		{
			close(fd[1]);
			if (read(fd[0], out, 30) == -1)
			{
				perror("read failed");
				return (4);
			}
			close(fd[0]);
			printf("Got from child process: %s\n", out);
		}
	}
	return (0);
}

// ft pipex
// - opens pipe
// - loop through input, call execute each loop and pipe last execute return into next one

// ft execute
// - forks
// - executes command
// - returns fd to read command ouptut from


// here_doc?? >> will append text instead of > overwrite



