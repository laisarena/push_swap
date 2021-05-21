# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lfrasson <lfrasson@student.42sp.org.br     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/18 23:46:27 by lfrasson          #+#    #+#              #
#    Updated: 2021/05/21 15:50:39 by lfrasson         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

LIBFT = libft.a

LIBFT_PATH = ./libft/

SRCS_PATH = ./srcs/

OBJS_PATH = ./objs/

SRCS = main.c

CC = gcc

CFLAGS = -Wall -Wextra -Werror

OBJS = $(SRCS:.c=.o)

%.o:	$(SRCS_PATH)%.c
	$(CC) $(CFLAGS) -c $< -o $(OBJS_PATH)$@

$(NAME): dir $(OBJS)
	make bonus -C $(LIBFT_PATH)
	$(CC) $(FLAGS) $(addprefix $(OBJS_PATH),$(OBJS)) -L$(LIBFT_PATH) -lft -I$(LIBFT_PATH) -o $(NAME)

dir:
	mkdir -p $(OBJS_PATH)

all:	$(NAME)

clean:
	make clean -C $(LIBFT_PATH)
	rm -rf $(OBJS_PATH)

fclean: clean
	make fclean -C $(LIBFT_PATH)
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
