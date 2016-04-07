/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_fcts.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeauman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/26 20:02:31 by tbeauman          #+#    #+#             */
/*   Updated: 2016/02/02 20:13:09 by tbeauman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_putpile(t_pile *a)
{
	ft_putstr("TOP|| ");
	while (a)
	{
		ft_putnbr(a->elem);
		ft_putchar(' ');
		a = a->next;
	}
	ft_putstr("||BOT\n");
}

void	debug(t_env *e)
{
	ft_putstr("\n\033[32mpile a:");
	ft_putpile(e->a);
	ft_putstr("\033[0m\033[33mpile b:");
	ft_putpile(e->b);
	ft_putstr("\033[0m");
}
