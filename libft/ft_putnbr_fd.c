/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smikayel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 14:56:21 by smikayel          #+#    #+#             */
/*   Updated: 2022/03/17 20:58:16 by smikayel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char	*char_nb;

	if (!fd)
		return ;
	char_nb = ft_itoa(n);
	ft_putstr_fd(char_nb, fd);
	free(char_nb);
}
