/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrasson <lfrasson@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 23:42:17 by lfrasson          #+#    #+#             */
/*   Updated: 2021/05/23 19:48:42 by lfrasson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(void)
{
	t_stack	*stack_a;
	t_stack *stack_b;

	stack_a = NULL;
	stack_b = NULL;

	//Parse input
	//Initialize stack a with input 

	ft_stack_push(&stack_a, ft_new_stack_node(5));
	ft_stack_push(&stack_b, ft_new_stack_node(6));
	return(0);
}
