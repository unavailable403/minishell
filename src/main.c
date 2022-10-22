/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ergrigor < ergrigor@student.42yerevan.am > +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 16:30:31 by ergrigor          #+#    #+#             */
/*   Updated: 2022/10/13 21:20:39 by ergrigor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

t_env *get_value_from_env(t_env *env, char *name)
{
	while (env)
	{
		if (strcmp(env->val_name, name) == 0)
			return (env);
		env = env->next;
	}
	return NULL;
}

int check_cmd_in_path(t_cmd **cmd_pointer, char **separated_paths)
{
	t_cmd *cmd;
	char *tmp_path;
	char *tmp;
	int i;

	cmd = *cmd_pointer;
	i = 0;
	while (separated_paths[i])
	{
		if (cmd->element->type == 1)
		{
			tmp_path = ft_strjoin(separated_paths[i], "/");
			tmp_path =  ft_strjoin(tmp_path, cmd->element->command->cmd);
			if (access(tmp_path, X_OK | R_OK) == 0)
			{
				cmd->element->command->path = tmp_path;
				return (1);
			}
		}
		else 
			return (0);
		i++;
		free(tmp_path);
	}
	cmd->element->command->path = NULL;
	return (-1);
}


void lexer(t_cmd **cmd_pointer, t_env *env)
{
	t_cmd *cmd;
	t_cmd *cmd_start;
	t_env *path;
	char **separated_paths;

	cmd = *cmd_pointer;
	cmd_start = cmd;
	path = get_value_from_env(env, "PATH");
	if (path->val_value && *(path->val_value))
	{
		separated_paths = ft_split(path->val_value, ':');
		while (cmd)
		{
			printf("%d\n",check_cmd_in_path(&cmd, separated_paths));
			cmd = cmd->next;
		}
	}
	// printf("%s\n", path->val_value);
	// if (!path)

}



int	main(int argc, char **argv, char **envp)
{
	char	*cmd_line;
	t_cmd		*cmd;
	t_element	*elem;
	t_element	*elem1;
	t_element	*elem2;
	t_env *env;
	char *cmd1;
	char *cmd2;
	char **args;
	char **args1;
	
	cmd1 = ft_strdup("ls");
	cmd2 = ft_strdup("echo");
	
	args = malloc(4 * sizeof(char *));
	args[0] = ft_strdup("ls");
	args[1] = ft_strdup("-l");
	args[2] = ft_strdup("-a");
	args[3] = NULL;

	args1 = malloc(4 * sizeof(char *));
	args1[0] = ft_strdup("echo");
	args1[1] = ft_strdup("-n");
	args1[2] = ft_strdup("asdsa ds df sa");
	args1[3] = NULL;

	elem = __test_cmd(cmd1, args, -1, 1);
	elem1 = __test_cmd(NULL, NULL, AND_OR, 2);
	elem2 = __test_cmd(cmd2, args1, -1, 1);
	cmd = __final_struct_maker(elem, elem1, elem2);
	
	printf("%s\n", cmd->element->command->args[0]);
	env = pars_env(envp);
	lexer(&cmd, env);
	// while (1)
	// {
	// 	cmd_line = readline("Say - Hello myalmo > ");
	// 	// cmd_line = ft_str_start_trim(readline("Say - Hello myalmo > "), "\t ");
	// 	if (cmd_line != NULL && cmd_line[0] != '\0')
	// 		add_history(cmd_line);
	// 	if (first_checker(cmd_line) == 0 && cmd_line[0] != '\0')
	// 	{
	// 		tok_line = tokenization(cmd_line);
	// 	}
	// }
	return (0);
}
