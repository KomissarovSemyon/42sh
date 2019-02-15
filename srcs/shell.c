/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkertzma <nkertzma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 18:15:05 by nkertzma          #+#    #+#             */
/*   Updated: 2019/02/15 18:55:54 by nkertzma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"
#include "lexer.h"
#include "libhash.h"

t_hshtb			**g_hash_env = NULL;
t_hshtb			**g_path = NULL;
void			*g_tokens = NULL;
unsigned int	g_curtok = 0;
int				g_parseerr = 0;

void	init(char **env)
{
	init_hash_env(env);
	init_path();
}

int		main(int ac, char **av, char **env)
{
	init(env);
	hash_print(g_hash_env);
	return (EXIT_SUCCESS);
}
