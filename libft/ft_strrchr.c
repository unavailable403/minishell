/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smikayel <smikayel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 13:05:59 by smikayel          #+#    #+#             */
/*   Updated: 2022/03/16 13:37:32 by smikayel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;
	char	*last;

	i = ft_strlen(s);
	last = (char *)s;
	while (i > 0)
	{
		if (last[i] == (char)c)
			return (last + i);
		i--;
	}
	if (last[i] == (char)c)
		return ((char *)last);
	return (NULL);
}
