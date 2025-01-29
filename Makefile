NAME = libftprintf.a

CC = cc
WFLAGS = -Wall -Wextra -Werror

SOURCE = ft_count_char.c ft_itoa_unsigned.c ft_itoa.c ft_print_address.c ft_print_hex.c ft_printf.c \
		ft_putchar.c ft_putstr.c
OBJECT = $(SOURCE:.c=.o)

HEADER = ft_printf.h

AR = ar
ARFLAGS = -rcs

RM = rm -f

all : $(NAME)

$(NAME) : $(OBJECT)
	$(AR) $(ARFLAGS) $(NAME) $(OBJECT)

%.o : %.c $(HEADER)
	$(CC) $(WFLAGS) -c $< -o $@

clean :
	$(RM) $(OBJECT)

fclean : clean
	$(RM) $(NAME)

re : fclean all

.PHONY : all clean fclean re
