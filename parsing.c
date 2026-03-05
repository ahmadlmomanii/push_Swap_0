/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aal-moum <aal-moum@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 14:51:00 by aal-moum          #+#    #+#             */
/*   Updated: 2026/02/11 18:12:35 by aal-moum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

static int	flags(const char *av)
{
	if (ft_strcmp(av, "--simple") == 0)
		return (1);
	if (ft_strcmp(av, "--medium") == 0)
		return (2);
	if (ft_strcmp(av, "--complex") == 0)
		return (3);
	if (ft_strcmp(av, "--adaptive") == 0)
		return (0);
	return (-1);
}

int	parsing(int ac, char **av, t_ps *ps)
{
	int	i;
	int	f;

	i = 1;
	while (i < ac)
	{
		if (ft_strcmp(av[i], "--bench") == 0)
		{
			ps->bench_on = true;
			i++;
		}
		else if (av[i][0] == '-' && av[i][1] == '-')
		{
			f = flags(av[i]);
			if (f == -1)
				error_exit();
			ps->flag = f;
			i++;
		}
		else
			break ;
	}
	if (i >= ac)
		error_exit();
	return (i);
}
