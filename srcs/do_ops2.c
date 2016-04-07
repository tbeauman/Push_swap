/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_ops2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeauman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/01 16:35:33 by tbeauman          #+#    #+#             */
/*   Updated: 2016/02/02 10:05:34 by tbeauman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rb(t_env *e)
{
	rotate_pile(&(e->b));
	if (e->first_shot)
	{
		ft_putstr("rb");
		e->first_shot = 0;
	}
	else
		ft_putstr(" rb");
	if (e->debug_mode)
		debug(e);
}

void	rra(t_env *e)
{
	revrotate_pile(&(e->a));
	if (e->first_shot)
	{
		ft_putstr("rra");
		e->first_shot = 0;
	}
	else
		ft_putstr(" rra");
	if (e->debug_mode)
		debug(e);
}

void	rrb(t_env *e)
{
	revrotate_pile(&(e->b));
	if (e->first_shot)
	{
		ft_putstr("rrb");
		e->first_shot = 0;
	}
	else
		ft_putstr(" rrb");
	if (e->debug_mode)
		debug(e);
}

void	rr(t_env *e)
{
	rotate_pile(&(e->a));
	rotate_pile(&(e->b));
	if (e->first_shot)
	{
		ft_putstr("rr");
		e->first_shot = 0;
	}
	else
		ft_putstr(" rr");
	if (e->debug_mode)
		debug(e);
}

void	rrr(t_env *e)
{
	revrotate_pile(&(e->a));
	revrotate_pile(&(e->b));
	if (e->first_shot)
	{
		ft_putstr("rrr");
		e->first_shot = 0;
	}
	else
		ft_putstr(" rrr");
	if (e->debug_mode)
		debug(e);
}
