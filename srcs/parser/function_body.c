/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function_body.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwerewol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 18:19:02 by bwerewol          #+#    #+#             */
/*   Updated: 2019/03/01 21:27:58 by nkertzma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	FD - Fuction Def
**	FB - Function Body
**	SHCMD - SHell CoMmanD
**	RDLST - ReDirection LiST
**
**           FD
**          /  \
**        FB    ...
**       /  \
**  SHCMD    RDLST
*/

#include "parser.h"

t_astree	*function_body(void)
{
	t_astree	*res;
	t_astree	*root;

	if (!(res = shell_command()))
		return (0);
	root = xmalloc(sizeof(t_astree));
	root->left = res;
	root->right = redirection_list();
	return (root);
}
