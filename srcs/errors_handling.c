/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_handling.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeauman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/01 16:45:14 by tbeauman          #+#    #+#             */
/*   Updated: 2016/02/03 14:12:29 by tbeauman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	ft_atol(const char *str)
{
	long	ret;
	int		n;
	int		i;

	i = 0;
	ret = 0;
	n = 0;
	while (*str == '\t' || *str == '\f' || *str == '\v' || *str == '\r' ||
			*str == '\n' || *str == 32)
		str++;
	if (*str == '-' || *str == '+')
	{
		n = *str == '-' ? 1 : 0;
		str++;
	}
	while (str[i] >= '0' && str[i] <= '9' && str[i] != '\0')
	{
		ret = 10 * ret + (str[i] - '0');
		i++;
	}
	return (n == 1 ? -ret : ret);
}

int		wrong_number(char *num)
{
	long	n;

	if (ft_strlen(num) == 0 || ft_strlen(num) > 11)
		return (1);
	if (ft_strlen(num) >= 10)
	{
		n = ft_atol(num);
		if (n > 2147483647 || n < -2147483648)
			return (1);
	}
	return (0);
}

int		is_flags(char *f)
{
	int		i;
	int		len;

	if (f[0] != '-')
		return (0);
	i = 1;
	len = ft_strlen(f);
	while (i < len)
	{
		if (f[i] != 'd')
			return (0);
		i++;
	}
	return (1);
}

void	check_args(int ac, char **av)
{
	int		i;
	int		j;

	i = 1;
	if (ac == 1)
		ft_error("\n");
	while (i < ac && is_flags(av[i]))
		i++;
	while (i < ac)
	{
		j = 0;
		while (av[i][j] != 0)
		{
			if (av[i][j] != '-' && (av[i][j] < '0' || av[i][j] > '9'))
				ft_error("Error\n");
			j++;
		}
		if (wrong_number(av[i]))
			ft_error("Error\n");
		i++;
	}
}
