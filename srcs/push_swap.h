/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrasson <lfrasson@student.42sp.org.b      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/23 19:07:53 by lfrasson          #+#    #+#             */
/*   Updated: 2021/06/03 10:41:24 by lfrasson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h" 
# include "stack/stack.h"
# include "operations/operations.h"
# include "sort/sort.h"
# include <limits.h>

# define FALSE		0
# define TRUE		1
# define SUCCESS	0
# define FAIL		-1

void	ft_parse(int argc, char **argv, t_list **reverse_input, int *sort);
void	ft_add_number_sorting(t_list *new, t_list **list);
void	ft_list_to_array(t_list	**list, int *sort);
void	ft_free_char_2pointer(char **pointer);
void	ft_free_null(void *pointer);
void	ft_error_exit(void);

#endif
