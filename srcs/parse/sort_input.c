/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrasson <lfrasson@student.42sp.org.b      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 18:18:06 by lfrasson          #+#    #+#             */
/*   Updated: 2021/05/27 21:24:01 by lfrasson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_list_to_array(t_list	**list, int *sort)
{
	int		size;
	int		*number;
	t_list	*tmp;

	size = ft_lstsize(*list);
	sort = ft_calloc(sizeof(int), size + 1);
	tmp = *list;
	while (tmp)
	{
		number = tmp->content;
		*sort = *number;
		sort++;
		tmp = tmp->next;
	}
}

void	ft_add_number_to_list(t_list *new, t_list **list)
{
	t_list	*tmp;
	t_list	*previous;
	int		*number;
	int		*new_number;

	tmp = *list;
	previous = *list;
	while (tmp)
	{
		number = (int *)tmp->content;
		new_number = (int *)new->content;
		if (*new_number == *number)
			ft_error_exit();
		if (*new_number < *number)
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
