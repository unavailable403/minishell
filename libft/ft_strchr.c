/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smikayel <smikayel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 12:44:54 by smikayel          #+#    #+#             */
/*   Updated: 2022/03/18 15:28:38 by smikayel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	unsigned char	tar;

	if (!c)
		return ((char *)str + ft_strlen(str));
	tar = c;
	while (*str)
	{
		if (*str == tar)
			return ((char *)str);
		else if (!*str++)
			return (0);
	}
	return (0);
}
