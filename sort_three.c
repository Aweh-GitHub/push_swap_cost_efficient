/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thantoni <thantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 17:16:05 by thantoni          #+#    #+#             */
/*   Updated: 2025/11/30 17:17:48 by thantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_stack *a)
{
	int	top;
	int	mid;
	int	bot;

	top = a->top->rank;
	mid = a->top->down->rank;
	bot = a->bot->rank;
	if (top > mid && mid < bot && top < bot)
		swap_x(a, 1);
	else if (top > mid && mid > bot)
	{
		swap_x(a, 1);
		rev_rotate_x(a, 1);
	}
	else if (top > mid && mid < bot && top > bot)
		rotate_x(a, 1);
	else if (top < mid && mid > bot && top < bot)
	{
		swap_x(a, 1);
		rotate_x(a, 1);
	}
	else if (top < mid && mid > bot && top > bot)
		rev_rotate_x(a, 1);
}
