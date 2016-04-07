/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   second_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeauman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/02 13:13:16 by tbeauman          #+#    #+#             */
/*   Updated: 2016/02/03 12:17:22 by tbeauman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	fill_b_with_under_median(t_env *e)
{
	while (e->size_a > e->initsize / 2 + e->initsize % 2)
	{
		while (e->a->elem >= e->med_a)
			ra(e);
		pb(e);
	}
}

void	sort_a_in_place(t_env *e)
{
	int		i;
	int		desordre;

	i = 0;
	desordre = 1;
	while (desordre)
	{
		desordre = 0;
		while (i < e->size_a)
		{
			if (i + 1 != e->size_a && e->a->elem > e->a->next->elem)
			{
				desordre = 1;
				sa(e);
			}
			i++;
			ra(e);
		}
		i = 0;
	}
}

void	sort_b_in_place(t_env *e)
{
	int		i;
	int		desordre;

	i = 0;
	desordre = 1;
	while (desordre)
	{
		desordre = 0;
		while (i < e->size_b)
		{
			if (i + 1 != e->size_b && e->b->elem < e->b->next->elem)
			{
				desordre = 1;
				sb(e);
			}
			i++;
			rb(e);
		}
		i = 0;
	}
}

void	first_sort(t_env *e)
{
	fill_b_with_under_median(e);
	sort_a_in_place(e);
	sort_b_in_place(e);
	while (e->b)
		pa(e);
}
