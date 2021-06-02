/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrasson <lfrasson@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 23:18:38 by lfrasson          #+#    #+#             */
/*   Updated: 2021/06/02 18:08:14 by lfrasson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"

static void	ft_swap(t_stack *stack)
{
	t_node	*first;
	t_node	*second;
	t_node	*third;
	t_node	*last;

	first = stack->top;
	if (!first)
		return ;
	second = first->next;
	third = second->next;
	last = first->prev;
	if (first == second)
		return ;
	if (third != first)
	{
		ft_connect(last, second);
		ft_connect(second, first);
		ft_connect(first, third);
	}
	stack->top = second;
}

void	ft_swap_a(t_stack *stack_a)
{
	ft_swap(stack_a);
	ft_putstr_fd(SWAP_A, 1);
}

void	ft_swap_b(t_stack *stack_b)
{
	ft_swap(stack_b);
	ft_putstr_fd(SWAP_B, 1);
}

void	ft_double_swap(t_stack *stack_a, t_stack *stack_b)
{
	ft_swap(stack_a);
	ft_swap(stack_b);
	ft_putstr_fd(SWAP, 1);
}
