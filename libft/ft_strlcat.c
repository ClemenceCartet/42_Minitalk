/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccartet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 14:51:42 by ccartet           #+#    #+#             */
/*   Updated: 2021/11/02 14:51:53 by ccartet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;
	size_t	size_src;

	i = 0;
	j = ft_strlen(&dst[i]);
	size_src = ft_strlen(&src[i]);
	if (dstsize == 0 || dstsize < j)
		return (size_src + dstsize);
	while (src[i] && (j + i) < dstsize - 1)
	{
		dst[j + i] = src[i];
		i++;
	}
	dst[j + i] = '\0';
	return (j + size_src);
}

/*#include <string.h>
#include <stdio.h>

int	main(int argc, char **argv)
{
	(void)argc;

	printf("%lu\n", strlcat(argv[1], argv[2], 0));
	printf("%zu\n", ft_strlcat(argv[1], argv[2], 0));
	return (0);
}*/
