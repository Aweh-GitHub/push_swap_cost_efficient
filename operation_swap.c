/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_swap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thantoni <thantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 16:40:04 by thantoni          #+#    #+#             */
/*   Updated: 2025/11/30 17:09:25 by thantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>

void	swap_x(t_stack *stack, int print)
{
	t_elem	*first;
	t_elem	*second;

	if (!stack || stack->size < 2)
		return ;
	first = stack->top;
	second = first->down;
	first->down = second->down;
	if (second->down)
		second->down->up = first;
	else
		stack->bot = first;
	second->up = NULL;
	second->down = first;
	first->up = second;
	stack->top = second;
	if (print)
	{
		write(1, "s", 1);
		ft_putstr(stack->name);
		write(1, "\n", 1);
	}
}

void	swap_swap(t_stack *a, t_stack *b)
{
	swap_x(a, 0);
	swap_x(b, 0);
	write(1, "ss\n", 1);
}
