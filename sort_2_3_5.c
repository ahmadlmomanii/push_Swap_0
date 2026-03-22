/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_2_3_5.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aal-moum <aal-moum@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 14:51:00 by aal-moum          #+#    #+#             */
/*   Updated: 2026/02/11 18:12:35 by aal-moum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	sort_two(t_ps *ps)
{
	if (ps->a->data > ps->a->next->data)
		sa(ps);
}

void	sort_three(t_ps *ps)
{
	int	a;
	int	b;
	int	c;

	a = ps->a->data;
	b = ps->a->next->data;
	c = ps->a->next->next->data;
	if (a < b && b < c)
		return ;
	else if (a > b && a < c)
		sa(ps);
	else if (a > b && b > c)
	{
		sa(ps);
		rra(ps);
	}
	else if (a > b && a > c && b < c)
		ra(ps);
	else if (a < b && b > c && a < c)
	{
		sa(ps);
		ra(ps);
	}
	else if (a < b && b > c && a > c)
		rra(ps);
}

int	find_min(t_ps *ps)
{
	t_node	*cur;
	int		min;

	cur = ps->a;
	min = ps->a->data;
	while (cur)
	{
		if (min > cur->data)
			min = cur->data;
		cur = cur->next;
	}
	return (min);
}

void	sort_five(t_ps *ps)
{
	int	m;

	m = find_min(ps);
	while (m != ps->a->data)
		ra(ps);
	pb(ps);
	m = find_min(ps);
	while (m != ps->a->data)
		ra(ps);
	pb(ps);
	sort_three(ps);
	pa(ps);
	pa(ps);
}
