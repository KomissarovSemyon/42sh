/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_esc_code.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sitlcead <sitlcead@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 13:53:30 by sitlcead          #+#    #+#             */
/*   Updated: 2019/03/03 20:45:34 by sitlcead         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "readline.h"
#include <time.h>

static int	check_esc_buttons(t_uchar c, int i)
{
	t_uchar	tmp;

	if (c == LEFT || c == RIGHT ||
		c == DOWN || c == UP ||
		c == HOME1 || c == HOME2 ||
		c == END1 || c == END2 ||
		c == DEL)
		return (1);
	tmp = 0;
	while (i--)
		tmp = (tmp << 8) + 0xFF;
	c &= tmp;
	if (c == (LEFT & tmp) || c == (RIGHT & tmp )||
		c == (DOWN & tmp )|| c == (UP & tmp) ||
		c == (HOME1 & tmp) || c == (HOME2 & tmp) ||
		c == (END1 & tmp) || c == (END2 & tmp) ||
		c == (DEL & tmp))
		return (2);
	return (0);
}

static t_uchar	erase_esc_code(t_uchar c, int i)
{
	t_uchar	tmp;

	tmp = 0;
	while (i--)
		tmp = (tmp << 8) + 0xFF;
	return (c & tmp);
}

static int		no_esc_code(t_matrix *matrix, t_uchar c, int i)
{
	if (g_mode == VI)
		modes_handling(matrix, ESC);
	modes_handling(matrix, erase_esc_code(c, i));
	return (1);
}

static int		new_esc_code(t_matrix *matrix)
{
	if (g_mode == VI)
		modes_handling(matrix, ESC);
	return (esc_code_handling(matrix, ESC));
}

int			esc_code_handling(t_matrix *matrix, t_uchar c)
{
	size_t	i;
	time_t	start;
	time_t	end;
	t_uchar	tmp;
	int		ret;

	i = 0;
	while (++i < sizeof(t_uchar))
	{
		start = time(&start);
		tmp = get_next_symbol(sizeof(char));
		end = time(&end);
		c += (tmp << (i * 8));
		if (difftime(end, start) >= 1)
			return (no_esc_code(matrix, c, i));
		if (tmp == ESC)
			return (new_esc_code(matrix));
		ret = check_esc_buttons(c, i);
		if (ret == 0)
			return (no_esc_code(matrix, c, i));
		if (ret == 1)
			return (modes_handling(matrix, c));
	}
	return (no_esc_code(matrix, c, i));
}
