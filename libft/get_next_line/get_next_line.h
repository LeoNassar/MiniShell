/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnassar <lnassar@student.42.fr>          +#+  +:+       +#+          */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 03:05:20 by lnassar          #+#    #+#              */
/*   Updated: 2024/11/22 03:05:20 by lnassar         ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 32
# endif

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>

void	*ft_gnl_memcpy(void *dest, const void *src, size_t n);
char	*ft_gnl_strdup(const char *s);
char	*ft_gnl_strchr(const char *string, int searchedChar);
size_t	ft_gnl_strlen(char *str);
char	*ft_gnl_strjoin(char *s1, char *s2);

char	*ft_read(int fd, char *stash);
char	*ft_line(char *temp);
char	*ft_rest_line(char *temp, char *line);
char	*get_next_line(int fd);

#endif