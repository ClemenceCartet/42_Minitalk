/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccartet <ccartet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 17:19:33 by ccartet           #+#    #+#             */
/*   Updated: 2021/12/16 13:37:28 by ccartet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putchar_count(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr_count(char *str)
{
	int	i;

	i = 0;
	if (!str)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
	}
	return (i);
}

int	ft_putnbr(int n)
{
	long	nb;
	char	nbc;
	int		count;

	nb = n;
	nbc = 0;
	count = ft_strlen_number(nb, "0123456789");
	if (nb < 0)
	{
		write(1, "-", 1);
		nb = -nb;
	}
	nbc = (nb % 10) + '0';
	if (nb > 9)
		ft_putnbr(nb / 10);
	write(1, &nbc, 1);
	return (count);
}

int	ft_putnbru_base(unsigned long long n, char *base)
{
	int					count;
	unsigned long long	base_len;

	count = 1;
	base_len = ft_strlen(base);
	if (n >= base_len)
		count += ft_putnbru_base(n / base_len, base);
	ft_putchar_count(base[n % base_len]);
	return (count);
}

int	ft_put_pointer(unsigned long long p)
{
	int	count;

	write(1, "0x", 2);
	count = ft_putnbru_base(p, "0123456789abcdef") + 2;
	return (count);
}
