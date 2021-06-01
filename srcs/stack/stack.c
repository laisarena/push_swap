/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrasson <lfrasson@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 17:14:36 by lfrasson          #+#    #+#             */
/*   Updated: 2021/05/31 17:10:21 by lfrasson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

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
	last->next = *stack;
	(*stack)->prev = last;
	node->prev = NULL;
	node->next = NULL;
	return (node);
}

void	ft_stack_push(t_stack **stack, t_stack *node)
{
	t_stack	*last;

	if (!*stack)
	{
		node->prev = node;
		node->next = node;
	}
	else
	{
		last = (*stack)->prev;
		last->next = node;
		node->prev = last;
		node->next = *stack;
		(*stack)->prev = node;
	}
	*stack = node;
}
