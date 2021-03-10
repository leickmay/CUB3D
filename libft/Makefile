
HEADER      =   includes/libft.h

SRCS        =	srcs/ft_memccpy.c srcs/ft_memset.c srcs/ft_split.c srcs/ft_strlcpy.c srcs/ft_strrchr.c srcs/ft_bzero.c \
				srcs/ft_isascii.c srcs/ft_memchr.c srcs/ft_putchar_fd.c srcs/ft_strchr.c srcs/ft_strlen.c srcs/ft_strtrim.c \
				srcs/ft_calloc.c srcs/ft_isdigit.c srcs/ft_memcmp.c srcs/ft_putendl_fd.c srcs/ft_strdup.c srcs/ft_strmapi.c \
				srcs/ft_substr.c srcs/ft_isalnum.c srcs/ft_isprint.c srcs/ft_memcpy.c srcs/ft_putnbr_fd.c srcs/ft_strjoin.c \
				srcs/ft_strncmp.c srcs/ft_tolower.c srcs/ft_atoi.c srcs/ft_isalpha.c srcs/ft_itoa.c srcs/ft_memmove.c \
				srcs/ft_putstr_fd.c srcs/ft_strlcat.c srcs/ft_strnstr.c srcs/ft_toupper.c \
				srcs/ft_lstnew.c srcs/ft_lstadd_front.c srcs/ft_lstsize.c srcs/ft_lstlast.c srcs/ft_lstadd_back.c \
				srcs/ft_lstdelone.c srcs/ft_lstclear.c srcs/ft_lstiter.c srcs/ft_lstmap.c \
				srcs/ft_putchar.c srcs/ft_putnbr.c srcs/ft_itoa_base.c srcs/ft_putstr.c

GNL			=	gnl/get_next_line.c gnl/get_next_line_utils.c

PRINTF		=	ft_printf/flags.c ft_printf/ft_itoa_printf.c ft_printf/ft_print_c.c ft_printf/ft_print_d_utils.c ft_printf/ft_print_d.c ft_printf/ft_print_p.c \
				ft_printf/ft_print_percent.c ft_printf/ft_print_s.c ft_printf/ft_print_u.c ft_printf/ft_print_x.c ft_printf/ft_printf_utils.c ft_printf/ft_printf.c \
				ft_printf/get_flags.c

OBJS        =   ${SRCS:.c=.o}

OGNL		=	${GNL:.c=.o}

OPRINTF		= 	${PRINTF:.c=.o}

NAME        =   libft.a

CC          =   gcc

CFLAGS      =   -Wall -Wextra -Werror

RM          =   rm -f

.c.o:
	 ${CC} ${CFLAGS} -c $< -o ${<:.c=.o} -I ${HEADER}

$(NAME):	${OBJS} ${OGNL} ${OPRINTF} ${HEADER}
	ar -rcs ${NAME} ${OBJS} ${OGNL} ${OPRINTF}
	
#bonus:	${OBJS} ${OBONUS}
#	ar -rcs ${NAME} ${OBJS} ${OBONUS}

all:        ${NAME} 

clean:
	${RM} ${OBJS} ${OGNL} ${OPRINTF}

fclean:     clean
	${RM} ${NAME}

re:         fclean all

