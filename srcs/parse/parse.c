/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrasson <lfrasson@student.42sp.org.b      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 16:41:52 by lfrasson          #+#    #+#             */
/*   Updated: 2021/06/24 15:42:13 by lfrasson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_is_string_number(char *string)
{
	if (*string == '-')
		string++;
	if (!(*string))
		return (FALSE);
	while (*string)
		if (!ft_isdigit(*string++))
			return (FALSE);
	return (TRUE);
}

static int	ft_is_integer(long number)
{
	if (number > INT_MAX)
		return (FALSE);
	if (number < INT_MIN)
		return (FALSE);
	return (TRUE);
}

static int	ft_parse_number(char *str_number, int *number)
{
	long	lnumber;

	if (!ft_is_string_number(str_number))
		return (FALSE);
	lnumber = atol(str_number);
	*number = (int)lnumber;
	return (ft_is_integer(lnumber));
}

static void	ft_parse_input(char **input, t_list **reverse_input, int **sort)
{
	int		*number;
	t_list	*sorted_list;

	sorted_list = NULL;
	while (*input)
	{
		number = malloc(sizeof(int));
		if (!ft_parse_number(*input++, number))
			ft_error_exit();
		ft_add_number_sorting(ft_lstnew(number), &sorted_list);
		ft_lstadd_front(reverse_input, ft_lstnew(number));
	}
	ft_list_to_array(&sorted_list, sort);
	ft_free_list(&sorted_list);
}

void	ft_parse(int argc, char **argv, t_list **reverse_input, int **sort)
{
	char	**input;

	if (argc == 1)
		exit(0);
	if (argc > 2)
		ft_parse_input(argv + 1, reverse_input, sort);
	else
	{
		input = ft_split(argv[1], ' ');
		ft_parse_input(input, reverse_input, sort);
		ft_free_char_2pointer(input);
	}
}
