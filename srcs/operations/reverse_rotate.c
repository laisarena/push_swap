/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrasson <lfrasson@student.42sp.org.b      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 22:24:52 by lfrasson          #+#    #+#             */
/*   Updated: 2021/06/01 22:30:18 by lfrasson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"

static void	ft_rev_rotate(t_stack **start)
{
	*start = (*start)->prev;
}

void	ft_rev_rotate_a(t_stack **stack_a)
{
	ft_rev_rotate(stack_a);
	ft_putstr_fd(REV_ROTATE_A, 1);
}

void	ft_rev_rotate_b(t_stack **stack_b)
{
	ft_rev_rotate(stack_b);
	ft_putstr_fd(REV_ROTATE_B, 1);
}

void	ft_double_rev_rotate(t_stack **stack_a, t_stack **stack_b)
{
	ft_rev_rotate(stack_a);
	ft_rev_rotate(stack_b);
	ft_putstr_fd(REV_ROTATE, 1);
}
