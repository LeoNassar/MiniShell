NAME 		= libft.a
CC 			= cc
CFLAGS 		+= -Wall -Wextra -Werror
SRC			=	ft_str/ft_atoi.c \
				memory/ft_bzero.c \
				memory/ft_calloc.c \
				ft_is/ft_isalnum.c \
				ft_is/ft_isalpha.c \
				ft_is/ft_isascii.c \
				ft_is/ft_isdigit.c \
				ft_is/ft_isprint.c \
				memory/ft_memchr.c \
				memory/ft_memcmp.c \
				memory/ft_memcpy.c \
				memory/ft_memmove.c \
				memory/ft_memset.c \
				ft_str/ft_strchr.c \
				ft_str/ft_strdup.c \
				ft_str/ft_strlcat.c \
				ft_str/ft_strlcpy.c \
				ft_str/ft_strlen.c \
				ft_str/ft_strncmp.c \
				ft_str/ft_strnstr.c \
				ft_str/ft_strrchr.c \
				ft_str/ft_tolower.c \
				ft_str/ft_toupper.c \
				ft_str/ft_strcmp.c \
				ft_str/ft_itoa.c \
				ft_put/ft_putchar_fd.c \
				ft_put/ft_putendl_fd.c \
				ft_put/ft_putnbr_fd.c \
				ft_put/ft_putstr_fd.c \
				ft_str/ft_strmapi.c \
				ft_str/ft_strtrim.c \
				ft_str/ft_strjoin.c \
				ft_str/ft_substr.c \
				ft_str/ft_striteri.c \
				ft_str/ft_split.c \
				ft_str/ft_cl_join.c \
				ft_is/ft_isfullspace.c \
				ft_lst/ft_lstadd_back.c \
				ft_lst/ft_lstadd_front.c \
				ft_lst/ft_lstclear.c \
				ft_lst/ft_lstdelone.c \
				ft_lst/ft_lstiter.c \
				ft_lst/ft_lstlast.c \
				ft_lst/ft_lstmap.c \
				ft_lst/ft_lstnew.c \
				ft_lst/ft_lstsize.c \

OBJ 		= $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	ar crs $(NAME) $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY:		all clean fclean re