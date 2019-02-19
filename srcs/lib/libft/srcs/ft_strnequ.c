/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwerewol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 17:49:18 by bwerewol          #+#    #+#             */
/*   Updated: 2019/02/19 13:00:37 by bwerewol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int	ft_strnequ(char const *s1, char const *s2, size_t n)
{
	if (!s1 || !s2)
		return (0);
	if (!n)
		return (1);
	while (*s1 == *s2 && *s1 && n > 1)
	{
		s1++;
		s2++;
		n--;
	}
	if (*s1 == *s2)
		return (1);
	return (0);
}
