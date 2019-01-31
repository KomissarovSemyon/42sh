/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   io_redirect.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwerewol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 15:39:52 by bwerewol          #+#    #+#             */
/*   Updated: 2019/01/31 21:53:00 by bwerewol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**                PREF
**               /
**              <(type)
**             / \
**   (content)2   filename(content)
*/

#include "parser.h"

t_astree        *io_redirect_1(void)
{
	t_astree        *root;

	root = xmalloc(sizeof(t_astree));
	root->content = ft_strdup(((t_lexem *)vector_get_elem(g_tokens, g_curtok++))->word);
	return (root);

}

t_astree        *io_redirect(void)
{
	t_astree        *root;
	t_astree        *res;

	if (g_curtok >= ((size_t *)g_tokens)[2])
		return (0);
	if (((t_lexem *)vector_get_elem(g_tokens, g_curtok))->type == NUMBER)
		res = io_redirect_1();
	else
		res = 0;
	if (!(root = io_file()))
		if (!(root = io_here()))
			return (0);
	root->left = res;
	return (root);
}
