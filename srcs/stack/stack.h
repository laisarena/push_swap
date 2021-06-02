/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrasson <lfrasson@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 16:55:59 by lfrasson          #+#    #+#             */
/*   Updated: 2021/06/02 18:11:56 by lfrasson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	STACK_H
# define STACK_H

#include "libft.h" 

typedef struct	s_node
{
	int				element;
	struct s_node	*prev;
	struct s_node	*next;
}					t_node;

typedef struct	s_stack
{
	int		size;
	t_node	*top;
}			t_stack;

void	ft_new_stack(t_stack *stack);
t_node	*ft_new_stack_node(int element);
t_node	*ft_stack_pop(t_stack *stack);
void	ft_stack_push(t_stack *stack, t_node *node);
void	ft_connect(t_node *first, t_node *second);

#endif
