/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeauman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/27 14:55:58 by tbeauman          #+#    #+#             */
/*   Updated: 2016/02/01 16:40:48 by tbeauman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_pile(t_pile **pile)
{
	int		tamp;

	tamp = (*pile)->elem;
	if (!*pile || !(*pile)->next)
		return ;
	(*pile)->elem = (*pile)->next->elem;
	(*pile)->next->elem = tamp;
}

void	push_pile(t_pile **a, t_pile **b)
{
	t_pile	*tamp;

	if (!*a)
		return ;
	tamp = (*a)->next;
	(*a)->next = *b;
	*b = *a;
	*a = tamp;
}

void	rotate_pile(t_pile **a)
{
	t_pile	*first;
	t_pile	*sec;

	first = *a;
	if (!first)
		return ;
	sec = (*a)->next;
	while ((*a)->next)
		*a = (*a)->next;
	(*a)->next = first;
	first->next = NULL;
	*a = sec;
}

void	revrotate_pile(t_pile **a)
{
	t_pile	*first;
	t_pile	*bef_last;

	first = *a;
	while ((*a)->next->next)
		*a = (*a)->next;
	bef_last = *a;
	*a = (*a)->next;
	(*a)->next = first;
	bef_last->next = NULL;
}
