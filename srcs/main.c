/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrasson <lfrasson@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 23:42:17 by lfrasson          #+#    #+#             */
/*   Updated: 2021/06/02 18:34:36 by lfrasson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "stdio.h"

void	ft_error_exit(void)
{
	ft_putstr_fd("Error\n", 2);
	exit(-1);
}

int	ft_is_already_sort(t_list *list)
{
	int	*number;
	int	*next_number;

	number = list->content;
	list = list->next;
	while (list)
	{
		next_number =  (int *)list->content;
		if (*number < *next_number)
			return (FALSE);
		number = next_number;
		list = list->next;
	}

	ft_lstclear(&list, ft_free_null);
	return (TRUE);
}

void	ft_initialize_stack_a(t_stack *stack_a, t_list *reverse_input)
{
	int	*number;

	while(reverse_input)
	{
		number = reverse_input->content;
		ft_stack_push(stack_a, ft_new_stack_node(*number));
		reverse_input = reverse_input->next;
	}
}

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

int	main(int argc, char **argv)
{
	t_stack	stack_a;
	t_stack stack_b;
	t_list	*reverse_input;
	int		*sort;

	ft_new_stack(&stack_a);
	ft_new_stack(&stack_b);
	reverse_input = NULL;
	sort = NULL;

	ft_parse(argc, argv, &reverse_input, sort);
	if(ft_is_already_sort(reverse_input))
		return (SUCCESS);
	ft_initialize_stack_a(&stack_a, reverse_input);
	ft_lstclear(&reverse_input, ft_free_null);
	ft_print(&stack_a, &stack_b);
	ft_test(&stack_a, &stack_b);
	return(SUCCESS);
}
