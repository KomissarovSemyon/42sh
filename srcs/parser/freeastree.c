/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freeastree.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwerewol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 21:58:50 by bwerewol          #+#    #+#             */
/*   Updated: 2019/02/08 13:35:49 by bwerewol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

t_astree	*freeastree(t_astree	*root)
{
	if (!root)
		return (0);
	if (root->content)
		free(root->content);
	if (root->left)
		freeastree(root->left);
	if (root->right)
		freeastree(root->left);
	free(root);
	return (0);
}
