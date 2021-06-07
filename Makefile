# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aymaatou <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/07 20:28:25 by aymaatou          #+#    #+#              #
#    Updated: 2021/06/07 20:28:30 by aymaatou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=pipex
LIB=libft.a
SRC= exec_children.c pipex.c 
FLGS=-Wall -Werror -Wextra
CC=gcc
all: $(NAME)

$(NAME): 
	make -C libft/.
	mv libft/$(LIB) .
	$(CC) $(SRC) $(LIB) -o $(NAME)
clean :
	rm -rf $(NAME)
fclean: clean
	rm -rf $(LIB)

re: fclean all

.PHONY : all clean fclean re $(NAME)
