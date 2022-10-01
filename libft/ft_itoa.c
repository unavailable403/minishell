/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smikayel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 14:18:22 by smikayel          #+#    #+#             */
/*   Updated: 2022/03/17 17:38:04 by smikayel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_rev_int_tab(char *tab, int size)
{
	int	i;
	int	k;

	i = 0;
	while (i < (size) / 2)
	{
		k = *(tab + i);
		*(tab + i) = *(tab + size - 1 - i);
		*(tab + size - 1 - i) = k;
		i++;
	}
}

static int	len_nbr(int nb)
{
	int	len;

	if (nb < 0)
		len = 1;
	else
		len = 0;
	while (nb != 0)
	{
		len ++;
		nb /= 10;
	}
	return (len);
}

static char	*loops(int nb)
{
	char	*arr;
	int		tmp;
	int		mod;

	mod = 1;
	arr = malloc(len_nbr(nb));
	tmp = 0;
	if (nb < 0)
	{
		nb *= -1;
		mod = -1;
	}
	while (nb != 0)
	{
		arr[tmp] = nb % 10 + '0';
		nb /= 10;
		tmp ++;
	}
	if (mod < 0)
		arr[tmp++] = '-';
	arr[tmp] = '\0';
	ft_rev_int_tab(arr, ft_strlen(arr));
	return (arr);
}

char	*ft_itoa(int n)
{
	char	*str_nb;

	if (n == 0)
		return (ft_strdup("0"));
	else if (n == -2147483648)
	{
		return (ft_strdup("-2147483648"));
	}
	else
	{
		str_nb = loops(n);
	}
	return (str_nb);
}
