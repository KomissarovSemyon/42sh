/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_free.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: narchiba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/08 13:11:17 by narchiba          #+#    #+#             */
/*   Updated: 2019/03/08 13:11:21 by narchiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "readline.h"
#include <stdlib.h>

void	line_free(t_line *line)
{
	if (line == NULL)
		return ;
	free(line->buf);
	free(line);
}
