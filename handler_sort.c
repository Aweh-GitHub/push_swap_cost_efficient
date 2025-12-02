/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thantoni <thantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 17:02:47 by thantoni          #+#    #+#             */
/*   Updated: 2025/11/30 17:13:35 by thantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_sorted(t_stack *stack)
{
	t_elem	*current;

	if (!stack || stack->size <= 1)
		return (1);
	current = stack->top;
	while (current->down)
	{
		if (current->rank > current->down->rank)
			return (0);
		current = current->down;
	}
	return (1);
}

void	handle_sorting(t_stack *a, t_stack *b)
{
	if (!a || a->size <= 1)
		return ;
	if (is_sorted(a))
		return ;
	if (a->size == 2)
		sort_two(a);
	else if (a->size == 3)
		sort_three(a);
	else if (a->size <= 5)
		sort_four_five(a, b);
	else
		sort_radix(a, b);
}
