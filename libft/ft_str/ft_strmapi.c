/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnassar <lnassar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 17:26:59 by lnassar           #+#    #+#             */
/*   Updated: 2025/02/19 22:28:08 by lnassar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	i;
	char	*result;

	i = ft_strlen(s);
	result = malloc(i + 1);
	if (result)
	{
		result[i] = 0;
		while (i--)
			result[i] = (*f)(i, s[i]);
	}
	return (result);
}
