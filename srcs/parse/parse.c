/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrasson <lfrasson@student.42sp.org.b      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 16:41:52 by lfrasson          #+#    #+#             */
/*   Updated: 2021/05/27 17:32:41 by lfrasson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_is_string_number(char *string)
{
	if (*string == '-')
		string++;
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

static void	ft_parse_input(char **input)
{
	int number;

	while (*input)
	{
		if (!ft_parse_number(*input++, &number))
			ft_error_exit();
	}
}

void	ft_parse(int argc, char **argv)
{
	char	**input;

	if (argc == 1)
		ft_error_exit();
	if (argc > 2)
		ft_parse_input(argv + 1);
	else
	{
		input = ft_split(argv[1], ' ');
		ft_parse_input(input);
		ft_free_char_2pointer(input);
	}
}
