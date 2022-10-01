/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smikayel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 14:38:36 by smikayel          #+#    #+#             */
/*   Updated: 2022/03/20 19:10:34 by smikayel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	index;
	size_t	index2;

	index = 0;
	index2 = 0;
	while (dst[index])
		index++;
	if (dstsize < index)
	{
		while (src[index2])
			index2++;
		return (dstsize + index2);
	}
	while (dstsize > 0 && index < dstsize - 1 && src[index2])
		dst[index++] = src[index2++];
	dst[index] = '\0';
	while (src[index2++])
		index++;
	return (index);
}
