/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrasson <lfrasson@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 23:18:38 by lfrasson          #+#    #+#             */
/*   Updated: 2021/06/01 17:08:19 by lfrasson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"

static void	ft_swap(t_stack **start)
{
	t_stack	*first;
	t_stack	*second;
	t_stack	*third;
	t_stack	*last;

	if (!*start)
		return ;
	first = *start;
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
	*start = second;
}

void	ft_swap_a(t_stack **stack_a)
{
	ft_swap(stack_a);
	ft_putstr_fd(SWAP_A, 1);
}

void	ft_swap_b(t_stack **stack_b)
{
	ft_swap(stack_b);
	ft_putstr_fd(SWAP_B, 1);
}

void	ft_double_swap(t_stack **stack_a, t_stack **stack_b)
{
	ft_swap(stack_a);
	ft_swap(stack_b);
	ft_putstr_fd(SWAP, 1);
}