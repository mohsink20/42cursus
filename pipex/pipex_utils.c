/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mokhan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 18:29:53 by mokhan            #+#    #+#             */
/*   Updated: 2023/12/17 18:29:54 by mokhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	cleanup(char **args, char *path, char **paths)
{
	int	i;

	i = -1;
	if (path)
		free(path);
	if (paths)
	{
		while (paths[++i])
			free(paths[i]);
		free(paths);
	}
	while (args[++i])
		free(args[i]);
	free(args);
}

char	*find_command_path(char *cmd, char **envp)
{
	char	*res;
	char	**paths;
	int		i;

	i = 0;
	while (ft_strnstr(envp[i], "PATH", 4) == 0)
		i++;
	paths = ft_split(envp[i] + 5, ':');
	i = 0;
	while (paths[i])
	{
		res = join_paths(paths[i], cmd);
		if (access(res, F_OK) == 0)
		{
			free(paths);
			return (res);
		}
		free(res);
		i++;
	}
	free_paths(paths);
	return (NULL);
}

void	execute_command(char **cmd, char **envp)
{
	char	*path;

	path = find_command_path(cmd[0], envp);
	if (!path)
		error();
	if (execve(path, cmd, envp) == -1)
		error();
}

char	*join_paths(char *dir, char *cmd)
{
	char	*full_path;
	char	*result;

	full_path = ft_strjoin(dir, "/");
	result = ft_strjoin(full_path, cmd);
	free(full_path);
	return (result);
}

void	free_paths(char **paths)
{
	int	i;

	i = -1;
	while (paths[++i])
		free(paths[i]);
	free(paths);
}
