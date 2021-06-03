/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrasson <lfrasson@student.42sp.org.b      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 10:34:17 by lfrasson          #+#    #+#             */
/*   Updated: 2021/06/03 10:55:41 by lfrasson         ###   ########.fr       */
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

static void	ft_sort_two(t_stack *stack_a)
{
	if (stack_a->size == 2)
		ft_swap_a(stack_a);
}

void	ft_sort(t_stack *stack_a, int *sort)
{
	t_stack stack_b;
	
	ft_new_stack(&stack_b);
	ft_print(stack_a, &stack_b);
	//ft_test(stack_a, &stack_b);
	ft_sort_two(stack_a);
	(void)sort[0];
	ft_print(stack_a, &stack_b);
}
