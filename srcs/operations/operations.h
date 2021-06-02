/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrasson <lfrasson@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 23:15:10 by lfrasson          #+#    #+#             */
/*   Updated: 2021/06/01 22:21:16 by lfrasson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPERATIONS_H
# define OPERATIONS_H

# include "../stack/stack.h"

# define SWAP_A			"sa\n"
# define SWAP_B			"sb\n"
# define SWAP			"ss\n"
# define PUSH_A			"pa\n"
# define PUSH_B			"pb\n"
# define ROTATE_A		"ra\n"
# define ROTATE_B		"rb\n"
# define ROTATE			"rr\n"
# define REV_ROTATE_A	"rra\n"
# define REV_ROTATE_B	"rrb\n"
# define REV_ROTATE		"rr\n"

void	ft_swap_a(t_stack **stack_a);
void	ft_swap_b(t_stack **stack_b);
void	ft_double_swap(t_stack **stack_a, t_stack **stack_b);
void	ft_push_a(t_stack **stack_a, t_stack **stack_b);
void	ft_push_b(t_stack **stack_a, t_stack **stack_b);
void	ft_rotate_a(t_stack **stack_a);
void	ft_rotate_b(t_stack **stack_b);
void	ft_double_rotate(t_stack **stack_a, t_stack **stack_b);

#endif
