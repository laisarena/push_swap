/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   second_split_return.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrasson <lfrasson@student.42sp.org.b      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 17:03:14 by lfrasson          #+#    #+#             */
/*   Updated: 2021/06/23 17:35:03 by lfrasson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort.h"

static t_pivot	ft_get_split_pivot(int *sort, t_pivot pivot)
{
	t_pivot	new_pivot;

	new_pivot.index = pivot.index + pivot.qtd / 2;
	new_pivot.value = sort[new_pivot.index];
	new_pivot.qtd = new_pivot.index;
	return (new_pivot);
}

static void	ft_second_split_return(t_stack *stack_a, t_stack *stack_b,
		int group, t_pivot pivot)
{
	while (stack_a->top->prev->group == group)
	{
		ft_rev_rotate_a(stack_a);
		if (stack_a->top->element < pivot.value)
			ft_push_b(stack_a, stack_b);
	}
}

static void	ft_first_split_return(t_stack *stack_a, t_stack *stack_b,
		int group, t_pivot pivot)
{
	while (stack_a->top->group == group)
	{
		if (stack_a->top->element < pivot.value)
			ft_push_b(stack_a, stack_b);
		else
			ft_rotate_a(stack_a);
	}
}

void	ft_return_to_b(t_stack *stack_a, t_stack *stack_b,
		int *sort, t_pivot pivot)
{
	t_pivot	new_pivot;

	new_pivot = ft_get_split_pivot(sort, pivot);
	ft_first_split_return(stack_a, stack_b, pivot.index, new_pivot);
	new_pivot = ft_get_split_pivot(sort, new_pivot);
	ft_second_split_return(stack_a, stack_b, pivot.index, new_pivot);
	while (stack_a->top->group == pivot.index)
		ft_push_b(stack_a, stack_b);
}
