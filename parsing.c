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

int	parsing(int ac,char **av)
{
	int	i;
	int	x;
	bool	bench;

	i = 1;
	bench =false;
	while (av[i])
	{
		if (av[i] == "--bench")
			{
				bench = true;
				i++;
			}
		if (av[i][0] == '-' && av[i][1] == '-')
			x = flags(av[i]);
		//to decide the algo according to the flag, you have to do it
		else
			break;
                i++;
        }
}
int	flags(char *av)
{
	int	flag;

	flag = 0;
	if (av == "--simple")
		flag = 1;
	else if (av == "--medium")
		flag = 2;
	else if (av == "--complex")
		flag = 3;
	else if (av == "--adaptive")
		flag = 0;
	else
		flag = 4;
	return (flag);
}
