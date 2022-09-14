/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccartet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 12:59:12 by ccartet           #+#    #+#             */
/*   Updated: 2021/11/05 12:59:15 by ccartet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long	nb;
	char	nbc;

	nb = n;
	nbc = 0;
	if (nb < 0)
	{
		write(fd, "-", 1);
		nb = -nb;
	}
	nbc = (nb % 10) + '0';
	if (nb > 9)
	{
		ft_putnbr_fd(nb / 10, fd);
	}
	write(fd, &nbc, 1);
}
