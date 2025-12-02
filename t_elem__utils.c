/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_elem__utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thantoni <thantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 09:46:57 by thantoni          #+#    #+#             */
/*   Updated: 2025/11/30 18:00:50 by thantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

t_elem	*t_elem__new(int value, int rank, t_elem *next, t_elem *prev)
{
	t_elem	*elem;

	elem = malloc(sizeof(t_elem));
	elem->rank = rank;
	elem->value = value;
	elem->up = next;
	elem->down = prev;
	return (elem);
}

t_elem	*t_elem__unlink(t_elem *elem)
{
	if (elem == NULL)
		return (elem);
	if (elem->down != NULL)
		elem->down->up = elem->up;
	if (elem->up != NULL)
		elem->up->down = elem->down;
	return (elem);
}
