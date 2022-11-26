/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smikayel <smikayel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 19:55:15 by ergrigor          #+#    #+#             */
/*   Updated: 2022/11/26 16:27:28 by smikayel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

t_cmd	*__final_struct_maker(t_element *elem1, t_element *elem2, t_element *elem3)
{
	t_cmd	*cmd;
	
	cmd = malloc(sizeof(t_cmd));
	// if (!(cmd || elem1 || elem2 || elem3))
	// 	return(("gago\n", NULL));
	cmd->element = elem1;
	cmd->prev = NULL;
	cmd->next = malloc(sizeof(t_cmd));
	cmd->next->element = elem2;
	cmd->next->prev = cmd;
	cmd->next->next = malloc(sizeof(t_cmd));
	cmd->next->next->prev = cmd->next;
	cmd->next->next->element = elem3;
	cmd->next->next->next = NULL;
	return(cmd);
}

t_element *__test_cmd(char *cmd1, char **args, int delim, int type)
{
	t_element	*elem;
	t_command	*command;

	elem = malloc(sizeof(t_element));
	
	if(cmd1 == NULL)
		command = NULL;
	else if(cmd1 != NULL)
	{
		command = __cmd_maker(cmd1, args);	
		if(!command || !elem)
			return(printf("malloc error\n"), NULL);
		elem->command = command;
	}
	elem->delimiter = delim;	
	elem->type = type;
	return (elem);	
}

t_command	*__cmd_maker(char *cmd1, char **args)
{
	t_command	*cmd;

	cmd = malloc(sizeof(t_command));
	if(!cmd)
		return(printf("malloc error\n"), NULL);
	cmd->cmd = cmd1;
	cmd->args = args;
	cmd->in = 0;
	cmd->out = 1;
	cmd->err = 2;
	cmd->hd = -1;
	cmd->hd_words = NULL;
	return(cmd);
}