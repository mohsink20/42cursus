/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mokhan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 18:27:33 by mokhan            #+#    #+#             */
/*   Updated: 2023/12/17 18:28:35 by mokhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	display_argument_error(void)
{
	ft_putstr_fd("Error: Bad arguments\n", 2);
	ft_putstr_fd("Usage: ./pipex <file1> <cmd1> <cmd2> <file2>\n", 1);
}

void	error(void)
{
	perror("Error");
	exit(EXIT_FAILURE);
}

void	handle_child_process(char *input_file, char **cmd1, \
				char **envp, int *fd)
{
	int	filein;

	filein = open(input_file, O_RDONLY, 0777);
	if (filein == -1)
		error();
	dup2(fd[1], STDOUT_FILENO);
	dup2(filein, STDIN_FILENO);
	close(fd[0]);
	execute_command(cmd1, envp);
	cleanup(cmd1, NULL, NULL);
}

void	handle_parent_process(char *output_file, char **cmd2, \
				char **envp, int *fd)
{
	int	fileout;

	fileout = open(output_file, O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (fileout == -1)
		error();
	dup2(fd[0], STDIN_FILENO);
	dup2(fileout, STDOUT_FILENO);
	close(fd[1]);
	execute_command(cmd2, envp);
	cleanup(cmd2, NULL, NULL);
}

int	main(int argc, char **argv, char **envp)
{
	pid_t	pid;
	int		fd[2];

	if (argc == 5)
	{
		if (pipe(fd) == -1)
			error();
		pid = fork();
		if (pid == -1)
			error();
		if (pid == 0)
			handle_child_process(argv[1], ft_split(argv[2], ' '), envp, fd);
		else
			waitpid(pid, NULL, 0);
		handle_parent_process(argv[4], ft_split(argv[3], ' '), envp, fd);
	}
	else
	{
		display_argument_error();
	}
	return (0);
}
