/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smikayel <smikayel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 12:32:00 by smikayel          #+#    #+#             */
/*   Updated: 2022/03/10 19:19:44 by smikayel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isdigit(int tmp)
{
	int	is_numeric;

	is_numeric = 1;
	if (tmp > 57 || tmp < 48)
	{
		is_numeric = 0;
		return (is_numeric);
	}
	return (is_numeric);
}
