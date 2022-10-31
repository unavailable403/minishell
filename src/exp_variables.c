/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exp_variables.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ergrigor < ergrigor@student.42yerevan.am > +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 19:40:45 by ergrigor          #+#    #+#             */
/*   Updated: 2022/10/31 22:49:06 by ergrigor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	is_var(char **args)
{
	int	i;
	int	j;

	i = 0;
	if (!args)
		return (1);
	while (args[i])
	{
		j = 0;
		while (args[i][j])
		{
			if (args[i][0] != '\'')
				if (args[i][j] == '$' && args[i][j + 1] != ' '
					&& args[i][j + 1] != '\0')
					return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	get_var_env_value(t_env *env, char **name)
{
	t_env	*ptr;

	ptr = env;
	while (ptr)
	{
		if (ft_strncmp(ptr->val_name, *name, ft_strlen(*name)) == 0)
			break ;
		else
			ptr = ptr->next;
	}
	free(*name);
	if (ptr && ft_strncmp(ptr->val_name, *name, ft_strlen(*name)) == 0)
		*name = ft_strdup(ptr->val_value);
	else
		*name = ft_strdup("");
}

void	change_var(t_env *env, char **args, int i, int *j)
{
	char	*name;
	char	*f_arg;
	char	*tmp;
	int		x;

	x = *j;
	while (args[i][x] && args[i][x] != ' ' && args[i][x] != '\0'
		&& args[i][x] != '"')
		x++;
	x--;
	name = ft_substr(args[i], ((*j) + 1), (x - (*j)));
	get_var_env_value(env, &name);
	f_arg = ft_substr(args[i], 0, *j);
	f_arg = ft_free_strjoin(f_arg, name);
	tmp = ft_substr(args[i], (x + 1), (ft_strlen(args[i]) - x));
	f_arg = ft_free_strjoin(f_arg, tmp);
	free(tmp);
	free(name);
	free(args[i]);
	args[i] = ft_strdup(f_arg);
	free(f_arg);
	// printf("%s\n",args[i]);
	// exit(0);
}

void	get_var(t_env *env, char **args)
{
	int	i;
	int	j;

	i = 0;
	while (args[i])
	{
		j = 0;
		while (args[i][j])
		{
			if (args[i][0] != '\'')
				if (args[i][j] == '$' && args[i][j + 1] != ' '
					&& args[i][j + 1] != '\0')
					change_var(env, args, i, &j);
			j++;
		}
		i++;
	}

}

void	get_new_args(char **new, t_command *command)
{
	int		i;
	int		new_i;
	int		args_i;
	char	**new_args;

	args_i = 1;
	new_i = 0;
	i = 0;
	while (new[new_i])
		new_i++;
	while (command->args[args_i])
		args_i++;
	new_args = ft_calloc((1 + new_i + args_i), sizeof(char *));
	args_i = 1;
	new_i = 0;
	while (new[new_i])
		new_args[i++] = ft_strdup(new[new_i++]);
	//printf("GAGO\n");
	free(command->args[0]);
	while (command->args[args_i])
	{
		new_args[i++] = ft_strdup(command->args[args_i]);
		free(command->args[args_i++]);
	}
	free(command->args);
	command->args = new_args;
}

void	join_option(t_command *command)
{
	int		i;
	int		j;
	char	**new;

	i = 0;
	while (command->args[0][i])
	{
		if (command->args[0][i] == ' ')
		{
			new = ft_split(command->args[0], ' ');
			get_new_args(new, command);
			break ;
		}
		else
			i++;
	}
}

void	remove_option(t_command *command)
{
	int		i;
	char	*new_cmd;

	i = 0;
	while (command->cmd[i] && command->cmd[i] != ' ')
		i++;
	new_cmd = ft_substr(command->cmd, 0, i);
	free(command->cmd);
	command->cmd = new_cmd;
}

void	get_variables(t_env *env, t_element **elem)
{
	int	i;

	i = 0;
	while (elem[i])
	{
		//printf("\n%d\n", is_var(elem[i]->command->args));
		if (is_var(&elem[i]->command->cmd) == 0)
		{
			get_var(env, &elem[i]->command->cmd);
			remove_option(elem[i]->command);
			print_elem(elem[i]);
		}
		if (is_var(elem[i]->command->args) == 0)
		{
			get_var(env, elem[i]->command->args);
			join_option(elem[i]->command);
			print_elem(elem[i]);
		}
		else
		{
			i++;
			// printf("tamama\n");
			break ;
		}
	}
}
