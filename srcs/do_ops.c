/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_ops.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeauman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/01 16:21:14 by tbeauman          #+#    #+#             */
/*   Updated: 2016/02/02 10:21:53 by tbeauman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_env *e)
{
	push_pile(&(e->b), &(e->a));
	e->size_b--;
	e->size_a++;
	if (e->first_shot)
	{
		ft_putstr("pa");
		e->first_shot = 0;
	}
	else
		ft_putstr(" pa");
	if (e->debug_mode)
		debug(e);
}

void	pb(t_env *e)
{
	push_pile(&(e->a), &(e->b));
	e->size_a--;
	e->size_b++;
	if (e->first_shot)
	{
		ft_putstr("pb");
		e->first_shot = 0;
	}
	else
		ft_putstr(" pb");
	if (e->debug_mode)
		debug(e);
}

void	sa(t_env *e)
{
	swap_pile(&(e->a));
	if (e->first_shot)
	{
		ft_putstr("sa");
		e->first_shot = 0;
	}
	else
		ft_putstr(" sa");
	if (e->debug_mode)
		debug(e);
}

void	sb(t_env *e)
{
	swap_pile(&(e->b));
	if (e->first_shot)
	{
		ft_putstr("sb");
		e->first_shot = 0;
	}
	else
		ft_putstr(" sb");
	if (e->debug_mode)
		debug(e);
}

void	ra(t_env *e)
{
	rotate_pile(&(e->a));
	if (e->first_shot)
	{
		ft_putstr("ra");
		e->first_shot = 0;
	}
	else
		ft_putstr(" ra");
	if (e->debug_mode)
		debug(e);
}
