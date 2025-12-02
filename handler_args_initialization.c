/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_args_initialization.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thantoni <thantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 09:12:48 by thantoni          #+#    #+#             */
/*   Updated: 2025/11/30 17:14:03 by thantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>
#include <unistd.h>

static t_stack	*init_ranks(t_stack *stack)
{
	t_elem	*ref;
	t_elem	*cmp;
	int		rank;

	rank = 0;
	ref = stack->top;
	while (ref != NULL)
	{
		cmp = stack->top;
		while (cmp != NULL)
		{
			if (cmp != ref && cmp->value < ref->value)
				rank++;
			cmp = cmp->down;
		}
		ref->rank = rank;
		rank = 0;
		ref = ref->down;
	}
	return (stack);
}

static int	are_values_uniques(t_stack *stack)
{
	t_elem	*ref;
	t_elem	*cmp;

	ref = stack->top;
	while (ref != NULL)
	{
		cmp = ref->down;
		while (cmp != NULL)
		{
			if (cmp != ref && cmp->value == ref->value)
				return (0);
			cmp = cmp->down;
		}
		ref = ref->down;
	}
	return (1);
}

static int	are_all_strvalues_valid(char **str_values)
{
	size_t	i;

	if (str_values == NULL || str_values[0] == NULL)
		return (0);
	i = 0;
	while (str_values[i] != NULL)
	{
		if (!ft_isnb(str_values[i]))
			return (0);
		i++;
	}
	return (1);
}

static void	free_strvalues(char **strvalues)
{
	size_t	i;

	if (!strvalues)
		return ;
	i = 0;
	while (strvalues[i])
	{
		free(strvalues[i]);
		i++;
	}
	free(strvalues);
}

t_stack	*init_args_to_stack(char *stack_name, \
	size_t argc, char **argv)
{
	size_t	argv_i;
	char	**strvalues;
	t_stack	*stack;

	argv_i = 1;
	stack = t_stack__new(stack_name, NULL, NULL);
	while (argv_i < argc)
	{
		strvalues = ft_split(argv[argv_i], ' ');
		if (!are_all_strvalues_valid(strvalues))
		{
			write(1, "Error\n", 6);
			free_strvalues(strvalues);
			return (t_stack__free_all(stack), NULL);
		}
		stack = t_stack__addtail(stack, ft_strtoelems(strvalues));
		free_strvalues(strvalues);
		if (!are_values_uniques(stack))
		{
			write(1, "Error\n", 6);
			return (t_stack__free_all(stack), NULL);
		}
		argv_i++;
	}
	return (init_ranks(stack));
}
