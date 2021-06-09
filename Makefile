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

NAME = pipex

SRC = pipex.c exec_children.c
BONUS = pipex_bonus.c exec_children_bonus.c
	  
FLAGS = gcc -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(SRC)
	@make -C ./libft
	@$(CC) -o $(NAME) $(SRC) libft/libft.a

clean:
	@make clean -C ./libft

fclean: clean
	@make fclean -C ./libft
	@rm -rf $(NAME)

bonus: fclean
	@make -C ./libft
	@$(CC) -o $(NAME) $(BONUS) libft/libft.a

re: fclean all