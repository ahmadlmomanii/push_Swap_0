/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aal-moum <aal-moum@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 18:44:07 by aal-moum          #+#    #+#             */
/*   Updated: 2026/02/11 19:57:02 by aal-moum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP
#define PUSH_SWAP

typedef	struct		s_stack
{
	int				data;
	struct s_stack	*next;
}					t_stack;

typedef struct s_ps
{
	t_stack	*a;
	t_stack	*b;
	int		size_a;
	int		size_b;
}			t_ps;

#endif
