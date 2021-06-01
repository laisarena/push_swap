/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrasson <lfrasson@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 17:14:36 by lfrasson          #+#    #+#             */
/*   Updated: 2021/06/01 17:18:48 by lfrasson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

void ft_connect(t_stack *first, t_stack *second)
{
	first->next = second;
	second->prev = first;
}

t_stack	*ft_new_stack_node(int element)
{
	t_stack	*node;

	node = malloc(sizeof(t_stack));
	if (!node)
		return (NULL);
	node->element = element;
	node->prev = NULL;
	node->next = NULL;
	return (node);
}

t_stack		*ft_stack_pop(t_stack **stack)
{
	t_stack	*node;
	t_stack	*last;

	node = *stack;
	if (!node)
		return (NULL);
	*stack = node->next;
	last = node->prev;
	ft_connect(last, *stack);
	node->prev = NULL;
	node->next = NULL;
	return (node);
}

void	ft_stack_push(t_stack **stack, t_stack *node)
{
	t_stack	*last;

	if (!*stack)
		ft_connect(node, node);
	else
	{
		last = (*stack)->prev;
		ft_connect(last, node);
		ft_connect(node, *stack);
	}
	*stack = node;
}
