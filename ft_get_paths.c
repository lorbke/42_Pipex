/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_paths.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorbke <lorbke@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 15:15:44 by lorbke            #+#    #+#             */
/*   Updated: 2022/08/26 22:04:03 by lorbke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static char	*ft_strnstr_arr(char **str_arr, char *needle)
{
	while (*str_arr)
	{
		if (ft_strnstr(*str_arr, needle, ft_strlen(*str_arr)) != NULL)
			return (*str_arr);
		str_arr++;
	}
	return (NULL);
}

static char	*ft_find_path(char *path_str, char delim, char *cmd)
{
	char	**path_arr;
	char	*temp;

	cmd = ft_strjoin("/", cmd);
	path_arr = ft_split(path_str, delim);
	if (path_arr == NULL)
		ft_handle_error(1);
	while (*path_arr)
	{
		temp = ft_strjoin(*path_arr, cmd);
		if (temp == NULL)
			ft_handle_error(1);
		if (access(temp, X_OK) == 0)
			return (temp);
		path_arr++;
	}
	return (NULL);
}

char	**ft_get_paths(char **envp, char ***cmd)
{
	char	**path;
	char	*path_set;
	char	*path_ident = "PATH=";
	int		i;

	path_set = ft_strnstr_arr(envp, path_ident);
	path_set = ft_strtrim(path_set, path_ident);
	if (path_set == NULL)
		ft_handle_error(9);
	i = 0;
	while (cmd[i])
		i++;
	path = (char **)malloc(sizeof(char *) * (i + 1));
	if (path == NULL)
		ft_handle_error(1);
	i = 0;
	while (cmd[i])
	{
		path[i] = ft_find_path(path_set, ':', cmd[i][0]);
		if (path[i] == NULL)
			ft_handle_error(10);
		i++;
	}
	path[i] = 0;
	return (path);
}
