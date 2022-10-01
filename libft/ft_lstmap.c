/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smikayel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 17:11:09 by smikayel          #+#    #+#             */
/*   Updated: 2022/03/21 17:37:55 by smikayel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f) (void *), void (*del)(void *))
{
	t_list	*new_lst;
	t_list	*tmp;

	new_lst = ft_lstnew(f(lst -> content));
	if (!new_lst)
		return (NULL);
	lst = lst -> next;
	while (lst)
	{
		tmp = ft_lstnew(f(lst->content));
		if (!tmp)
			ft_lstclear(&new_lst, del);
		ft_lstadd_back(&new_lst, tmp);
		lst = lst -> next;
	}
	return (new_lst);
}
