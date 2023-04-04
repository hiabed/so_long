NAME = so_long
NAME_B = so_long_bonus
CFILES = ./src_files/so_long.c ./src_files/read_file.c ./src_files/read_file_utils.c ./src_files/movements.c ./src_files/helper.c ./src_files/switch_p_imgs_to_w_and_e.c ./src_files/eat_coin_when_touch.c ./src_files/check_map_errors.c ./libft/ft_split.c ./libft/ft_strlen.c ./ft_printf/ft_printf.c ./ft_printf/ft_putchar.c ./ft_printf/ft_putnbr.c ./ft_printf/ft_putstr.c ./ft_printf/ntohex_up.c ./ft_printf/ntohex.c ./ft_printf/print_pointer.c ./ft_printf/print_uns_num.c
CFILES_BONUS = ./bonus/so_long_bonus.c ./bonus/imgs_bonus.c ./bonus/animation_bonus.c ./bonus/read_file_bonus.c ./bonus/read_file_utils_bonus.c ./bonus/movements_bonus.c ./bonus/helper_bonus.c ./bonus/switch_p_imgs_to_w_and_e_bonus.c ./bonus/eat_coin_when_touch_bonus.c ./bonus/check_map_errors_bonus.c ./libft/ft_split.c ./libft/ft_itoa.c ./libft/ft_strdup.c ./libft/ft_strlen.c ./ft_printf/ft_printf.c ./ft_printf/ft_putchar.c ./ft_printf/ft_putnbr.c ./ft_printf/ft_putstr.c ./ft_printf/ntohex_up.c ./ft_printf/ntohex.c ./ft_printf/print_pointer.c ./ft_printf/print_uns_num.c
OBJ = ${CFILES:.c=.o}
OBJ_BONUS = ${CFILES_BONUS:.c=.o}
CFLAGS = -Wall -Wextra -Werror -fsanitize=address
CC = cc

all : ${NAME}

${NAME} : ${OBJ}
	${CC} ${CFLAGS} ${CFILES} -lmlx -framework OpenGL -framework AppKit -o ${NAME}

bonus : ${NAME_B}

${NAME_B} : ${OBJ_BONUS}
	${CC} ${CFLAGS} ${CFILES_BONUS} -lmlx -framework OpenGL -framework AppKit -o ${NAME_B}

clean :
	${RM} ${OBJ} ${OBJ_BONUS}

fclean : clean
	${RM} ${NAME} ${NAME_B}

re : fclean all