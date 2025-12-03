/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_benchmarked.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thantoni <thantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 09:34:47 by thantoni          #+#    #+#             */
/*   Updated: 2025/12/02 11:46:58 by thantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		is_sorted(t_stack *stack)
{
	t_elem	*elem;

	elem = stack->top;
	while (elem != NULL)
	{
		if (elem->up != NULL && elem->rank > elem->up->rank)
			return (FALSE);
		elem = elem->down;
	}
	return (TRUE);
}

int get_LIS(t_stack *stack, t_elem **LIS_start, t_elem **LIS_end)
{
	t_elem	*ref_start;
	t_elem	*ref_end;
	size_t	best_score;
	size_t	current_score;

	ref_start = stack->top;
	ref_end = ref_start->down;
	best_score = 0;
	while (ref_start != NULL)
	{
		if (ref_end->rank < ref_end->down->rank)
		{
			current_score++;
			ref_end = ref_start->down;
			continue;
		}
		else if (current_score > best_score)
		{
			*LIS_start = ref_start;
			*LIS_end = ref_end;
			best_score = current_score;
		}
		ref_start = ref_end->down;
	}
	return (best_score);
}
// get rotate to opti_IS
// from top (always start position)
// -> check the lowest value at PUSH_OPTI_DIST_IS = 1

static int	get_opti_IS_top_down(t_stack *stack, t_elem **lowest_elem)
{
	t_elem	*elem;
	int		dist;
	int		lowest;
	int		dist_to_lowest;
	
	lowest = -1;
	elem = stack->top;
	dist = 0;
	while (elem != NULL && dist < 0)
	{
		if (lowest == -1 || elem->rank < lowest)
		{
			*lowest_elem = elem->rank;
			dist_to_lowest = dist;
		}
		elem = elem->down;
		dist++;	
	}
	return (dist_to_lowest);
}

static int	get_opti_IS_bot_up(t_stack *stack, t_elem **lowest_elem)
{
	t_elem	*elem;
	int		dist;
	int		lowest;
	int		dist_to_lowest;
	
	lowest = -1;
	elem = stack->bot;
	dist = 0;
	while (elem != NULL && dist < 0)
	{
		if (lowest == -1 || elem->rank < lowest)
		{
			*lowest_elem = elem->rank;
			dist_to_lowest = dist;
		}
		elem = elem->up;
		dist++;
	}
	return (dist_to_lowest);
}

int	get_rotation_to_opti_IS(t_stack *stack, t_elem **lowest_elem)
{
	t_elem	*lowest_from_top;
	t_elem	*lowest_from_bot;
	int dist_from_top;
	int dist_from_bot;

	dist_from_top = get_opti_IS_top_down(stack, &lowest_from_top);
	dist_from_bot = get_opti_IS_bot_up(stack, &lowest_from_bot);
	if (dist_from_top == dist_from_bot)
	{
		if (lowest_from_top->rank < lowest_from_bot->rank)
			return (*lowest_elem = lowest_from_top, dist_from_top);
		return (*lowest_elem = lowest_from_bot, dist_from_bot);
	}
	if (dist_from_top < dist_from_bot)
		return (*lowest_elem = lowest_from_top, dist_from_top);
	return (*lowest_elem = lowest_from_bot, dist_from_bot);
}

// BUILD B
//

void	sort_benchmarked(t_stack *a, t_stack *b)
{
	//chink size = 5
	//a: 9, 8, 5, 4, 1, [0, 2, 3], 7, 6

	//1. envoi sorted chunk ------------------------------------------------------------------------------------

	//a: 0, 2, 3, 7, 6
	//b: 9, 8, 5, 4, 1

	//2. reinsert sorted ---------------------------------------------------------------------------------------
	//a: 0, 2, 3, 7, 6
	//b: 9,8,5,4,1

	//2.1) look at 'a' for the first: b->bot->rank < a_elem->rank
	// get distance -> distance = 1
	// ra;

	//2.2) reinsert always with rrb
	//rrb, pa
	
	//b: 9,8,5,4
	//a: 1, 2, 3, 7, 6, 0

	//b: 9,8,5,
	//a: 4, 7, 6, 0, 1, 2, 3

	//b: 9,8,
	//a: 5, 7, 6, 0, 1, 2, 3, 4

	//b: 9
	//a: 8, 6, 0, 1, 2, 3, 4, 5, 7
	
	//b:
	//a: 9, 6, 0, 1, 2, 3, 4, 5, 7, 8
	
	//3. envoi sorted chunk ------------------------------------------------------------------------------------

	// ENFT JSP ce qu'il faut faire
	// est ce que je met 0 au debut ? a la fin ? 
	// autre ? genre









	
	
	//1ere etape: trouver le plus petit en range = 3
	//2eme etape faire remonter le plus petit
	//3eme etape le push
	
	//b: , 1, 0
	


	
	//b: 4, 1, 0, 5, 3, 2
	//a: 
	
	
	
	// [6, 7, 8, 9], 3, 0, 5, 2, 1, 4,
	// Position favorable -> pas au top
	// Meilleure position -> rank = index
	// 3, 0, 5, 2, 1, 4, [6, 7, 8, 9]
	while (!is_sorted(a))
	{
		// 1. obtenir la LIS
		// 2.
			//2.a. LIS proche du top
				//si quelques elem dans 'a' avant LIS vas imposer beaucoup de rotations
			//2.b. LIS proche au milieu
				//peut PB et creer IS dans 'b'
			//2.c. LIS proche de la fin
				//peut PB et creer IS dans 'b'
		
	}
}