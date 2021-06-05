/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrasson <lfrasson@student.42sp.org.b      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 10:34:17 by lfrasson          #+#    #+#             */
/*   Updated: 2021/06/04 22:49:54 by lfrasson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort.h"

static void	ft_sort_three(t_stack *stack_a, int *sort)
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

typedef struct s_pivot
{
	int	index;
	int	value;
	int	qtd;
	int group;
	int first;
}	t_pivot;

static t_pivot	ft_get_pivot(int *sort, int size, int first)
{
	t_pivot	 pivot;

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
	if (pivot.index > size - 3)
		pivot.index = size - 3;
	pivot.value = sort[pivot.index];
	pivot.qtd = pivot.index;
	pivot.first = first;
	return (pivot);
}

void	ft_split_stack(t_stack *stack_a, t_stack *stack_b, t_pivot pivot)
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

int	ft_find_sort_way(t_stack *stack_b, t_pivot pivot, int value)
{
	t_node *node;
	int count;
	int max;

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

void	ft_return_stack(t_stack *stack_a, t_stack *stack_b,
		t_pivot pivot, int *sort)
{
	int reverse;

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
		}
		else
		{
			if (reverse)
				ft_rev_rotate_b(stack_b);
			else
				ft_rotate_b(stack_b);
		}
		if (reverse == 0 && stack_b->top->group != pivot.group)
			reverse = 1;
		else if (reverse == 1 && stack_b->top->prev->group != pivot.group)
			reverse = 0;
	}
}

void	ft_sort_more(t_stack *stack_a, t_stack *stack_b, int *sort, int first)
{
	t_pivot pivot;

	pivot.index = 0;
	if (stack_a->size > 3)
	{
		pivot = ft_get_pivot(sort, stack_a->size, first);
		ft_split_stack(stack_a, stack_b, pivot);
		ft_sort_more(stack_a, stack_b, sort + pivot.index, 0);
	}
	ft_sort_three(stack_a, sort + pivot.index);
	ft_return_stack(stack_a, stack_b, pivot, sort);
}

void	ft_sort(t_stack *stack_a, int *sort)
{
	t_stack stack_b;
	
	ft_new_stack(&stack_b);
	ft_sort_two(stack_a);
	ft_sort_three(stack_a, sort);
	ft_sort_more(stack_a, &stack_b, sort, 1);
}
