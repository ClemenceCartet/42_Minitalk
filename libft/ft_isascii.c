/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccartet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 14:08:46 by ccartet           #+#    #+#             */
/*   Updated: 2021/11/02 15:28:10 by ccartet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

int	ft_isascii(int c)
{
	return (c >= 0 && c <= 127);
}

/*#include <ctype.h>
#include <stdio.h>

int	main()
{
	printf("%d\n", isascii(2));
	printf("%d\n", ft_isascii(2));
	return (0);
}*/