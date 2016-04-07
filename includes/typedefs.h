/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   typedefs.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeauman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/01 16:22:12 by tbeauman          #+#    #+#             */
/*   Updated: 2016/02/03 11:45:27 by tbeauman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPEDEFS_H
# define TYPEDEFS_H

typedef struct		s_pile
{
	int				elem;
	struct s_pile	*next;
}					t_pile;
typedef struct		s_env
{
	int				size_a;
	int				size_b;
	int				nb_swap;
	int				nb_rotates;
	t_pile			*a;
	t_pile			*b;
	int				initsize;
	int				med_a;
	int				debug_mode;
	int				first_shot;
}					t_env;

#endif
