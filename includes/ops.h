/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeauman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/01 16:23:03 by tbeauman          #+#    #+#             */
/*   Updated: 2016/02/01 16:45:56 by tbeauman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPS_H
# define OPS_H

# include "typedefs.h"

void	swap_pile(t_pile **pile);
void	push_pile(t_pile **a, t_pile **b);
void	rotate_pile(t_pile **a);
void	revrotate_pile(t_pile **a);
void	pa(t_env *e);
void	pb(t_env *e);
void	sa(t_env *e);
void	sb(t_env *e);
void	ra(t_env *e);
void	rb(t_env *e);
void	rr(t_env *e);
void	rra(t_env *e);
void	rrb(t_env *e);
void	rrr(t_env *e);

#endif
