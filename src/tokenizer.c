/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ergrigor < ergrigor@student.42yerevan.am > +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 14:35:44 by ergrigor          #+#    #+#             */
/*   Updated: 2022/10/09 22:18:50 by ergrigor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	ft_tokadd_back(t_token **tok, t_token *new)
{
	t_token	*iter;

	if (tok == NULL || new == NULL)
		return ;
	if (*tok == NULL)
	{
		*tok = new;
		return ;
	}
	iter = *tok;
	while (iter -> next != NULL)
		iter = iter -> next;
	iter -> next = new;
}

t_token	*ft_toknew(char *content)
{
	t_token	*new;

	new = malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new->word = content;
	new->type = -1;
	new->next = NULL;
	return (new);
}

void	fnorm_tokenizer2(char *cmd_line, int *arr, int len, int *i)
{
	while (cmd_line[*i] && *i < len)
	{
		if (cmd_line[*i] == '"')
			arr[*i] = DOUBLE_QUOTES;
		else if (cmd_line[*i] == '\'')
			arr[*i] = SINGLE_QUOTES;
		else if (cmd_line[*i] == '|' && cmd_line[(*i) + 1] == '|')
		{
			arr[(*i)++] = OR_IF;
			arr[(*i)] = OR_IF;
		}
		else
			arr[*i] = WORD;
		break ;
	}
}

void	fnorm_tokenizer(char *cmd_line, int *arr, int len, int *i)
{
	while (cmd_line[*i] && *i < len)
	{
		if (cmd_line[*i] == '>' && cmd_line[(*i) + 1] == '>')
		{
			arr[(*i)++] = RED_OUTPUT_APP;
			arr[(*i)] = RED_OUTPUT_APP;
		}
		else if (cmd_line[*i] == '<' && cmd_line[(*i) + 1] == '<')
		{
			arr[(*i)++] = HERE_DOC;
			arr[(*i)] = HERE_DOC;
		}
		else if (cmd_line[*i] == '&' && cmd_line[(*i) + 1] == '&')
		{
			arr[(*i)++] = AND_OR;
			arr[(*i)] = AND_OR;
		}
		else
			fnorm_tokenizer2(cmd_line, arr, len, i);
		break ;
	}
}

void	tokenizer(char *cmd_line, int *arr, int len)
{
	int	i;

	i = 0;
	while (cmd_line[i] && i < len)
	{
		if (cmd_line[i] == ' ')
			arr[i] = SPACE;
		else if (cmd_line [i] == '|' && cmd_line[i + 1] != '|')
			arr[i] = PIPE;
		else if (cmd_line [i] == ';')
			arr[i] = DOT_COMMA;
		else if (cmd_line [i] == '(')
			arr[i] = L_SCOPE;
		else if (cmd_line [i] == ')')
			arr[i] = R_SCOPE;
		else if (cmd_line [i] == '<' && cmd_line[i + 1] != '<')
			arr[i] = RED_INPUT;
		else if (cmd_line [i] == '>' && cmd_line[i + 1] != '>')
			arr[i] = RED_OUTPUT;
		else
			fnorm_tokenizer(cmd_line, arr, len, &i);
		i++;
	}
}

t_token	*tokenization(char *cmd_line)
{
	t_token	*tok_line;
	int		*arr;
	int		i;
	int		len;

	i = 0;
	len = ft_strlen(cmd_line);
	arr = malloc (len * sizeof(int));
	tokenizer(cmd_line, arr, len);
	// while (i < len)
	// 	printf(" [%d] ", arr[i++]);
	// printf("\n");
	//exit(1);
	// tok_line = malloc((sizeof(tok_line) * i) + 1);
	// if (!tok_line)
	// 	return (NULL);
	// tok_line[i] = 0x0;
	// i = 0;
	// while (line[i])
	// {
	// 	//printf("%s\n",line[i]);
	// 	tok_line[i]->word = ft_strdup("gago\n");
	// 	i++;
	// 	printf("%d\n", i);
	// 	//free(line[i]);
	// }
	// //free(line);
	// //printf("%s\n", tok_line[0]->word);
	return (NULL);
}
