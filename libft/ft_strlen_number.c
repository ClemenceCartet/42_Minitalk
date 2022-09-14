/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen_number.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccartet <ccartet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 11:01:54 by ccartet           #+#    #+#             */
/*   Updated: 2021/12/16 11:03:00 by ccartet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strlen_number(long lnb, char *base)
{
	long	base_length;
	int		i;

	i = 1;
	if (lnb < 0)
	{
		i++;
		lnb = -lnb;
	}
	base_length = ft_strlen(base);
	while (lnb >= base_length)
	{
		lnb = lnb / base_length;
		i++;
	}
	return (i);
}
