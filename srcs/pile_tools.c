/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pile_tools.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeauman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/26 18:29:41 by tbeauman          #+#    #+#             */
/*   Updated: 2016/02/03 13:59:21 by tbeauman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	add_elem(t_pile **p, int elem)
{
	t_pile	*bgn;
	t_pile	*new;

	bgn = *p;
	if (!(new = (t_pile*)malloc(sizeof(t_pile))))
		return ;
	new->elem = elem;
	new->next = NULL;
	if (!*p)
		*p = new;
	else
	{
		while ((*p)->next)
			*p = (*p)->next;
		(*p)->next = new;
		*p = bgn;
	}
}

int		pile_size(t_pile *p)
{
	int		i;

	i = 0;
	while (p)
	{
		i++;
		p = p->next;
	}
	return (i);
}

int		is_sorted(t_pile *p)
{
	while (p && p->next)
	{
		if (p->elem > p->next->elem)
			return (0);
		p = p->next;
	}
	return (1);
}

int		seek_max_index(t_pile *p)
{
	int		max;
	int		pindex;
	int		ret;
	int		psize;

	psize = pile_size(p);
	max = p->elem;
	ret = 0;
	pindex = 0;
	while (p)
	{
		if (p->elem > max)
		{
			max = p->elem;
			ret = pindex;
		}
		p = p->next;
		pindex++;
	}
	return (ret);
}

int		pile_median(t_pile *p)
{
	int		len;
	int		ind;
	t_pile	*tmp;

	ind = 0;
	len = pile_size(p);
	tmp = bubble_sort(p);
	while (ind < len / 2)
	{
		ind++;
		tmp = tmp->next;
	}
	len = tmp->elem;
	ft_piledel(&tmp);
	return (len);
}
