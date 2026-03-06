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

/**
 * Displays the benchmark results to stderr if the flag is present.
 */
void	display_bench(t_ps *ps)
{
	write(2, "[bench] disorder:\n", 18);
	ft_putdouble_fd(ps->bench.disorder * 100, 2); // ضرب في 100 لعرضها كنسبة مئوية
	write(2, "%\n", 2);
	write(2, "[bench] strategy:\n", 18);
	if (ps->flag == 1)
		write(2, "Simple / O(n^2)\n", 16);
	else if (ps->flag == 2)
		write(2, "Medium / O(n*sqrt(n))\n", 22);
	else
		write(2, "Complex / O(n log n)\n", 21);
	write(2, "[bench] total_ops:\n", 19);
	ft_putnbr_fd(ps->bench.count, 2);
	write(2, "\n", 1);
}

int	main(int argc, char **argv)
{
	t_ps	ps;
	int		first_num_idx;

	if (argc == 1)
		return (0);
	init_ps(&ps);
	first_num_idx = parsing(argc, argv, &ps); 
	build_stack_a(first_num_idx, argv, &ps, argc);
	dup_check(ps.a);
	if (is_sorted(ps.a))
		return (stack_free(&ps.a), 0);
	// 1. Disorder Calculation 
	ps.bench.disorder = compute_disorder(ps.a, ps.size_a);
	// 2. Strategy Selection 
	select_strategy(&ps);
	// 3. Execution
	execute_sort(&ps);
	// 4. Benchmark Output 
	if (ps.bench_on)
		display_bench(&ps);
	stack_free(&ps.a);
	return (0);
}
