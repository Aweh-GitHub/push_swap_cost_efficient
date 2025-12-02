/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_sorting.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thantoni <thantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 09:45:05 by thantoni          #+#    #+#             */
/*   Updated: 2025/11/30 16:58:15 by thantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_radix(t_stack *a, t_stack *b)
{
	size_t	byte_i;
	size_t	elem_i;
	size_t	max_bits;
	size_t	a_size;

	max_bits = 0;
	while (((a->size - 1) >> max_bits) != 0)
		max_bits++;
	byte_i = 0;
	while (byte_i < max_bits)
	{
		a_size = a->size;
		elem_i = 0;
		while (elem_i < a_size)
		{
			if ((a->top->rank >> byte_i & 1) == 0)
				push_x(b, a);
			else
				rotate_x(a, 1);
			elem_i++;
		}
		while (b->top)
			push_x(a, b);
		byte_i++;
	}
}
