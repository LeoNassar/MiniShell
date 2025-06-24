/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnassar <lnassar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 12:08:06 by lnassar           #+#    #+#             */
/*   Updated: 2025/02/19 22:29:52 by lnassar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <strings.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 32
# endif

typedef unsigned char		t_byte;
typedef unsigned int		t_uint;
typedef unsigned long long	t_llu;

typedef struct s_list
{
	void			*data;
	struct s_list	*next;
}	t_list;

typedef struct s_alloc
{
	t_list	*memory;
	t_list	*current;
	size_t	free_size;
	size_t	buffer_size;
}	t_alloc;

// ft_is
int		ft_isalnum(int c);
int		ft_isalpha(int c);
int		ft_isascii(int c);
int		ft_isdigit(int c);
int		ft_isfullspace(char *str);
int		ft_isprint(int c);

// ft_printf
size_t	print_base(ssize_t num, char *base, size_t base_len);
size_t	ft_putnbr_base(ssize_t nbr, char *base, size_t base_len, char spf);
int		ft_printchar(int c);
int		ft_printstr(char *str);
int		ft_formats(va_list args, const char format);
int		ft_printf(const char *str, ...);

// ft_put
void	ft_putchar_fd(char c, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
void	ft_putstr_fd(char *s, int fd);

// ft_str
int		ft_atoi(const char *str);
char	*ft_cl_join(char *s1, char *s2);
char	*ft_itoa(int nbr);
char	**ft_split(char const *s, char c);
char	*ft_strchr(const char *s, int c);
int		ft_strcmp(const char *str1, const char *str2);
char	*ft_strdup(const char *s1);
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlcat(char *dest, const char *src, size_t size);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t	ft_strlen(const char *str);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int		ft_strncmp(const char *s1, const char *s2, unsigned int n);
char	*ft_strnstr(const char *str, const char *to_find, size_t len);
char	*ft_strrchr(const char *s, int c);
char	*ft_strtrim(char const *s1, char const *set);
char	*ft_substr(char const *s, unsigned int start, size_t len);
int		ft_tolower(int c);
int		ft_toupper(int c);

// Memory
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t count, size_t size);
void	*ft_memchr(const void *s, int c, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
void	*ft_memcpy(void *dst, const void *src, size_t n);
void	*ft_memmove(void *dst, const void *src, size_t len);
void	*ft_memset(void *b, int c, size_t len);

// list
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstadd_front(t_list **lst, t_list *new);
void	ft_lstclear(t_list **lst, void (*del)(void*));
void	ft_lstdelone(t_list *lst, void (*del)());
void	ft_lstiter(t_list *lst, void (*f)());
t_list	*ft_lstlast(t_list *lst);
t_list	*ft_lstmap(t_list *lst, void *(*f)(), void (*del)());
t_list	*ft_lstnew(void *data);
t_uint	ft_lstsize(t_list *lst);

#endif
