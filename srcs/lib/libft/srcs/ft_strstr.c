/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwerewol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 17:43:46 by bwerewol          #+#    #+#             */
/*   Updated: 2019/02/27 12:51:34 by nkertzma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strstr(const char *haystack, const char *needle)
{
	size_t i;

	if (!needle || !haystack)
		return (NULL);
	while (*haystack)
	{
		i = 0;
		while (haystack[i] == needle[i])
		{
			if (!needle[i + 1])
				return ((char *)haystack);
			i++;
		}
		haystack++;
	}
	return (NULL);
}
