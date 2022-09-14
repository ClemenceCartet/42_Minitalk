/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccartet <ccartet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 14:37:01 by ccartet           #+#    #+#             */
/*   Updated: 2022/01/17 14:11:52 by ccartet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	t;

	i = 0;
	if (dstsize == 0)
		return (ft_strlen(src));
	t = ft_strlen(&src[i]);
	while (src && src[i] && i < dstsize - 1)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (t);
}

/*#include <string.h>
#include <stdio.h>

int	main(int argc, char **argv)
{
	(void)argc;

	printf("%lu\n", strlcpy(argv[1], argv[2], 0));
	printf("%zu\n", ft_strlcpy(argv[1], argv[2], 0));
	return (0);
}*/