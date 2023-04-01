NAME = so_long

CFILES = so_long.c ./src_files/read_file.c ./src_files/read_file_utils.c ./src_files/movements.c ./src_files/helper.c ./src_files/switch_p_imgs_to_w_and_e.c ./src_files/eat_coin_when_touch.c ./src_files/check_map_errors.c ./libft/ft_split.c ./ft_printf/ft_printf.c ./ft_printf/ft_putchar.c ./ft_printf/ft_putnbr.c ./ft_printf/ft_putstr.c ./ft_printf/ntohex_up.c ./ft_printf/ntohex.c ./ft_printf/print_pointer.c ./ft_printf/print_uns_num.c
OBJECT = ${CFILES:.c=.o}
CFLAGS = -Wall -Wextra -Werror
CC = cc

all : ${NAME}

${NAME} : ${OBJECT}
	${CC} ${CFLAGS} ${CFILES} -lmlx -framework OpenGL -framework AppKit -o ${NAME} 

clean :
	${RM} ${OBJECT}

fclean : clean
	${RM} ${NAME}

re : fclean all