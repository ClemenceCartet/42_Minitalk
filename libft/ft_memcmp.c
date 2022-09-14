/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccartet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 14:35:07 by ccartet           #+#    #+#             */
/*   Updated: 2021/11/04 17:11:13 by ccartet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*ptr1;
	unsigned char	*ptr2;

	i = 0;
	ptr1 = (unsigned char *)s1;
	ptr2 = (unsigned char *)s2;
	while (i < n)
	{
		if (!(*ptr1 == *ptr2))
			return (*ptr1 - *ptr2);
		ptr1++;
		ptr2++;
		i++;
	}
	return (0);
}

/*#include <string.h>
#include <stdio.h>

int	main()
{
	printf("%d\n", memcmp("heLlo", "hello", 4));
	printf("%d\n", ft_memcmp("heLlo", "hello", 4));
	return (0);
}*/