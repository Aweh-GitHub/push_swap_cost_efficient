/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_stack__utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thantoni <thantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 09:37:04 by thantoni          #+#    #+#             */
/*   Updated: 2025/12/02 09:10:17 by thantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

static size_t	count_and_find_last(t_elem *elem, t_elem **last)
{
	size_t	count;

	*last = elem;
	count = 1;
	while ((*last)->down != NULL)
	{
		*last = (*last)->down;
		count++;
	}
	return (count);
}

t_stack	*t_stack__new(char *name, t_elem *head, t_elem *tail)
{
	t_stack	*stack;
	t_elem	*scroll;
	size_t	elems_count;

	stack = malloc(sizeof(t_stack));
	if (stack == NULL)
		return (NULL);
	stack->name = name;
	stack->top = head;
	stack->bot = tail;
	scroll = head;
	elems_count = 0;
	while (scroll != NULL)
	{
		elems_count++;
		scroll = scroll->down;
	}
	stack->size = elems_count;
	return (stack);
}

t_stack	*t_stack__addtail(t_stack *stack, t_elem *elem)
{
	t_elem	*last;
	t_elem	*old_tail;
	size_t	added_elems_count;

	old_tail = stack->bot;
	if (old_tail != NULL)
		old_tail->down = elem;
	elem->up = old_tail;
	last = elem;
	added_elems_count = 1;
	while (last->down != NULL)
	{
		last = last->down;
		added_elems_count++;
	}
	stack->bot = last;
	if (stack->top == NULL)
		stack->top = elem;
	stack->size += added_elems_count;
	return (stack);
}

t_stack	*t_stack__addhead(t_stack *stack, t_elem *elem)
{
	t_elem	*last;
	size_t	added_count;

	added_count = count_and_find_last(elem, &last);
	if (stack->size == 0)
	{
		stack->top = elem;
		stack->bot = last;
		stack->size = added_count;
		return (stack);
	}
	stack->bot->down = elem;
	elem->up = stack->bot;
	stack->bot = last;
	stack->size += added_count;
	return (stack);
}

void	t_stack__free_all(t_stack *stack)
{
	t_elem	*scroll;
	t_elem	*to_free;

	scroll = stack->top;
	while (scroll != NULL)
	{
		to_free = scroll;
		scroll = scroll->down;
		free(to_free);
	}
	free(stack);
}
