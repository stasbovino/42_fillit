# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gwyman-m <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/03/15 15:08:42 by gwyman-m          #+#    #+#              #
#    Updated: 2019/11/09 17:35:56 by gwyman-m         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

FLAGS = -Wall -Wextra -Werror -g -I sourses -I libft/includes

LIBFT = -L libft/ -lft

CFILES = main.c check_valid.c get_figure.c read_figure.c map.c fillit.c \
		 position.c place_del_figure.c equal_figures.c mapr_opts.c \
		 mapr_start.c

SRC_DIR = sourses/

SRC = $(addprefix $(SRC_DIR),$(CFILES))

OBJ = $(SRC:%.c=%.o)

VPATH := sourses

submodule = `git submodule | grep "-"`

.PHONY: subm all clean fclean re

.SILENT: subm

all: subm $(NAME)

subm:
	if [[ -n $(submodule) ]]; then\
		git submodule init;\
		git submodule update;\
	fi

$(NAME): $(OBJ)
	make -C libft
	gcc $(FLAGS) $(OBJ) -o $(NAME) $(LIBFT)

%.o: %.c $(SRC_DIR)fillit.h
	gcc $(FLAGS) -c $< -o $@

clean:
	make clean -C ./libft
	rm -f $(OBJ)

fclean: clean
	make fclean -C ./libft
	rm -f $(NAME)

re: fclean all
