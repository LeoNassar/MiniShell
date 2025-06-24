/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnassar <lnassar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 10:40:50 by lnassar           #+#    #+#             */
/*   Updated: 2025/02/19 22:24:33 by lnassar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

#include <stdlib.h>

t_list	*ft_lstnew(void *data)
{
	t_list	*elt;

	elt = (t_list *)malloc(sizeof(*elt));
	if (!elt)
		return (NULL);
	elt->data = data;
	elt->next = NULL;
	return (elt);
}
