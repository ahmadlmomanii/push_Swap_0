/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aal-moum <aal-moum@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 14:51:00 by aal-moum          #+#    #+#             */
/*   Updated: 2026/02/11 18:12:35 by aal-moum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error_exit(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

void	ft_putdouble_fd(double n, int fd)
{
	long	integral;
	long	fractional;

	if (n < 0)
	{
		write(fd, "-", 1);
		n = -n;
	}
	// طباعة الجزء الصحيح
	integral = (long)n;
	ft_putnbr_fd(integral, fd);
	write(fd, ".", 1);
	// حساب أول خانتين عشريتين (مثلاً 0.4993 تصبح 49)
	n -= (double)integral;
	fractional = (long)(n * 100 + 0.5); // إضافة 0.5 للتقريب لأقرب رقم
	if (fractional >= 100) // حالة خاصة عند التقريب لـ 1.00
		fractional = 99;
	if (fractional < 10)
		write(fd, "0", 1);
	ft_putnbr_fd(fractional, fd);
}

void	ft_putnbr_fd(long n, int fd)
{
	char	c;

	if (n < 0)
	{
		write(fd, "-", 1);
		n = -n;
	}
	if (n >= 10)
		ft_putnbr_fd(n / 10, fd);
	c = (n % 10) + '0';
	write(fd, &c, 1);
}