/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ergrigor < ergrigor@student.42yerevan.am > +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 16:33:14 by ergrigor          #+#    #+#             */
/*   Updated: 2022/10/13 20:36:19 by ergrigor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

//error
# include "error.h"
// libs
# include "tokens.h"
# include <stdio.h>
# include <errno.h>
# include <stdlib.h>
# include <limits.h>
# include <unistd.h>
# include "../libft/libft.h"
# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>

typedef struct s_command
{
	char	*cmd;
	char	*path;
	char	**args;
	int		in;
	int		out;
	int		err;
	int		hd;
	char	**hd_words;
}			t_command;

typedef struct s_element
{
	t_command	*command;
	int			delimiter;
	int			type;
}				t_element;

// token types -> | & ; () < > SPACE TAB NEWLINE  {1..8}
// int type 0 -> is word, int type{1..8} is token
typedef struct s_token	t_token;
struct s_token
{
	char			*word;
	int				type;
	t_token			*next;
} ;

typedef struct s_cmd
{
	t_element			*element;
	int					exec_mode;
	int					status;
	struct s_cmd		*next;
	struct s_cmd		*prev;
}				t_cmd;

typedef struct s_env
{
	char			*val_name;
	char			*val_value;
	struct s_env	*next;
	struct s_env	*prev;
}				t_env;


/*
** TEST
*/

t_cmd	*__final_struct_maker(t_element *elem1, t_element *elem2, t_element *elem3);
t_element *__test_cmd(char *cmd1, char **args, int delim, int type);
t_command	*__cmd_maker(char *cmd, char **args);

//tokenization
int		first_checker(char *cmd_line);
t_token	*tokenization(char *cmd_line);
void	quot_editor(int *arr, int len);
//void	ft_tokadd_back(t_token **tok, t_token *new);
//utils
char	*ft_str_start_trim(char const *s1, char const *set);


//env 
t_env *pars_env(char **env);
int get_env_var_count(t_env *l_env);
static char *get_val(char *env_line);
int get_env_var_count(t_env *l_env);
char *get_line_env(t_env *l_env);
char **get_arr_env(t_env *l_env);

#endif
