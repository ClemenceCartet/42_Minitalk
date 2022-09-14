/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccartet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 14:12:55 by ccartet           #+#    #+#             */
/*   Updated: 2021/11/04 17:15:09 by ccartet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(void *s, int c, size_t n)
{
	unsigned char	*str;
	size_t			i;

	str = s;
	i = 0;
	while (i < n)
	{
		if (str[i] == (unsigned char)c)
			return (&s[i]);
		i++;
	}
	return (0);
}

/*#include <string.h>
#include <stdio.h>

int	main()
{
	printf("%s\n", memchr("012345", '2', 3));
	printf("%s\n", ft_memchr("012345", '2', 3));
	return (0);
}*/