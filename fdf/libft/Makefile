SRC = ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_itoa.c \
ft_isprint.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c ft_putchar_fd.c ft_split.c \
ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c ft_strchr.c ft_strdup.c ft_strjoin.c ft_strlcat.c \
ft_strlcpy.c ft_strlen.c ft_strmapi.c ft_strncmp.c ft_strnstr.c ft_strrchr.c ft_strtrim.c ft_substr.c \
ft_tolower.c ft_toupper.c ft_striteri.c \
			ft_printf.c \
			process_i.c \
			process_u.c \
			process_s.c \
			process_xcapx.c \
			process_p.c \
			ft_tools.c \
			process_d.c \
			get_next_line.c \
			get_next_line_utils.c
BONUS = ft_lstadd_back_bonus.c ft_lstadd_front_bonus.c ft_lstclear_bonus.c ft_lstdelone_bonus.c ft_lstiter_bonus.c \
ft_lstlast_bonus.c ft_lstmap_bonus.c ft_lstnew_bonus.c ft_lstsize_bonus.c
NAME = libft.a
OBJ = ${SRC:.c=.o}
OBJ_BONUS = ${BONUS:.c=.o}
FLAGS = -Wall -Werror -Wextra

all : $(NAME)
	@true

$(NAME) :
	gcc -I $(FLAGS) -c $(FLAGS) $(SRC)
	ar -rcs $(NAME) $(OBJ)

bonus :
	cc -I $(FLAGS) -c $(FLAGS) $(SRC) $(BONUS)
	ar -rcs $(NAME) $(OBJ) $(OBJ_BONUS)

clean :
	rm -f $(NAME)
	rm -rf $(OBJ) $(OBJ_BONUS)

fclean : clean

re : fclean all

dev :
	make fclean;git add .; git commit -m 'auto update';git push;cd ../libft-unit-test; make f;cd ../libft; make fclean

.PHONY : all clean fclean re mclean bonus dev
