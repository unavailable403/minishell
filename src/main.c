/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ergrigor < ergrigor@student.42yerevan.am > +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 16:30:31 by ergrigor          #+#    #+#             */
/*   Updated: 2022/10/10 22:00:46 by ergrigor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/main.h"

int	main(void)
{
	char	*cmd_line;
	t_token	*tok_line;

	while (1)
	{
		cmd_line = readline("Say - Hello myalmo > ");
		//cmd_line = ft_str_start_trim(readline("Say - Hello myalmo > "), "\t ");
		if (cmd_line != NULL && cmd_line[0] != '\0')
			add_history(cmd_line);
		if (first_checker(cmd_line) == 0 && cmd_line[0] != '\0')
		{
			tok_line = tokenization(cmd_line);
		}
	}
	return (0);
}
