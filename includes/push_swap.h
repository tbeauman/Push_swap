/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeauman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/26 18:18:08 by tbeauman          #+#    #+#             */
/*   Updated: 2016/02/03 13:36:30 by tbeauman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>

# include "libft.h"
# include "typedefs.h"
# include "ops.h"
# define ABS(x) x > 0 ? x : -x

void	add_elem(t_pile **p, int elem);
int		pile_size(t_pile *p);
int		is_sorted(t_pile *p);
int		seek_min_index(t_pile *p);
int		seek_max_index(t_pile *p);
void	first_sort(t_env *e);
void	second_sort(t_env *e);
void	short_sort(t_env *e);
void	ft_error(char *msg);
int		wrong_number(char *num);
void	check_args(int ac, char **av);
int		is_flags(char *f);
void	ft_putpile(t_pile *a);
void	debug(t_env *e);
t_pile	*piledup(t_pile *p);
t_pile	*bubble_sort(t_pile *p);
void	ft_piledel(t_pile **p);
int		pile_median(t_pile *p);
int		check_pile(t_pile *p);
int		get_ind_swap(t_pile *a);
int		check_swaps(t_env *e);
int		check_rotate(t_env *e);
void	only_swaps(t_env *e);
void	only_rotate(t_env *e);
void	little_sort(t_env *e);
int		get_max(t_pile *a);
int		get_min(t_pile *a);

#endif
