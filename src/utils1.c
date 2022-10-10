/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ergrigor < ergrigor@student.42yerevan.am > +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 20:38:59 by ergrigor          #+#    #+#             */
/*   Updated: 2022/10/10 20:42:21 by ergrigor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

static int	first_set_count(char const *str, char const *set)
{
	int	index;
	int	count;

	index = 0;
	count = 0;
	while (set[index])
	{
		if (set[index] == *str)
		{
			index = 0;
			count++;
			str++;
		}
		else
			index++;
	}
	return (count);
}

char	*ft_str_start_trim(char const *s1, char const *set)
{
	size_t	lenght;
	size_t	start;
	size_t	str_len;
	char	*str;

	if (!*set || (first_set_count(s1, set) == 0))
	{
		str = ft_strdup(s1);
		return (str);
	}
	start = first_set_count(s1, set);
	lenght = ft_strlen(s1) - start;
	str = ft_substr(s1, start, lenght);
	str_len = ft_strlen(str);
	str[str_len] = '\0';
	return (str);
}
