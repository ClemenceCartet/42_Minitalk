/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccartet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 13:48:42 by ccartet           #+#    #+#             */
/*   Updated: 2021/11/04 17:12:51 by ccartet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(char *s, int c)
{	
	size_t	len;

	len = ft_strlen(s);
	while (len)
	{
		if (s[len] == (char)c)
			return (&s[len]);
		len--;
	}
	if (s[len] == (char)c)
		return (&s[len]);
	return (0);
}

/*#include <string.h>
#include <stdio.h>

int	main(int argc, char **argv)
{
	(void)argc;

	printf("%s\n", strrchr(argv[1], 'e'));
	printf("%s\n", ft_strrchr(argv[1], 'e'));
	return (0);
}*/