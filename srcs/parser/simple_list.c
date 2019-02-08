/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwerewol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 21:53:19 by bwerewol          #+#    #+#             */
/*   Updated: 2019/02/08 11:46:47 by bwerewol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

t_astree	*simple_list(void)
{
	int			type;
	t_astree	*res;

	res = simple_list1();
	if (g_curtok >= ((size_t *)g_tokens)[2])
		return (res);
	type = ((t_lexem *)vector_get_elem(g_tokens, g_curtok))->type;
	if (type != AND && type != SEMI)
		return (freeastree(res));
	g_curtok++;
	return (res);
}
