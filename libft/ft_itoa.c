/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccartet <ccartet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 15:11:37 by ccartet           #+#    #+#             */
/*   Updated: 2021/12/16 11:16:31 by ccartet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	strlen_number(long lnb)
{
	int		i;

	i = 1;
	if (lnb < 0)
	{
		i++;
		lnb = -lnb;
	}
	while (lnb > 9)
	{
		lnb = lnb / 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	long	lnb;
	int		stop;
	char	*number;
	int		nb_size;

	lnb = n;
	nb_size = strlen_number(lnb);
	number = malloc(sizeof(char) * nb_size + 1);
	if (!number)
		return (0);
	stop = 0;
	if (lnb < 0)
	{
		number[0] = '-';
		lnb = -lnb;
		stop++;
	}
	number[nb_size] = '\0';
	while (nb_size > stop)
	{
		number[nb_size - 1] = (lnb % 10) + '0';
		lnb = lnb / 10;
		nb_size--;
	}
	return (number);
}

/*#include <stdio.h>

int	main()
{
	printf("%s\n", ft_itoa(54));
	return (0);
}*/
