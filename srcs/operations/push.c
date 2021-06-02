/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrasson <lfrasson@student.42sp.org.b      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 16:47:36 by lfrasson          #+#    #+#             */
/*   Updated: 2021/06/02 18:18:35 by lfrasson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"

static void	ft_pop_push(t_stack *stack_pop, t_stack *stack_push)
{
	t_node *node;
	
	node = ft_stack_pop(stack_pop);
	ft_stack_push(stack_push, node);
}

void	ft_push_a(t_stack *stack_a, t_stack *stack_b)
{
	ft_pop_push(stack_b, stack_a);
	ft_putstr_fd(PUSH_A, 1);
}

void	ft_push_b(t_stack *stack_a, t_stack *stack_b)
{
	ft_pop_push(stack_a, stack_b);
	ft_putstr_fd(PUSH_B, 1);
}
