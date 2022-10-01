/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smikayel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 10:38:35 by smikayel          #+#    #+#             */
/*   Updated: 2022/03/25 15:46:30 by smikayel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub_str;
	size_t	i;
	size_t	s_len;

	i = 0;
	if (ft_strlen(s) < start)
	{
		sub_str = malloc(sizeof(char));
		sub_str[0] = '\0';
		return (sub_str);
	}
	s_len = ft_strlen(s + start);
	if (s_len < len)
		len = s_len;
	sub_str = (char *)malloc(len + 1);
	if (!sub_str)
		return (NULL);
	while (i < len)
	{
		sub_str[i] = s[start];
		start++;
		i++;
	}
	sub_str[i] = '\0';
	return (sub_str);
}
