/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrasson <lfrasson@student.42sp.org.b      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/23 19:07:53 by lfrasson          #+#    #+#             */
/*   Updated: 2021/06/05 14:28:21 by lfrasson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h" 
# include "stack/stack.h"
# include "operations/operations.h"
# include "sort/sort.h"
# include <limits.h>

void	ft_parse(int argc, char **argv, t_list **reverse_input, int **sort);
void	ft_add_number_sorting(t_list *new, t_list **list);
void	ft_list_to_array(t_list	**list, int **sort);
void	ft_free_char_2pointer(char **pointer);
void	ft_free_list(t_list **lst);
void	ft_free_null(void *pointer);
void	ft_error_exit(void);

#endif
