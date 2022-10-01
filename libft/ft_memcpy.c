/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smikayel <smikayel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 16:07:42 by smikayel          #+#    #+#             */
/*   Updated: 2022/03/16 11:37:42 by smikayel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void	*dst, const void *src, size_t n)
{
	unsigned char		*cpy;
	unsigned const char	*src_char;

	src_char = src;
	cpy = dst;
	while (n--)
	{
		*cpy = *src_char;
		src_char++;
		cpy++;
	}
	return (dst);
}
