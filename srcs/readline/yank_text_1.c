/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   yank_text_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: narchiba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/08 13:28:39 by narchiba          #+#    #+#             */
/*   Updated: 2019/03/08 13:29:07 by narchiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "readline.h"

int	yank_begin_word(t_matrix *matrix)
{
	size_t col;

	col = get_cursor_pos_begin_word(matrix);
	matrix_string_yank(matrix, matrix->cursor->row, col);
	return (1);
}

int	yank_next_word(t_matrix *matrix)
{
	size_t col;

	col = get_cursor_pos_next_word(matrix);
	matrix_string_yank(matrix, matrix->cursor->row, col);
	return (1);
}

int	yank_end_word(t_matrix *matrix)
{
	size_t col;

	col = get_cursor_pos_end_word(matrix);
	matrix_string_yank(matrix, matrix->cursor->row, col);
	return (1);
}

int	yank_end(t_matrix *matrix)
{
	size_t col;

	col = get_cursor_pos_end(matrix);
	matrix_string_yank(matrix, matrix->cursor->row, col);
	return (1);
}

int	yank_home(t_matrix *matrix)
{
	size_t col;

	col = get_cursor_pos_home(matrix);
	matrix_string_yank(matrix, matrix->cursor->row, col);
	return (1);
}
