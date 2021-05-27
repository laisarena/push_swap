/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrasson <lfrasson@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 17:14:36 by lfrasson          #+#    #+#             */
/*   Updated: 2021/05/26 18:57:40 by lfrasson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

t_stack	*ft_new_stack_node(int element)
{
	t_stack	*node;

	node = malloc(sizeof(t_stack));
	if (node)
		return (NULL);
	node->element = element;
	node->next = NULL;
	return (node);
}

t_stack		*ft_stack_pop(t_stack **stack)
{
	t_stack	*tmp;

	tmp =  *stack;
	if (!tmp)
		return (NULL);
	*stack = tmp->next;
	return (tmp);
}

void	ft_stack_push(t_stack **stack, t_stack *node)
{
	if (*stack)
		node->next = *stack;
	*stack = node;
}
