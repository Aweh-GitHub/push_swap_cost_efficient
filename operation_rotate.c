/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_rotate.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thantoni <thantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 16:59:43 by thantoni          #+#    #+#             */
/*   Updated: 2025/11/30 17:13:42 by thantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>

void	rotate_x(t_stack *stack, int print)
{
	t_elem	*old_top;
	t_elem	*old_bot;

	if (!stack->top || !stack->top->down)
		return ;
	old_top = stack->top;
	old_bot = stack->bot;
	stack->top = old_top->down;
	stack->top->up = NULL;
	old_bot->down = old_top;
	old_top->up = old_bot;
	old_top->down = NULL;
	stack->bot = old_top;
	if (print)
	{
		write(1, "r", 1);
		ft_putstr(stack->name);
		write(1, "\n", 1);
	}
}

void	rotate_rotate(t_stack *a, t_stack *b)
{
	rotate_x(a, 0);
	rotate_x(b, 0);
	write(1, "rr\n", 3);
}
