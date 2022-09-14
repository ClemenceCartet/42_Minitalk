/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccartet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 11:02:51 by ccartet           #+#    #+#             */
/*   Updated: 2021/11/04 17:11:02 by ccartet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t				i;

	i = 0;
	if (!dst && !src)
		return (0);
	if (dst <= src)
	{
		while (i < len)
		{
			((unsigned char *)dst)[i] = ((unsigned char *)src)[i];
			i++;
		}
	}
	else if (dst > src)
	{
		while (len)
		{
			((unsigned char *)dst)[len - 1] = ((unsigned char *)src)[len - 1];
			len--;
		}
	}
	return (dst);
}

/*#include <string.h>
#include <stdio.h>

int	main(int argc, char **argv)
{
	(void)argc;

	printf("%s\n", memmove(argv[1], argv[2], 20));
	printf("%s\n", ft_memmove(argv[1], argv[2], 20));
	return (0);
}*/