# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lfrasson <lfrasson@student.42sp.org.br     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/18 23:46:27 by lfrasson          #+#    #+#              #
#    Updated: 2021/05/24 12:22:50 by lfrasson         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := push_swap

LIBFT := libft.a
LIBFTDIR := ./libft/

CC := gcc
CFLAGS := -Wall -Wextra -Werror

SRCDIR := ./srcs/
SRCS := main.c\
		stack/stack.c

VPATH := $(SRCDIR):$(SRCDIR)stack 

OBJDIR := ./objs/
OBJS := $(addprefix $(OBJDIR), $(notdir $(SRCS:.c=.o)))

$(OBJDIR)%.o:	%.c
	$(CC) $(CFLAGS) -I$(LIBFTDIR) -I$(SRCDIR) -c $< -o $@

all:	$(NAME)

$(NAME): $(OBJS)
	make bonus -C $(LIBFTDIR)
	$(CC) $(CFLAGS) $(OBJS) -L$(LIBFTDIR) -lft -I$(LIBFTDIR) -o $@

$(OBJS): | $(OBJDIR)

$(OBJDIR):
	mkdir $(OBJDIR)

clean:
	make clean -C $(LIBFTDIR)
	rm -rf $(OBJDIR)

fclean: clean
	make fclean -C $(LIBFTDIR)
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
