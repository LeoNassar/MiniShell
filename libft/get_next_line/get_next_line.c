/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnassar <lnassar@student.42.fr>          +#+  +:+       +#+          */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 20:18:13 by lnassar          #+#    #+#              */
/*   Updated: 2024/12/11 20:18:13 by lnassar         ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_read(int fd, char *stash)
{
	char	*buffer;
	int		nread;

	nread = 1;
	while (!ft_gnl_strchr(stash, '\n') && nread != 0)
	{
		buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (!buffer)
			return (NULL);
		nread = read(fd, buffer, BUFFER_SIZE);
		if ((!stash && nread == 0) || nread == -1)
			return (free(buffer), NULL);
		buffer[nread] = '\0';
		stash = ft_gnl_strjoin(stash, buffer);
	}
	return (stash);
}

char	*ft_line(char *temp)
{
	char	*line;
	int		i;

	if (!temp)
		return (NULL);
	i = 0;
	while (temp[i] != '\0' && temp[i] != '\n')
		i++;
	line = malloc(sizeof(char) * (i + 2));
	if (!line)
		return (NULL);
	i = -1;
	while (temp[++i] && temp[i] != '\n')
		line[i] = temp[i];
	line[i] = temp[i];
	if (temp[i] == '\n')
		++i;
	line[i] = '\0';
	return (line);
}

char	*ft_rest_line(char *temp, char *line)
{
	char	*rest;
	int		i;
	int		j;

	i = ft_gnl_strlen(line);
	if (!temp[i])
		return (free(temp), NULL);
	rest = malloc(sizeof(char) * (ft_gnl_strlen(temp) + 1));
	if (!rest)
		return (NULL);
	i = ft_gnl_strlen(line);
	j = 0;
	while (temp[i])
		rest[j++] = temp[i++];
	rest[j] = '\0';
	return (free(temp), rest);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line;
	char		*temp;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (free(stash), NULL);
	temp = ft_read(fd, stash);
	if (!temp)
	{
		if (stash)
			free(stash);
		stash = NULL;
		return (NULL);
	}
	line = ft_line(temp);
	stash = ft_rest_line(temp, line);
	return (line);
}
