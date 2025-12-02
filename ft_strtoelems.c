/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtoelems.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thantoni <thantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 09:45:01 by thantoni          #+#    #+#             */
/*   Updated: 2025/11/26 11:00:22 by thantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_elem	*ft_strtoelems(char **values)
{
	t_elem	*first_elem;
	t_elem	*upper_elem;
	size_t	i;

	if (values == NULL)
		return (NULL);
	first_elem = t_elem__new(ft_atoi(values[0]), 0, NULL, NULL);
	upper_elem = first_elem;
	i = 1;
	while (values[i])
	{
		upper_elem->down = t_elem__new(ft_atoi(values[i]), 0, upper_elem, NULL);
		upper_elem = upper_elem->down;
		i++;
	}
	return (first_elem);
}
