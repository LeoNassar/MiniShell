/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnassar <lnassar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 00:39:39 by lnassar           #+#    #+#             */
/*   Updated: 2025/02/19 22:29:41 by lnassar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*tmp1;
	unsigned char	*tmp2;
	size_t			i;

	if (!dst && !src)
		return (NULL);
	tmp1 = (unsigned char *)src;
	tmp2 = (unsigned char *)dst;
	i = 0;
	if (dst > src)
		while (len-- > 0)
			tmp2[len] = tmp1[len];
	else
	{
		while (i < len)
		{
			tmp2[i] = tmp1[i];
			i++;
		}
	}
	return (dst);
}
