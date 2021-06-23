/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrasson <lfrasson@student.42sp.org.b      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 10:34:17 by lfrasson          #+#    #+#             */
/*   Updated: 2021/06/23 15:30:02 by lfrasson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort.h"

void	ft_sort_three(t_stack *stack_a, int *sort)
{
	t_node	*top;
	t_node	*mid;

	if (stack_a->size != 3)
		return ;
	top = stack_a->top;
	mid = top->next;
	if (sort[2] == top->element)
		ft_rotate_a(stack_a);
	if (sort[2] == mid->element)
		ft_rev_rotate_a(stack_a);
	mid = stack_a->top->next;
	if (sort[0] == mid->element)
		ft_swap_a(stack_a);
}

static void	ft_sort_two(t_stack *stack_a)
{
	if (stack_a->size == 2)
		ft_swap_a(stack_a);
}

void	ft_sort(t_stack *stack_a, int *sort)
{
	t_stack	stack_b;

	ft_new_stack(&stack_b);
	ft_sort_two(stack_a);
	ft_sort_three(stack_a, sort);
	ft_sort_all(stack_a, &stack_b, sort, 1);
}
