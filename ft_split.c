/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aal-moum <aal-moum@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 18:29:27 by aal-moum          #+#    #+#             */
/*   Updated: 2026/02/11 18:42:23 by aal-moum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

static int	countnums(const char *s, char c)
{
	int	i;
	int	nums;

	i = 0;
	nums = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i])
		{
			nums++;
			while (s[i] && s[i] != c)
				i++;
		}
	}
	return (nums);
}

static char	*copynums(const char *s, int start, int end)
{
	char	*res;
	int		i;

	res = malloc((end - start) + 1);
	if (!res)
		return (NULL);
	i = 0;
	while (start < end)
		res[i++] = s[start++];
	res[i] = '\0';
	return (res);
}

static int	fill_split(char **res, const char *s, char c)
{
	int	i;
	int	j;
	int	start;

	i = 0;
	j = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (!s[i])
			break ;
		start = i;
		while (s[i] && s[i] != c)
			i++;
		res[j] = copynums(s, start, i);
		if (!res[j])
			return (ft_free_split(res), 0);
		j++;
	}
	res[j] = NULL;
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char	**res;

	if (!s)
		return (NULL);
	res = malloc(sizeof(char *) * (countnums(s, c) + 1));
	if (!res)
		return (NULL);
	if (!fill_split(res, s, c))
		return (NULL);
	return (res);
}
