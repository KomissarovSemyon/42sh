/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bits_operators.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkertzma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/22 20:32:33 by nkertzma          #+#    #+#             */
/*   Updated: 2019/01/23 11:14:56 by nkertzma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "calc.h"

intmax_t	op_rsh(intmax_t operator, t_astree *node)
{
	intmax_t	tmp;

	tmp = operator >> calc(node->left);
	if (node->right)
		return (g_operators[node->right->type - OPSHIFT](tmp, node->right));
	return (tmp);
}

intmax_t	op_lsh(intmax_t operator, t_astree *node)
{
	intmax_t	tmp;

	tmp = operator << calc(node->left);
	if (node->right)
		return (g_operators[node->right->type - OPSHIFT](tmp, node->right));
	return (tmp);
}
