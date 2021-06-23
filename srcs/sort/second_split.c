/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   second_split.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrasson <lfrasson@student.42sp.org.b      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 15:51:07 by lfrasson          #+#    #+#             */
/*   Updated: 2021/06/23 17:05:40 by lfrasson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort.h"

static void	ft_second_split(t_stack *stack_a, t_stack *stack_b, t_pivot pivot)
{
	int	qtd;

	qtd = pivot.qtd;
	while (qtd > 0 && stack_b->top)
	{
		if (stack_b->top->element >= pivot.value)
		{
			stack_b->top->group = pivot.index;
			ft_push_a(stack_a, stack_b);
			qtd--;
		}
		else
			ft_rotate_b(stack_b);
	}
}

static t_pivot	ft_get_second_pivot(int *sort, int size, int first)
{
	t_pivot	 pivot;

	if (size < 10)
		pivot.index = size - size / 2;
	else if (size < 50)
		pivot.index = size - size / 3;
	else if (size < 90)
		pivot.index = size - size / 5;
	else if (size < 110)
		pivot.index = size - size / 7;
	else if (size < 150)
		pivot.index = size - size / 9;
	else
		pivot.index = size - size / 11;
	if (pivot.index > size - 2)
		pivot.index = size - 2;
	pivot.value = sort[pivot.index];
	pivot.qtd = size - pivot.index;
	pivot.first = first;
	return (pivot);
}

void	ft_second_level(t_stack *stack_a, t_stack *stack_b,
		int *sort, t_pivot first_pivot)
{
	t_pivot	pivot;

	if (!(first_pivot.first && stack_b->size > 3))
		return ;
	pivot = ft_get_second_pivot(sort, stack_b->size, first_pivot.first);
	ft_second_split(stack_a, stack_b, pivot);
	ft_second_level(stack_a, stack_b, sort, first_pivot);
	ft_return_to_b(stack_a, stack_b, sort, pivot);
}
