/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ergrigor < ergrigor@student.42yerevan.am > +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 16:30:31 by ergrigor          #+#    #+#             */
/*   Updated: 2022/10/08 23:29:22 by ergrigor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/main.h"

int	main(void)
{
	char	*cmd_line;

	while (1)
	{
		cmd_line = readline("Say - Hello myalmo > ");
		add_history(cmd_line);
		if (first_checker(cmd_line) == 0)
		{
			printf("pay dzec, dzec\n");
		}
	}
	return (0);
}
