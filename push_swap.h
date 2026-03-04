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

#include <stdbool.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>

typedef	struct		s_node
{
	int				data;
	struct s_node	*next;
}					t_node;

typedef struct s_ps
{
	t_node	*a;
	t_node	*b;
	int		size_a;
	int		size_b;
	int		flag;
	bool		bench;
}			t_ps;

int     ft_atoi_strict(const char *s);
int     parsing(int ac, char **av, t_ps *ps);
int     ft_strcmp(const char *s1, const char *s2);
void	error_exit(void);

#endif
