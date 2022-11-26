/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smikayel <smikayel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 16:30:31 by ergrigor          #+#    #+#             */
/*   Updated: 2022/11/26 18:42:24 by smikayel         ###   ########.fr       */
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

char *get_cmd_name_from_path(char *cmd_path)
{
	int i;
	char **split_path;

	i = 0;
	split_path = ft_split(cmd_path, '/');
	if (split_path == NULL)
		return NULL;
	while (split_path[i] != NULL)
	{
		i++;
	}
	if (i > 0)
		return (split_path[i - 1]);
	return (split_path[i]);
}

int check_in_builtins(t_cmd **cmd_pointer)
{
	char *path;
	t_cmd *cmd;
	char *cmd_name;

	cmd = *cmd_pointer;
	cmd_name = cmd->element->command->cmd;

	if (strcmp(cmd_name, ECHO) != 0 && strcmp(cmd_name, CD) != 0 &&
	strcmp(cmd_name, EXPORT) != 0 && strcmp(cmd_name, UNSET) != 0 && 
	strcmp(cmd_name, ENV) != 0 && strcmp(cmd_name, EXIT) != 0)
	{
		cmd->status = 127;
		return (-1);
	}
	cmd->status = 0;
	return (1);
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
			if (access(tmp_path, R_OK) == 0)
			{
				if (access(tmp_path, X_OK) == 0)
				{
					cmd->element->command->path = tmp_path;
					cmd->status = 0;
					return (1);
				}
				else 
					cmd->status = 126;
			}
			else
				cmd->status = 127;
			if (access(cmd->element->command->cmd, R_OK) == 0)
			{
				if (access(cmd->element->command->cmd, X_OK) == 0)
				{
					cmd->element->command->path = cmd->element->command->cmd;
					cmd->element->command->cmd = get_cmd_name_from_path(cmd->element->command->path);
					cmd->status = 0;
					return (1);
				}
				else 
					cmd->status = 126;
			}
			else 
				cmd->status = 127;
		}
		else
			return (-1);
		i++;
		free(tmp_path);
	}
	return check_in_builtins(cmd_pointer);
}

void lexer(t_cmd **cmd_pointer, t_env *env)
{
	t_cmd *cmd;
	t_cmd *cmd_start;
	t_env *path;
	char **separated_paths;
	int for_mode;

	cmd = *cmd_pointer;
	cmd_start = cmd;
	for_mode = 0;
	path = get_value_from_env(env, "PATH");
	if (path && path->val_value && *(path->val_value))
	{
		separated_paths = ft_split(path->val_value, ':');
		while (cmd)
		{
			if (check_cmd_in_path(&cmd, separated_paths) == -1)
			{
				cmd->status = 127;
			}
			cmd = cmd->next;
		}
	}
	else 
	{
		while (cmd)
		{
			if (access(cmd->element->command->cmd, R_OK) == 0)
			{
				if (access(cmd->element->command->cmd, X_OK) == 0)
				{
					cmd->element->command->path = cmd->element->command->cmd;
					cmd->element->command->cmd = get_cmd_name_from_path(cmd->element->command->path);
					cmd->status = 0;
				}
				else 
					cmd->status = 126;
			}
			else 
				cmd->status = 127;
			cmd = cmd->next;
		}
		if (check_in_builtins(cmd_pointer) == -1)
			cmd->status = 127;
	}
}



void print_error_out_and_exit(char *msg, int out_fd)
{
	write(out_fd, msg, strlen(msg));
	exit(out_fd);
}

pid_t	fork_checking(t_cmd **cmd)
{
	pid_t	proces_id;
	t_cmd *command;

	command = *cmd;
	proces_id = fork();
	if (proces_id < 0)
		print_error_out_and_exit("Can not fork: Terminal allocation crushed!", command->element->command->out);
	return (proces_id);
}


void	run_command_one(t_cmd **command, char **env)
{
	t_cmd *cmd;

	cmd = *command;
	printf("\n\n\n\n\n\naaaassste;jwjegjgf\n");
	dup2(cmd->element->command->out, 1);
	close(cmd->element->command->out);
	// close(cmd->element->command->in);
	dup2(cmd->element->command->in, 0);
	close(cmd->element->command->in);
	if (execve(cmd->element->command->path, cmd->element->command->args, env) == -1)
		exit(cmd->element->command->out);
}

void cmd_exec_error(t_cmd	*cmd_p)
{
	if (cmd_p->element->type == 2)
		return ;
	if (cmd_p->status == 126)
		write(cmd_p->element->command->out, "Permissions denied!", strlen("Permissions denied!"));
	else if (cmd_p->status == 127)
		write(cmd_p->element->command->out, "Command not found!", strlen("Command not found!"));
}

int	execute_just_one(t_env **env, t_cmd **cmd)
{
	t_cmd	*cmd_p;
	pid_t	process_id;
	int		status;

	cmd_p = *cmd;
	if (cmd_p->element->type != 2 && (cmd_p->status != 127 || cmd_p->status != 126))
	{
		process_id = fork_checking(cmd); // will fork proccess and return proccess id
		if (process_id == 0)
			run_command_one(cmd,  get_arr_env(*env));	
		else
		{
			waitpid(process_id, &status, WUNTRACED | WCONTINUED); // need to change the place where it needs to be 
			/*as we can get the situation when our secund cmd will wait to this but hey need to work in the same time not waiting to each other,
			so seems to change waiting (need to check maybe with just one command it's normal)*/
			cmd_p->status = status;
		}
	}
	else
		cmd_exec_error(cmd_p);
	
	// proc->child2 = fork_checking();
	// if (proc->child2 == 0)
	// 	run_command_two(proc, commands->sec->cmd_path, argv[3], env);
	// close_pipe_to_ends(proc->pip_in_out);
	// wait_process(proc->child1, proc->child2);
	// free_structs(commands, proc);
	return (0);
}

void execute_with_and(t_env **env, t_cmd **cmd_pointer)
{
	t_cmd *cmd;
	t_cmd *first_cmd;
	t_cmd *secund_cmd;

	cmd = *cmd_pointer;
	first_cmd = cmd;
	secund_cmd = cmd->next->next;
	printf("%s\n", cmd->element->command->cmd);
	printf("%s\n",	secund_cmd->element->command->cmd);
	// execute command with and ( && )
	execute_just_one(env, &first_cmd);
	if (first_cmd->status == 0)
		execute_just_one(env, &secund_cmd);
	else
		return ;
}

void executer(t_cmd **cmd_pointer, t_env *env)
{
	t_cmd *cmd;

	cmd = *cmd_pointer;
	// if one command
	if (!cmd->next)
		execute_just_one(&env, cmd_pointer);
	// more then one command with delimitors
	else
	{

		while (cmd)
		{
			if (strcmp(cmd->element->command->cmd, "&&") == 0)
			{
				printf("GAAAAG\n");
				execute_with_and(&env, cmd_pointer);	
				// need to go to next next next 
			}
			cmd = cmd->next;
		}
	}
		// printf("yeh just one command\n"); // need function witch will execute just one command 
	// if 2 or more commands
		// check or 
		// check and 
		// check pipe
	// printf("sorry I didn't know how to run this yet\n");
}


int	main(int argc, char **argv, char **envp)
{
	char	*cmd_line;
	t_cmd		*cmd;
	t_element	*elem;
	t_element	*elem1;
	t_element	*elem2;
	t_env *env;

	elem = malloc(sizeof(t_element));
	elem1 = malloc(sizeof(t_element));
	elem2 = malloc(sizeof(t_element));

	elem->command = malloc(sizeof(t_command));
	elem->type = 0;
	elem->command->cmd = ft_strdup("ls");
	elem->command->args = malloc(3 * sizeof(char *));
	elem->command->args[0] = ft_strdup("ls");
	elem->command->args[1] = ft_strdup("-la");
	elem->command->args[2] = NULL;
	elem->command->err = 2;
	elem->command->out = 1;
	elem->command->in = 0;
	elem->command->err = 2;
	elem->command->out = 1;


	elem1->command = malloc(sizeof(t_command));
	elem->type = 1;
	elem1->command->cmd = ft_strdup("&&");
	elem1->command->args = NULL;
	elem1->command->in = 0;
	elem1->command->err = 2;
	elem1->command->out = 1;

	elem2->command = malloc(sizeof(t_command));
	elem->type = 0;
	elem2->command->cmd = ft_strdup("echo");
	elem2->command->args = malloc(3 * sizeof(char *));
	elem2->command->args[0] = ft_strdup("echo");
	elem2->command->args[1] = ft_strdup("pxik ev dzknik");
	elem2->command->args[2] = NULL;
	elem2->command->err = 2;
	elem2->command->out = 1;
	elem2->command->in = 0;
	elem2->command->err = 2;
	elem2->command->out = 1;

	cmd = malloc(sizeof(t_cmd));
	cmd->element = elem;
	cmd->next = malloc(sizeof(t_cmd));
	cmd->next->element = elem1;
	cmd->next->next = malloc(sizeof(t_cmd));
	cmd->next->next->element = elem2;
	printf("%s\n", cmd->next->next->element->command->cmd);
	// char *cmd1;
	// char *cmd_delimiter;
	// char *cmd2;
	// char **args;
	// char **args_and;
	// char **args1;
	
	// cmd1 = ft_strdup("ls");
	// cmd_delimiter = ft_strdup("&&");
	// cmd2 = ft_strdup("echo");
	
	// args = malloc(4 * sizeof(char *));
	// args[0] = ft_strdup("ls");
	// args[1] = ft_strdup("-l");
	// args[2] = ft_strdup("-a");
	// args[3] = NULL;

	// args_and = malloc(4 * sizeof(char *));
	// args_and[0] = ft_strdup("&&");
	// args_and[1] = NULL;

	// args1 = malloc(4 * sizeof(char *));
	// args1[0] = ft_strdup("echo");
	// args1[1] = ft_strdup("-n");
	// args1[2] = ft_strdup("asdsa ds df sa");
	// args1[3] = NULL;

	// elem = __test_cmd(cmd1, args, -1, 1);
	// elem_and = __test_cmd(cmd1, args, -1, 1);
	// elem1= __test_cmd(cmd2, args1, -1, 1);
	// elem2 = __test_cmd(NULL, NULL, AND_OR, 2);
	// cmd = __final_struct_maker(elem, elem1, elem2);
	// cmd->element->command->cmd = cmd1;
	// cmd->element->command->in = 4; //just  for tests
	// cmd->element->command->out = 5; // just test 2
	
	// cmd->next->element->command->cmd = cmd2;
	// cmd->next = NULL;
	// cmd = cmd->next;
	// printf("%s\n", cmd->element->command->cmd);
	// printf("%s\n", cmd->next->element->command->cmd);
	env = pars_env(envp); // env in format env _t 	
	lexer(&cmd, env);  /* checking if cmd not found, also setting the command path witch will help to execute the command 
	 in case when the command is builtin it will just check and set the cmd status 0, overview it will set to 127 (IF COMMAND NOT FOUND AND 126 if there is not enough
	 permissions)
	*/
	executer(&cmd, env); /*this is executer function here will be cheeked that if next cmd element type is pipe/and/or will called function what is needed*/

	// this is for just testing command status 
	// printf("\n\n\n\n");
	while (cmd->next)
	{
		printf("cmd : %s, status: %d , path: %s\n", cmd->element->command->cmd, cmd->status, cmd->element->command->path);
		cmd = cmd->next;
	}
	// executer(cmd__pointer);
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
