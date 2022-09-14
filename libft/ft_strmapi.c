/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccartet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 09:41:33 by ccartet           #+#    #+#             */
/*   Updated: 2021/11/08 09:41:34 by ccartet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*sbis;
	int		i;

	i = 0;
	if (!s || !f)
		return (0);
	sbis = malloc(sizeof(char) * ft_strlen(s) + 1);
	if (!sbis)
		return (0);
	while (s[i])
	{
		sbis[i] = (*f)(i, s[i]);
		i++;
	}
	sbis[i] = '\0';
	return (sbis);
}

/*#include <stdio.h>

char	ft_toupperc(unsigned int i, char c)
{
	if (i >= 3)
		c = c - 32;
	return (c);
}

int	main()
{
	printf("%s\n", ft_strmapi("Hello", ft_toupperc));
	return (0);
}*/
