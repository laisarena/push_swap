/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrasson <lfrasson@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 16:55:59 by lfrasson          #+#    #+#             */
/*   Updated: 2021/05/28 20:53:03 by lfrasson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	STACK_H
# define STACK_H

#include "libft.h" 

typedef struct	s_stack
{
	int				element;
	struct s_stack	*prev;
	struct s_stack	*next;
}					t_stack;

t_stack	*ft_new_stack_node(int element);
t_stack	*ft_stack_pop(t_stack **stack);
void	ft_stack_push(t_stack **stack, t_stack *node);

#endif
