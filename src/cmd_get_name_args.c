/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_get_name_args.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ergrigor < ergrigor@student.42yerevan.am > +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 18:38:51 by ergrigor          #+#    #+#             */
/*   Updated: 2022/10/18 18:54:23 by ergrigor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	get_cmd_name(int *i, int *arr, t_element *elem, char *line)
{
	int	x;

	x = *i;
	while (arr[x] != SPACE)
		x++;
	x--;
	elem->command->cmd = ft_substr(line, *i, (x - (*i)));
}

void	get_cmd_args(int *i, int *arr, t_element *elem, char *line)
{
	int	size;

	skip_spaces(i, arr);
	if (arr[*i] == PIPE || arr[*i] == AND_OR || arr[*i] == OR_IF)
		return ;
	size = arg_counter(i, arr);
	elem->command->args = ft_calloc(size + 1, sizeof(char *));
	return ;
}