/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnassar <lnassar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 10:40:52 by lnassar           #+#    #+#             */
/*   Updated: 2025/02/19 22:24:38 by lnassar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

t_uint	ft_lstsize(t_list *lst)
{
	t_uint	i;	

	i = 0;
	while (lst)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}
