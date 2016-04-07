/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pile_tools2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeauman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/02 11:04:54 by tbeauman          #+#    #+#             */
/*   Updated: 2016/02/03 12:14:19 by tbeauman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_pile	*piledup(t_pile *p)
{
	t_pile	*ret;

	ret = NULL;
	while (p)
	{
		add_elem(&ret, p->elem);
		p = p->next;
	}
	return (ret);
}

t_pile	*bubble_sort(t_pile *p)
{
	int		desordre;
	t_pile	*bgn;
	t_pile	*ret;

	ret = piledup(p);
	bgn = ret;
	desordre = 1;
	while (desordre)
	{
		desordre = 0;
		while (ret->next)
		{
			if (ret->elem > ret->next->elem)
			{
				desordre = ret->elem;
				ret->elem = ret->next->elem;
				ret->next->elem = desordre;
				desordre = 1;
			}
			ret = ret->next;
		}
		ret = bgn;
	}
	return (ret);
}

void	ft_piledel(t_pile **p)
{
	t_pile	*tmp;
	t_pile	*tmp2;

	tmp = *p;
	while (tmp)
	{
		tmp2 = tmp->next;
		free(tmp);
		tmp = tmp2;
	}
	*p = NULL;
}

int		check_pile(t_pile *p)
{
	t_pile	*cpy;

	if (!p)
		return (0);
	cpy = p->next;
	while (p->next)
	{
		while (cpy)
		{
			if (cpy->elem == p->elem)
				return (0);
			cpy = cpy->next;
		}
		p = p->next;
		cpy = p->next;
	}
	return (1);
}

int		get_ind_swap(t_pile *a)
{
	int		i;

	i = 0;
	while (a->next)
	{
		if (a->elem > a->next->elem)
			return (i);
		a = a->next;
		i++;
	}
	return (-1);
}
