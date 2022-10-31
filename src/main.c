/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ergrigor < ergrigor@student.42yerevan.am > +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 16:30:31 by ergrigor          #+#    #+#             */
/*   Updated: 2022/10/31 19:36:08 by ergrigor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	main(int argc, char **argv, char **_env)
{
	char		*cmd_line;
	int			*tokenized_line;
	t_env		*env;
	t_element	**elem;

	env = pars_env(_env);
	while (1)
	{
		cmd_line = readline("Say - Hello myalmo > ");
		if (empty_line(cmd_line) != 1)
			add_history(cmd_line);
		if (first_checker(cmd_line) == 0 && empty_line(cmd_line) == 0)
		{
			tokenized_line = tokenization(cmd_line);
			elem = cmd_init(cmd_line, tokenized_line);
			get_variables(env, elem);
		}
		// lexer(&all_cmd);
	}
	return (0);
}
