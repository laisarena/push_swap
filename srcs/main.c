/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrasson <lfrasson@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 23:42:17 by lfrasson          #+#    #+#             */
/*   Updated: 2021/05/27 21:21:53 by lfrasson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "stdio.h"

void	ft_error_exit(void)
{
	ft_putstr_fd("Error\n", 2);
	exit(-1);
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack *stack_b;
	t_stack *node;
	int		*sort;

	stack_a = NULL;
	stack_b = NULL;
	sort = NULL;

	ft_parse(argc, argv, sort);
	//Check if already sorted
	//Initialize stack a with input 

	ft_stack_push(&stack_a, ft_new_stack_node(5));
	node = ft_stack_pop(&stack_a);
	ft_stack_push(&stack_b, node);
	free(node);
	return(0);
}
