# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ikourkji <ikourkji@student.42.us.or>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/26 19:40:37 by ikourkji          #+#    #+#              #
#    Updated: 2019/02/21 21:58:43 by ikourkji         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC = ft_printf.c ft_printf_cont.c pf_core.c pf_utils.c pf_numbers.c \
	  pf_strings.c pf_strutils.c pf_smallconvs.c pf_floats.c

OBJ = $(SRC:.c=.o)

LFTOBJ = libft/ft_*.o

CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME):
	@make -C libft
	gcc $(CFLAGS) -c $(SRC)
	ar rc $(NAME) $(OBJ) $(LFTOBJ)
	ranlib $(NAME)

clean:
	@make -C libft clean
	rm -f $(OBJ)

fclean: clean
	@make -C libft fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
