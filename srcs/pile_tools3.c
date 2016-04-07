/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pile_tools3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeauman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/03 12:58:46 by tbeauman          #+#    #+#             */
/*   Updated: 2016/02/03 13:11:55 by tbeauman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		get_max(t_pile *a)
{
	int		max;

	if (!a)
		return (0);
	max = a->elem;
	while (a)
	{
		if (a->elem > max)
			max = a->elem;
		a = a->next;
	}
	return (max);
}

int		get_min(t_pile *a)
{
	int		min;

	if (!a)
		return (0);
	min = a->elem;
	while (a)
	{
		if (a->elem < min)
			min = a->elem;
		a = a->next;
	}
	return (min);
}
