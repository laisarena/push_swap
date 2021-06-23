/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrasson <lfrasson@student.42sp.org.b      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 10:39:42 by lfrasson          #+#    #+#             */
/*   Updated: 2021/06/23 17:04:34 by lfrasson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SORT_H
# define SORT_H

# include "../operations/operations.h"

typedef struct s_pivot
{
	int	index;
	int	value;
	int	qtd;
	int	group;
	int	first;
}	t_pivot;

void	ft_sort(t_stack *stack_a, int *sort);
void	ft_sort_all(t_stack *stack_a, t_stack *stack_b, int *sort, int first);
void	ft_sort_three(t_stack *stack_a, int *sort);
void	ft_second_level(t_stack *stack_a,
			t_stack *stack_b,
			int *sort, t_pivot first_pivot);
void	ft_return_to_b(t_stack *stack_a,
			t_stack *stack_b,
			int *sort, t_pivot pivot);
void	ft_return_stack(t_stack *stack_a,
			t_stack *stack_b,
			t_pivot pivot, int *sort);

#endif
