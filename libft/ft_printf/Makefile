
HEADER      =  includes/ft_printf.h

SRCS        =  srcs/ft_printf.c \
				srcs/ft_printf_utils.c srcs/ft_print_c.c srcs/ft_print_s.c srcs/get_flags.c \
				srcs/ft_print_p.c srcs/ft_print_d.c srcs/ft_print_d_utils.c srcs/flags.c\
				srcs/ft_print_u.c srcs/ft_itoa_printf.c srcs/ft_print_x.c srcs/ft_print_percent.c

OBJS        =   ${SRCS:.c=.o}

NAME        =   libftprintf.a

CC          =   gcc

CFLAGS      =   -Wall -Wextra -Werror

RM          =   rm -f

.c.o:
	 ${CC} ${CFLAGS} -c $< -o ${<:.c=.o} -I ${HEADER}

$(NAME):	$(OBJS)
	$(MAKE) bonus -C ./libft
	cp libft/libft.a $(NAME) 
	ar -rcs $(NAME) $(OBJS) 

all:        $(NAME) 

clean:
	$(MAKE) clean -C ./libft
	$(RM) $(OBJS)

fclean:     clean
	$(MAKE) fclean -C ./libft
	$(RM) $(NAME)

re:         fclean all

.PHONY : all, clean, fclean, re

