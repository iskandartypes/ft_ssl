# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ikourkji <ikourkji@student.42.us.or>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/03/12 03:43:24 by ikourkji          #+#    #+#              #
#    Updated: 2019/03/12 03:49:33 by ikourkji         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ssl

_SRC = main.c
SRC = $(patsubst %,src/%,$(_SRC))

_OBJ = $(_SRC:.c=.o)
OBJ= $(patsubst %,obj/%,$(_OBJ))

INC = -I ./inc

LIB = -L ./ft_printf -lftprintf

CFLAGS = -Wall -Wextra -Werror

all : $(NAME)

$(NAME) :
	@make -C lib/ft_printf
	gcc $(INC) -c $(SRC)
	@mv $(_OBJ) obj
	gcc $(CFLAGS) -o $(NAME) $(INC) $(LIB) $(OBJ)

clean:
	@make -C lib/ft_printf clean
	rm -rf $(OBJ)

fclean: clean
	@make -C lib/ft_printf fclean
	rm -f $(NAME)

re: fclean all

test:
	gcc $(INC) $(_SRC) $(LIB) -g

.PHONY: all $(NAME) clean fclean re test
