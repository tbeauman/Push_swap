/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeauman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/26 19:42:23 by tbeauman          #+#    #+#             */
/*   Updated: 2016/02/03 13:58:54 by tbeauman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		seek_min_index(t_pile *p)
{
	int		min;
	int		pindex;
	int		ret;
	int		psize;

	psize = pile_size(p);
	min = p->elem;
	ret = 0;
	pindex = 0;
	while (p)
	{
		if (p->elem < min)
		{
			min = p->elem;
			ret = pindex;
		}
		if (p->elem == min && (ABS(psize / 2 - ret) < ABS(psize / 2 - pindex)))
			ret = pindex;
		p = p->next;
		pindex++;
	}
	return (ret);
}

void	second_sort(t_env *e)
{
	int		i_min;

	i_min = 0;
	while (e->size_a)
	{
		i_min = seek_min_index(e->a);
		if (i_min > 1 + e->size_a / 2)
			while (i_min++ < e->size_a)
				rra(e);
		else
			while (i_min-- > 0)
				ra(e);
		pb(e);
	}
	while (e->size_b)
		pa(e);
}
