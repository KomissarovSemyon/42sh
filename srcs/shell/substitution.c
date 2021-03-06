/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   substitution.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkertzma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/25 13:54:49 by nkertzma          #+#    #+#             */
/*   Updated: 2019/03/25 13:54:51 by nkertzma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"
#include "lexer.h"
#include "parser.h"
#include "execute.h"

static int	exec_substitution(t_astree *root, int isoutput)
{
	int			fd[2];
	int			resfd;

	pipe(fd);
	/* resfd = fd[0]; */
	resfd = fd[isoutput ? 0 : 1];
	/* fd[0] = 0; */
	fd[isoutput ? 0 : 1] = isoutput ? 0 : 1;
	if (g_dontexec == FALSE && root)
		execlist1(root, fd, 0);
	close(fd[isoutput ? 1 : 0]);
	if (g_execerr || g_parseerr)
	{
		close(resfd);
		resfd = -1;
	}
	return (resfd);
}

int			substitution(char *cmd, int isoutput)
{
	t_lexer		*lex;
	t_astree	*ast;
	int			resfd;

	lex = lexer(cmd, ft_strlen(cmd));
	g_tokens = lex->lexems;
	resfd = -1;
	if ((ast = inputunit()))
		resfd = exec_substitution(ast, isoutput);
	g_execerr = 0;
	freeastree(ast);
	lexer_free(lex);
	return (resfd);
}

char		*substitution_output(char *cmd)
{
	int		fd;
	int		count;
	char	*res;
	char	buff[100];

	if ((fd = substitution(cmd, 1)) == -1)
		return ((char *)0);
	res = xmalloc(sizeof(char));
	res[0] = 0;
	while ((count = read(fd, buff, 100)) > 0)
	{
		buff[count] = 0;
		res = ft_stradd(res, buff, 0);
	}
	if (count == 0)
		return (res);
	free(res);
	return ((char *)0);
}
