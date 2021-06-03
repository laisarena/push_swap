/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrasson <lfrasson@student.42sp.org.b      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 10:34:17 by lfrasson          #+#    #+#             */
/*   Updated: 2021/06/03 19:00:55 by lfrasson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort.h"
#include "stdio.h"

void	ft_print_stack(t_node *top, char c)
{
	t_node	*last;;

	if (!top)
		return ;
	printf("%c\t", c);
	last = top->prev;
	while (top != last)
	{
		printf("%d\t", top->element);
		top = top->next;
	}
	printf("%d ", top->element);
	printf("|\n");
}

void	ft_print(t_stack *stack_a, t_stack *stack_b)
{
	ft_print_stack(stack_a->top, 'A');
	ft_print_stack(stack_b->top, 'B');
	printf("-------------------------------------------------------------------------------\n");
}

void	ft_test(t_stack *stack_a, t_stack *stack_b)
{
	ft_swap_a(stack_a);
	ft_print(stack_a, stack_b);
	ft_push_b(stack_a, stack_b);
	ft_push_b(stack_a, stack_b);
	ft_print(stack_a, stack_b);
	ft_double_swap(stack_a, stack_b);
	ft_print(stack_a, stack_b);
	ft_rotate_a(stack_a);
	ft_print(stack_a, stack_b);
	ft_rev_rotate_a(stack_a);
	ft_print(stack_a, stack_b);
}

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
}	t_pivot;

static t_pivot	ft_get_pivot(int *sort, int size)
{
	t_pivot	 pivot;

	pivot.index = size / 2;
	if (pivot.index > size - 3)
		pivot.index = size - 3;
	pivot.value = sort[pivot.index];
	pivot.qtd = pivot.index;
	return (pivot);
}

void	ft_split_stack(t_stack *stack_a, t_stack *stack_b, t_pivot pivot)
{
	int	qtd;

	qtd = pivot.qtd;
	while (qtd > 0)
	{
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

void	ft_return_stack(t_stack *stack_a, t_stack *stack_b,
		t_pivot pivot, int *sort)
{
	int reverse;

	reverse = 0;
	pivot.index--;
	pivot.group = stack_b->top->group;
	while (stack_b->size > 0 && pivot.index >= 0)
	{
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
		if (reverse == 1 && stack_b->top->prev->group != pivot.group)
			reverse = 0;
	}
}

void	ft_sort_more(t_stack *stack_a, t_stack *stack_b, int *sort)
{
	t_pivot pivot;

	pivot = ft_get_pivot(sort, stack_a->size);
	ft_split_stack(stack_a, stack_b, pivot);
	if (stack_a->size > 3)
		ft_sort_more(stack_a, stack_b, sort + pivot.index);
	//ft_print(stack_a, stack_b);
	ft_sort_three(stack_a, sort + pivot.index);
	//ft_print(stack_a, stack_b);
	ft_return_stack(stack_a, stack_b, pivot, sort);
}

void	ft_sort(t_stack *stack_a, int *sort)
{
	t_stack stack_b;
	
	ft_new_stack(&stack_b);
	//ft_print(stack_a, &stack_b);
	//ft_test(stack_a, &stack_b);
	ft_sort_two(stack_a);
	ft_sort_three(stack_a, sort);
	ft_sort_more(stack_a, &stack_b, sort);
	//ft_print(stack_a, &stack_b);
}
