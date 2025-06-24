/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnassar <lnassar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 17:26:52 by lnassar           #+#    #+#             */
/*   Updated: 2025/02/19 22:26:55 by lnassar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static	size_t	ft_countwords(const char s[], char c)
{
	size_t	count;
	size_t	i;

	i = 0;
	count = 0;
	if (!s || !s[0])
		return (0);
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i])
			count++;
		while (s[i] && s[i] != c)
			i++;
	}
	return (count);
}

char	**ft_split(char const *s, char c)
{
	char	**split;
	size_t	len;
	size_t	i;
	size_t	k;

	i = 0;
	k = 0;
	if (!s)
		return (NULL);
	split = (char **)malloc(sizeof(char *) * (ft_countwords(s, c) + 1));
	if (!split)
		return (NULL);
	while (s[k])
	{
		while (s[k] == c)
			k++;
		len = 0;
		while (s[k + len] && s[k + len] != c)
			len++;
		if (s[k])
			split[i++] = ft_substr(s, k, len);
		k += len;
	}
	split[i] = NULL;
	return (split);
}
