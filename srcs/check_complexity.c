/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_complexity.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeauman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/03 10:59:27 by tbeauman          #+#    #+#             */
/*   Updated: 2016/02/03 13:43:09 by tbeauman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		check_swaps(t_env *e)
{
	t_pile	*tmp;
	int		nb_swaps;

	tmp = e->a;
	nb_swaps = 0;
	while (tmp->next)
	{
		if (tmp->elem > tmp->next->elem)
			nb_swaps++;
		tmp = tmp->next;
	}
	return (nb_swaps);
}

int		check_rotate(t_env *e)
{
	t_pile	*a;
	int		first;
	int		last_i;

	a = e->a;
	first = a->elem;
	last_i = 0;
	while (a->next)
	{
		if (a->elem > a->next->elem)
		{
			a = a->next;
			break ;
		}
		last_i++;
		a = a->next;
	}
	while (a->next)
	{
		if (a->elem > first || a->elem > a->next->elem)
			return (0);
		a = a->next;
	}
	return (a->elem < first ? last_i + 1 : 0);
}
