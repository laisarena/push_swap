/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   return_stack_b.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrasson <lfrasson@student.42sp.org.b      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/05 16:45:31 by lfrasson          #+#    #+#             */
/*   Updated: 2021/06/11 13:57:08 by lfrasson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort.h"

static int	ft_find_sort_way(t_stack *stack_b, t_pivot pivot, int value)
{
	t_node	*node;
	int		count;
	int		max;

	node = stack_b->top;
	count = 0;
	max = pivot.qtd;
	if (pivot.first)
		max = pivot.qtd / 2;
	while (count < max)
	{
		if (node->element == value)
			return (0);
		count++;
		node = node->next;
	}
	return (1);
}

static int	ft_change_direction(t_node *top, int group, int reverse)
{
	if (reverse == 0 && top->group != group)
		return (1);
	else if (reverse == 1 && top->prev->group != group)
		return (0);
	return (reverse);
}

void	ft_return_stack(t_stack *stack_a, t_stack *stack_b,
		t_pivot pivot, int *sort)
{
	int	reverse;

	if (stack_b->top == NULL)
		return ;
	reverse = 0;
	pivot.index--;
	pivot.group = stack_b->top->group;
	while (stack_b->size > 0 && pivot.index >= 0)
	{
		reverse = ft_find_sort_way(stack_b, pivot, sort[pivot.index]);
		if (stack_b->top->element == sort[pivot.index])
		{
			ft_push_a(stack_a, stack_b);
			pivot.index--;
			pivot.qtd--;
		}
		else
		{
			if (reverse)
				ft_rev_rotate_b(stack_b);
			else
				ft_rotate_b(stack_b);
		}
		reverse = ft_change_direction(stack_b->top, pivot.group, reverse);
	}
}
