/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operand.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwerewol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 07:29:36 by bwerewol          #+#    #+#             */
/*   Updated: 2019/01/22 20:01:39 by nkertzma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "expr.h"

t_astree	*operand_1(void)
{
	t_astree	*res;

	g_curtok++;
	if (!(res = expr()))
		return (0);
	if (g_curtok <= ((size_t *)g_tokens)[2])
		if (((t_lexem *)vector_get_elem(g_tokens, g_curtok++))->type == CBRACKET)
			return (res);
	/* ft_free_node(res); /1* XXX - FREE ALL RES *1/ */
	return (0);
}

t_astree	*operand_2(void)
{
	t_astree	*leaf;

	if (!(leaf = ft_memalloc(sizeof(t_astree))))
		return (0);
	leaf->type = NUM;
	if ((leaf->content = ft_strdup(((t_lexem *)vector_get_elem(g_tokens, g_curtok++))->word)))
		return (leaf);
	free(leaf);
	return (0);
}

t_astree	*operand(void)
{
	uint64_t	type;

	if (g_curtok >= ((size_t *)g_tokens)[2])
		return (0);
	type = ((t_lexem *)vector_get_elem(g_tokens, g_curtok))->type;
	if (type == OBRACKET)
		return (operand_1());
	else if (type == NUM)
		return (operand_2());
	return (variable());
}