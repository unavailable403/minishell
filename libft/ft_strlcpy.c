/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smikayel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 14:29:14 by smikayel          #+#    #+#             */
/*   Updated: 2022/03/12 14:31:12 by smikayel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char*src, size_t dstsize)
{
	size_t	len;

	if (!dst || !src)
		return (0);
	len = ft_strlen((char *)src);
	if (!dstsize)
		return (len);
	if (len >= dstsize)
	{
		ft_memcpy(dst, src, dstsize - 1);
		dst[dstsize - 1] = '\0';
	}
	else
		ft_memcpy(dst, src, len + 1);
	return (len);
}
