/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeauman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/26 18:17:26 by tbeauman          #+#    #+#             */
/*   Updated: 2016/02/03 13:58:09 by tbeauman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_error(char *msg)
{
	ft_putstr_fd(msg, 2);
	exit(1);
}

int		parse_flags(t_env *e, int ac, char **av)
{
	int		i;
	int		j;

	i = 1;
	while (i < ac && is_flags(av[i]))
	{
		j = 1;
		while (av[i][j])
		{
			if (av[i][j] == 'd')
				e->debug_mode = 1;
			j++;
		}
		i++;
	}
	return (i);
}

void	init_env(t_env *e, int ac, char **av)
{
	int		i;

	e->debug_mode = 0;
	i = parse_flags(e, ac, av);
	e->a = NULL;
	e->b = NULL;
	while (i < ac)
	{
		add_elem(&(e->a), ft_atoi(av[i]));
		i++;
	}
	e->size_a = pile_size(e->a);
	e->initsize = e->size_a;
	if (e->a)
	{
		e->med_a = pile_median(e->a);
		e->nb_swap = check_swaps(e);
		e->nb_rotates = check_rotate(e);
	}
	e->size_b = 0;
	e->first_shot = 1;
}

int		main(int ac, char **av)
{
	t_env	e;

	check_args(ac, av);
	init_env(&e, ac, av);
	if (e.debug_mode)
		debug(&e);
	if (check_pile(e.a) == 0)
		ft_error("Error\n");
	if (is_sorted(e.a))
		return (1);
	else if (e.nb_rotates != 0)
		only_rotate(&e);
	else if (e.nb_swap == 1)
		only_swaps(&e);
	else if (e.initsize <= 6)
		little_sort(&e);
	else
		second_sort(&e);
	ft_putchar('\n');
}
