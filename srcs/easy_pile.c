/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easy_pile.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeauman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/03 11:07:54 by tbeauman          #+#    #+#             */
/*   Updated: 2016/02/03 14:12:28 by tbeauman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	only_swaps(t_env *e)
{
	int		i_swap;
	int		cpt;

	i_swap = 0;
	while (i_swap != -1)
	{
		i_swap = get_ind_swap(e->a);
		cpt = i_swap;
		while (cpt <= e->size_a / 2 ? cpt-- > 0 : cpt++ < e->size_a)
			i_swap <= e->size_a / 2 ? ra(e) : rra(e);
		if (e->a->elem > e->a->next->elem)
			sa(e);
		cpt = i_swap;
		while (cpt <= e->size_a / 2 ? cpt-- > 0 : cpt++ < e->size_a)
			i_swap <= e->size_a / 2 ? rra(e) : ra(e);
	}
}

void	only_rotate(t_env *e)
{
	if (e->nb_rotates <= e->size_a / 2)
		while (e->nb_rotates-- > 0)
			ra(e);
	else
		while (e->nb_rotates++ < e->size_a)
			rra(e);
}

void	sort_a(t_env *e)
{
	int		max_i;

	max_i = seek_max_index(e->a);
	if (max_i == 0)
		ra(e);
	if (max_i == 1)
		rra(e);
	if (e->a->elem > e->a->next->elem)
		sa(e);
}

void	sort_b(t_env *e)
{
	int		max_i;

	if (e->size_b == 1)
		return ;
	if (e->size_b == 2)
	{
		if (e->b->elem > e->b->next->elem)
			sb(e);
		return ;
	}
	else if (e->size_b == 3)
	{
		max_i = seek_max_index(e->b);
		if (max_i == 0)
			rb(e);
		if (max_i == 1)
			rrb(e);
		if (e->b->elem > e->b->next->elem)
			sb(e);
	}
}

void	little_sort(t_env *e)
{
	int		max;
	int		min;

	while (e->size_a > 3)
		pb(e);
	sort_a(e);
	sort_b(e);
	while (e->b)
	{
		max = get_max(e->a);
		min = get_min(e->a);
		if (e->b->elem < e->a->elem || (e->b->elem > max && e->a->elem == min))
			pa(e);
		ra(e);
	}
	min = get_min(e->a);
	while (e->a->elem != min)
		ra(e);
}
