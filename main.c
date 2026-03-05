/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aal-moum <aal-moum@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 19:02:22 by aal-moum          #+#    #+#             */
/*   Updated: 2026/02/11 16:21:08 by aal-moum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	init_ps(t_ps *ps)
{
	ps->a = NULL;
	ps->b = NULL;
	ps->size_a = 0;
	ps->size_b = 0;
	ps->flag = 0;
	ps->bench_on = false;
	ps->bench = (t_bench){0};
}

int	main(int argc, char **argv)
{
	t_ps	ps;
	int		first_num;

	if (argc == 1)
		return (0);
	init_ps(&ps);
	first_num = parsing(argc, argv, &ps);
	build_stack_a(first_num, argv, &ps, argc);
	dup_check(ps.a);
	if (is_sorted(ps.a))
		return (stack_free(&ps.a), 0);
	return (0);
}
