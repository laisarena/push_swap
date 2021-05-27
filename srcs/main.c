/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrasson <lfrasson@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 23:42:17 by lfrasson          #+#    #+#             */
/*   Updated: 2021/05/26 23:06:07 by lfrasson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "stdio.h"

static void	ft_error_exit(void)
{
	ft_putstr_fd("Error\n", 2);
	exit(-1);
}

static void	ft_free_null(void *pointer)
{
	if (pointer)
		free(pointer);
	pointer = NULL;
}

static void	ft_free_char_2pointer(char **pointer)
{
	int	i;

	i = 0;
	if (!pointer)
		return ;
	while (pointer[i])
		ft_free_null(pointer[i++]);
	ft_free_null(pointer);
}

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

static void	ft_parse(int argc, char **argv)
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

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack *stack_b;
	t_stack *node;
	//int		**sort;

	stack_a = NULL;
	stack_b = NULL;

	ft_parse(argc, argv);
	//Check if already sorted
	//Initialize stack a with input 

	ft_stack_push(&stack_a, ft_new_stack_node(5));
	node = ft_stack_pop(&stack_a);
	ft_stack_push(&stack_b, node);
	free(node);
	return(0);
}
