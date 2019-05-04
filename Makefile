# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ikourkji <ikourkji@student.42.us.or>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/03/12 03:43:24 by ikourkji          #+#    #+#              #
#    Updated: 2019/04/30 07:50:26 by ikourkji         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ssl

_SRC = *.c
SRC = $(patsubst %,src/%,$(_SRC))

_OBJ = $(_SRC:.c=.o)
OBJ= $(patsubst %,obj/%,$(_OBJ))

INC = -I ./inc

LIB = -L ./libft -lft

CFLAGS = -Wall -Wextra -Werror

FSAN = -fsanitize=address

all : $(NAME)

$(NAME) :
	@make -C libft
	gcc $(INC) -c $(SRC)
	@mv $(_OBJ) obj
	gcc $(CFLAGS) -o $(NAME) $(INC) $(LIB) $(OBJ)

clean:
	@make -C libft clean
	rm -rf $(OBJ)

fclean: clean
	@make -C libft fclean
	rm -f $(NAME)

re: fclean all

test:
	gcc $(INC) $(SRC) $(LIB) -g -o test_$(NAME)

testf:
	gcc $(INC) $(SRC) $(LIB) -g $(FSAN) -o test_$(NAME)

.PHONY: all $(NAME) clean fclean re test
