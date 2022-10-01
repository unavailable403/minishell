/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smikayel <smikayel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 12:17:26 by smikayel          #+#    #+#             */
/*   Updated: 2022/03/10 19:19:10 by smikayel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isalpha(int tmp)
{
	int	is_alpha;

	is_alpha = 1;
	if (tmp < 65 || (tmp > 90 && tmp < 97) || tmp > 122)
	{
		is_alpha = 0;
		return (is_alpha);
	}
	return (is_alpha);
}
