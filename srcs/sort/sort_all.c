/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrasson <lfrasson@student.42sp.org.b      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/05 15:00:20 by lfrasson          #+#    #+#             */
/*   Updated: 2021/06/06 16:23:54 by lfrasson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort.h"

static int	ft_can_swap_a(t_stack *stack_a)
{
	t_node	*top;
	t_node	*second;

	if (stack_a->size < 2)
		return (FALSE);
	top = stack_a->top;
	second = stack_a->top->next;
	if (top->group != second->group)
		return (FALSE);
	if (top->element > second->element)
		return (TRUE);
	return (FALSE);
}

static int	ft_can_swap_b(t_stack *stack_b)
{
	t_node	*top;
	t_node	*second;

	if (stack_b->size < 2)
		return (FALSE);
	top = stack_b->top;
	second = stack_b->top->next;
	if (top->group != second->group)
		return (FALSE);
	if (top->element < second->element)
		return (TRUE);
	return (FALSE);
}

void	ft_can_swap(t_stack *stack_a, t_stack *stack_b)
{
	int	sa;
	int	sb;

	sa = ft_can_swap_a(stack_a);
	sb = ft_can_swap_b(stack_b);
	if (sa && sb)
		ft_double_swap(stack_a, stack_b);
	//if (sa && !sb)
	//	ft_swap_a(stack_a);
	if (!sa && sb)
		ft_swap_b(stack_b);
}
static void	ft_split_stack(t_stack *stack_a, t_stack *stack_b, t_pivot pivot)
{
	int	qtd;

	qtd = pivot.qtd;
	while (qtd > 0)
	{
		//ft_can_swap(stack_a, stack_b);
		if (stack_a->top->element < pivot.value)
		{
			stack_a->top->group = pivot.index;
			ft_push_b(stack_a, stack_b);
			qtd--;
		}
		else
			ft_rotate_a(stack_a);
	}
}

static void	ft_split_stack_b(t_stack *stack_a, t_stack *stack_b, t_pivot pivot)
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
	
	//while (stack_a->top->group == pivot.group)
	while (stack_a->top->group == pivot.index)
		ft_push_b(stack_a, stack_b);
}

static t_pivot	ft_get_pivot_b(int *sort, int size, int first)
{
	t_pivot	 pivot;
	pivot.index = size / 2;
	if (pivot.index > size - 2)
		pivot.index = size - 2;
	pivot.value = sort[pivot.index];
	pivot.qtd = pivot.index;
	pivot.first = first;
	return (pivot);
}

static t_pivot	ft_get_pivot(int *sort, int size, int first)
{
	t_pivot	 pivot;
/*
	if (size < 10)
		pivot.index = size / 2;
	else if (size < 50)
		pivot.index = size / 3;
	else if (size < 90)
		pivot.index = size / 5;
	else if (size < 110)
		pivot.index = size / 7;
	else if (size < 150)
		pivot.index = size / 9;
	else
		pivot.index = size / 11;
	*/pivot.index = size / 2;
	if (pivot.index > size - 3)
		pivot.index = size - 3;
	pivot.value = sort[pivot.index];
	pivot.qtd = pivot.index;
	pivot.first = first;
	return (pivot);
}
void	ft_sort_all(t_stack *stack_a, t_stack *stack_b, int *sort, int first)
{
	t_pivot	pivot;
	t_pivot	pivot_b;

	pivot.index = 0;
	if (stack_a->size > 3)
	{
		pivot = ft_get_pivot(sort, stack_a->size, first);
		ft_split_stack(stack_a, stack_b, pivot);
		if (first && stack_b->size > 3)
		{
			pivot_b = ft_get_pivot_b(sort, pivot.qtd, first);
			ft_split_stack_b(stack_a, stack_b, pivot_b);
		}
		ft_sort_all(stack_a, stack_b, sort + pivot.index, 0);
	}
	ft_sort_three(stack_a, sort + pivot.index);
	ft_return_stack(stack_a, stack_b, pivot, sort);
}
