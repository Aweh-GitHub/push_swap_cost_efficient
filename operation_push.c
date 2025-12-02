/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_p.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thantoni <thantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 16:59:19 by thantoni          #+#    #+#             */
/*   Updated: 2025/11/30 16:50:52 by thantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>

void	push_x(t_stack *dst, t_stack *src)
{
	t_elem	*elem;

	if (!(src->top))
		return ;
	elem = src->top;
	src->top = elem->down;
	if (src->top)
		src->top->up = NULL;
	else
		src->bot = NULL;
	src->size--;
	elem->down = dst->top;
	if (dst->top)
		dst->top->up = elem;
	else
		dst->bot = elem;
	dst->top = elem;
	elem->up = NULL;
	dst->size++;
	write(1, "p", 1);
	ft_putstr(dst->name);
	write(1, "\n", 1);
}
