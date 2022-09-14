/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccartet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 15:21:00 by ccartet           #+#    #+#             */
/*   Updated: 2021/11/02 15:22:42 by ccartet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

int	ft_tolower(int c)
{
	if (c >= 65 && c <= 90)
		c = c + 32;
	return (c);
}

/*#include <ctype.h>
#include <stdio.h>

int	main()
{
	printf("%d\n", tolower('E'));
	printf("%d\n", ft_tolower('E'));
	return (0);
}*/