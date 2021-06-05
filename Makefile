# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lfrasson <lfrasson@student.42sp.org.br     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/18 23:46:27 by lfrasson          #+#    #+#              #
#    Updated: 2021/06/05 16:49:00 by lfrasson         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := push_swap

LIBFT := libft.a
LIBFTDIR := ./libft/

CC := gcc
CFLAGS := -Wall -Wextra -Werror
CFLAGS += -g
CFLAGS += -fsanitize=address

SRCDIR := ./srcs/
SRCS := main.c\
		free_resources.c\
		parse/parse.c\
		parse/sort_input.c\
		stack/stack.c\
		operations/swap.c\
		operations/push.c\
		operations/rotate.c\
		operations/reverse_rotate.c\
		sort/sort.c\
		sort/sort_all.c\
		sort/return_stack_b.c\

VPATH := $(SRCDIR)\
		 $(SRCDIR)stack\
		 $(SRCDIR)parse\
		 $(SRCDIR)operations\
		 $(SRCDIR)sort

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

sani: CFLAGS += -g -fsanitize=address
sani: re

.PHONY: all clean fclean re
