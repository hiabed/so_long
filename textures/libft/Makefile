# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mhassani <mhassani@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/29 13:57:27 by mhassani          #+#    #+#              #
#    Updated: 2023/04/02 00:55:46 by mhassani         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CFILES = ft_atoi.c\
        ft_split.c\
        ft_strchr.c\
        ft_strjoin.c\
        ft_strlen.c\
        ft_strnstr.c\
        ft_itoa.c\
        ft_strdup.c\

OBJ = ${CFILES:.c=.o}
CFLAGS = -Wall -Werror -Wextra
CC = cc
LI = ar -r
HEAD = libft.h

all : ${NAME}

${NAME} : ${OBJ}
	${LI} ${NAME} ${OBJ}

clean :
	${RM} ${OBJ}

fclean : clean
	${RM} ${NAME}

re : fclean all