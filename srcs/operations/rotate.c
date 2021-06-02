/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrasson <lfrasson@student.42sp.org.b      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 17:26:11 by lfrasson          #+#    #+#             */
/*   Updated: 2021/06/02 18:10:24 by lfrasson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"

static void	ft_rotate(t_stack *stack)
{
	stack->top = stack->top->next;
}

void	ft_rotate_a(t_stack *stack_a)
{
	ft_rotate(stack_a);
	ft_putstr_fd(ROTATE_A, 1);
}

void	ft_rotate_b(t_stack *stack_b)
{
	ft_rotate(stack_b);
	ft_putstr_fd(ROTATE_B, 1);
}

void	ft_double_rotate(t_stack *stack_a, t_stack *stack_b)
{
	ft_rotate(stack_a);
	ft_rotate(stack_b);
	ft_putstr_fd(ROTATE, 1);
}
