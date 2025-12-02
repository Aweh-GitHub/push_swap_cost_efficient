/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isnb.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thantoni <thantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 09:20:05 by thantoni          #+#    #+#             */
/*   Updated: 2025/11/30 17:09:54 by thantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <limits.h>

int	ft_isnb(char *s)
{
	size_t		i;
	long int	nb;
	long int	sign;

	if (s == NULL)
		return (0);
	i = 0;
	sign = 1;
	if (s[0] == '-' || s[0] == '+')
	{
		if (!(s[1] >= '0' && s[1] <= '9'))
			return (0);
		i++;
		if (s[0] == '-')
			sign = -sign;
	}
	nb = 0;
	while (s[i])
	{
		if (!(s[i] >= '0' && s[i] <= '9'))
			return (0);
		nb = nb * 10 + (s[i] - '0');
		i++;
	}
	return (nb * sign <= INT_MAX && nb * sign >= INT_MIN);
}
