/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccartet <ccartet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 13:53:50 by ccartet           #+#    #+#             */
/*   Updated: 2021/12/16 10:15:28 by ccartet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*dest;
	size_t	count;
	size_t	i;
	size_t	size;

	if (!s)
		return (0);
	count = 0;
	i = 0;
	size = ft_strlen(s);
	while (s[start + count] && count < len)
		count++;
	dest = malloc(sizeof(char) * count + 1);
	if (!dest)
		return (0);
	while (start < size && i < count)
	{
		dest[i++] = s[start++];
	}
	dest[i] = '\0';
	return (dest);
}

/*#include <stdio.h>

int	main(int argc, char **argv)
{
	(void)argc;
	printf("%s\n", ft_substr(argv[1], 3, 10));
	return (0);
}*/