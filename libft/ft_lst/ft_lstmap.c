/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnassar <lnassar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 10:40:48 by lnassar           #+#    #+#             */
/*   Updated: 2025/02/19 22:24:28 by lnassar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(), void (*del)())
{
	t_list	*root;
	t_list	**current;
	void	*data;

	root = NULL;
	current = &root;
	while (lst)
	{
		data = f(lst->data);
		*current = ft_lstnew(data);
		if (!*current)
		{
			ft_lstclear(&root, del);
			if (del)
				del(data);
			return (NULL);
		}
		current = &(*current)->next;
		lst = lst->next;
	}
	return (root);
}
