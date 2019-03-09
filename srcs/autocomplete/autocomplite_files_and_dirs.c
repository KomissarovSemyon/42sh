/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   autocomplite_files_and_dirs.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbaelor- <bbaelor-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/09 02:25:48 by bbaelor-          #+#    #+#             */
/*   Updated: 2019/03/09 06:41:51 by bbaelor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "autocomplete.h"

int		get_autocomplite_files_dir_len(char *str)
{
	size_t	len;
	int		res_len;
	char	**res;
	char	*pattern;
	char	*real_dir;

	len = ft_strlen(str);
	pattern = atcml_get_pattern(str, len);
	real_dir = atcml_get_rel_dir(str, len);
	if (xglob(pattern, real_dir, &res, (size_t *)&res_len))
	{
		free(pattern);
		free(real_dir);
		return (0);
	}
	free(pattern);
	free(real_dir);
	glob_free(&res, res_len);
	return (res_len);
}

char	**get_autocomplite_files_dir_mas(char *str, char **res, int *c)
{
	int		i;
	size_t	len;
	char	**out_glob;
	char	*pattern;
	char	*real_dir;

	i = 0;
	len = ft_strlen(str);
	pattern = atcml_get_pattern(str, len);
	real_dir = atcml_get_rel_dir(str, len);
	if (xglob(pattern, real_dir, &out_glob, &len))
		return (res);
	free(pattern);
	free(real_dir);
	while (out_glob[i])
	{
		res[*c] = out_glob[i];
		i++;
		(*c)++;
	}
	free(out_glob);
	res[*c] = NULL;
	return (res);
}