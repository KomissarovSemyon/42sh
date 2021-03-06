/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_echo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkertzma <nkertzma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 13:53:51 by nkertzma          #+#    #+#             */
/*   Updated: 2019/02/28 17:56:25 by nkertzma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"
#include "builtins.h"

int					echo_usage(char c)
{
	char	arg[3];

	arg[0] = '-';
	arg[1] = c;
	arg[2] = '\0';
	sputcmderr(sstrerr(SHERR_INVSNTX), "echo", arg);
	return (-1);
}

static void			echo_print_string(const char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] != '\\')
			ft_putchar(str[i]);
		else
		{
			if ((i = echo_handle_sequence(str, i + 1)) == -1)
				return ;
		}
		i++;
	}
}

static void			echo_print_strings(char **av, const int *flags, size_t i)
{
	size_t	size;

	size = size_str_arr(av + i);
	if (flags[0])
		size++;
	while (av[i])
	{
		if (flags[1])
			echo_print_string(av[i]);
		else
			ft_putstr(av[i]);
		if (i < size)
			ft_putchar(' ');
		i++;
	}
	if (!flags[0])
		ft_putchar('\n');
}

static int			echo_parse_flags(char **av, int *flags)
{
	int		i;

	i = 1;
	while (av[i])
	{
		if (av[i][0] == '-')
		{
			if (!echo_switch(av, i, flags))
				return (-1);
		}
		else
			return (i);
		i++;
	}
	return (i);
}

/*
** Builtin 'echo' parses flags and prints strings.
** The following flags are supported: -n, -e, -E.
** -n -- print string without '\n' at the end.
** -e -- interpret sequences.
** -E -- don't interpret sequences.
*/

int					built_echo(char **av, char **env)
{
	int		flags[2];
	int		i;

	env = NULL;
	flags[0] = 0;
	flags[1] = g_echoe == TRUE ? 1 : 0;
	if ((i = echo_parse_flags(av, flags)) == -1)
		return (SHERR_ERR);
	echo_print_strings(av, flags, (size_t)i);
	return (SHERR_OK);
}
