/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   glob.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkertzma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/20 15:40:02 by nkertzma          #+#    #+#             */
/*   Updated: 2019/01/22 19:44:43 by nkertzma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tools.h"

static size_t	get_files_count(char *path)
{
	struct dirent	*cdir;
	DIR				*dirp;
	size_t			count;

	count = 0;
	if (!(dirp = opendir(path)))
		return (count);
	while ((cdir = readdir(dirp)))
		count++;
	closedir(dirp);
	return (count);
}

static void		glob_free(char ***matches, int i)
{
	while (i >= 0)
	{
		free((*matches)[i]);
		i--;
	}
	free(*matches);
	*matches = NULL;
}

static int		read_dir(DIR *dirp, char *pattern, char ***matches, int *cnt)
{
	struct dirent	*cdir;
	size_t			i;

	i = 0;
	while ((cdir = readdir(dirp)))
	{
		if (match(cdir->d_name, pattern))
		{
			if (!((*matches)[i] = ft_strdup(cdir->d_name)))
			{
				glob_free(matches, i);
				return (-1);
			}
			i++;
		}
	}
	*cnt = i;
	(*matches)[i] = NULL;
	return (i);
}

int				glob(char *pattern, char *path, char ***matches, int *cnt)
{
	DIR				*dirp;
	size_t			arr_len;

	if (!pattern && !path && !matches)
		return (1);
	if (!(dirp = opendir(path)))
		return (1);
	if (!(arr_len = get_files_count(path)))
		return (1);
	if (!(*matches = (char **)malloc(sizeof(char *) * (arr_len + 1))))
		return (1);
	if ((read_dir(dirp, pattern, matches, cnt) == -1))
		return (1);
	closedir(dirp);
	return (0);
}