/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_end.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwerewol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 15:54:30 by bwerewol          #+#    #+#             */
/*   Updated: 2019/02/02 14:11:52 by bwerewol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

t_astree	*here_end(void)
{
	t_lexem		*token;
	t_astree	*root;

	if (g_curtok >= ((size_t *)g_tokens)[2])
		return (0);
	token = ((t_lexem *)vector_get_elem(g_tokens, g_curtok));
	if (token->type != WORD)
		return (0);
	root = xmalloc(sizeof(t_astree));
	root->content = ft_strdup(token->word);
	g_curtok++;
	return (root);
}
