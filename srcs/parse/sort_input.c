/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrasson <lfrasson@student.42sp.org.b      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 18:18:06 by lfrasson          #+#    #+#             */
/*   Updated: 2021/06/05 14:49:20 by lfrasson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_list_to_array(t_list	**list, int **sort)
{
	int		size;
	int		*number;
	int		*array;
	t_list	*tmp;

	size = ft_lstsize(*list);
	array = ft_calloc(size + 1, sizeof(int));
	*sort = array;
	tmp = *list;
	while (tmp)
	{
		number = tmp->content;
		*array = *number;
		array++;
		tmp = tmp->next;
	}
}

void	ft_add_number_sorting(t_list *new, t_list **list)
{
	t_list	*tmp;
	t_list	*previous;

	tmp = *list;
	previous = *list;
	while (tmp)
	{
		if (*(int *)(new->content) == *(int *)(tmp->content))
			ft_error_exit();
		if (*(int *)(new->content) < *(int *)(tmp->content))
		{
			new->next = tmp;
			if (tmp == *list)
				*list = new;
			else
				previous->next = new;
			return ;
		}
		previous = tmp;
		tmp = tmp->next;
	}
	ft_lstadd_back(list, new);
}
