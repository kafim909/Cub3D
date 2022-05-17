# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mtournay <mtournay@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/07 12:15:16 by mtournay          #+#    #+#              #
#    Updated: 2022/05/16 19:44:27 by mtournay         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	Cub3D

SRCS		=	./srcs/main.c ./srcs/parsing/parsing.c ./srcs/parsing/data.c \
				./srcs/parsing/parsing_map.c ./srcs/parsing/error.c \

DYLIB		= 	./libmlx.dylib

LIBFT		= 	./libft/

NAMELFT		= 	./libft/libft.a

OBJS		=	$(SRCS:c=o)

CC			=	gcc

CFLAGS		=	-Wall -Wextra -Werror  -g3 \
				-fsanitize=address -g

MLX			=	-lmlx -framework OpenGL -framework AppKit -lm -O3 -I.

INC			= 	-I./head/

all:			$(OBJS) $(NAME)

%.o:		%.c
				@echo "Compiling $<"
				@$(CC) $(CFLAGS) -c $(INC) $< -o $(<:c=o)
				@echo "Compiling OK!"

$(NAME):	$(OBJS)
				@make all -s -C ./libft
				@make -s -C ./mlx
				@echo "Linking $^"
				mv ./mlx/libmlx.dylib .
				${CC} ${CFLAGS} ${OBJS} ${NAMELFT} ${DYLIB} ${MLX} -o ${NAME}
				@echo "Executable created!"

clean:
				@echo "Cleaning objects..."
				@rm -f $(OBJS) ${DYLIB}
				@echo "Cleaned up!"

fclean:		clean
				@make fclean -s -C ./libft
				@make clean -s -C ./mlx
				@echo "Removing executable..."
				@rm -f $(NAME)
				@echo "Removed!"

re:			fclean all

.PHONY:		all clean fclean re
