/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_four_five.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thantoni <thantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 16:59:04 by thantoni          #+#    #+#             */
/*   Updated: 2025/11/30 17:16:42 by thantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_elem	*find_min(t_stack *stack)
{
	t_elem	*current;
	t_elem	*min;

	current = stack->top;
	min = current;
	while (current)
	{
		if (current->rank < min->rank)
			min = current;
		current = current->down;
	}
	return (min);
}

static int	get_position(t_stack *stack, t_elem *elem)
{
	t_elem	*current;
	int		pos;

	current = stack->top;
	pos = 0;
	while (current)
	{
		if (current == elem)
			return (pos);
		current = current->down;
		pos++;
	}
	return (-1);
}

static void	push_min_to_b(t_stack *a, t_stack *b)
{
	t_elem	*min;
	int		pos;
	int		i;

	min = find_min(a);
	pos = get_position(a, min);
	i = 0;
	if (pos <= (int)a->size / 2)
	{
		while (i++ < pos)
			rotate_x(a, 1);
	}
	else
	{
		while (i++ < (int)a->size - pos)
			rev_rotate_x(a, 1);
	}
	push_x(b, a);
}

void	sort_four_five(t_stack *a, t_stack *b)
{
	push_min_to_b(a, b);
	push_min_to_b(a, b);
	sort_three(a);
	push_x(a, b);
	push_x(a, b);
}
