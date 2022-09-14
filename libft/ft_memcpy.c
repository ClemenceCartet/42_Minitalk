/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccartet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 10:27:33 by ccartet           #+#    #+#             */
/*   Updated: 2021/11/04 17:11:42 by ccartet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t				i;
	unsigned char		*ptr1;
	const unsigned char	*ptr2;

	if (!dst && !src)
		return (0);
	ptr1 = dst;
	ptr2 = src;
	i = 0;
	while (i < n)
	{
		ptr1[i] = ptr2[i];
		i++;
	}
	return (dst);
}

/*#include <string.h>
#include <stdio.h>

int	main(int argc, char **argv)
{
	(void)argc;

	printf("%s\n", memcpy(argv[1], argv[2], 20));
	printf("%s\n", ft_memcpy(argv[1], argv[2], 20));
	return (0);
}*/