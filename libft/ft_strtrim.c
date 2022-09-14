/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccartet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 12:13:35 by ccartet           #+#    #+#             */
/*   Updated: 2021/11/08 12:13:36 by ccartet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_check_sepi(char c, char const *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*s2;
	size_t	start;
	size_t	end;
	int		i;

	if (!s1 || !set)
		return (0);
	start = 0;
	end = ft_strlen(s1);
	while (ft_check_sepi(s1[start], set) == 1)
		start++;
	while (ft_check_sepi(s1[end - 1], set) == 1 && end > start)
		end--;
	s2 = malloc(sizeof(char) * (end - start) + 1);
	if (!s2)
		return (0);
	i = 0;
	while (start < end)
		s2[i++] = s1[start++];
	s2[i] = '\0';
	return (s2);
}

/*#include <stdio.h>

int	main(int argc, char **argv)
{
	(void)argc;
	printf("%s\n", ft_strtrim(argv[1], argv[2]));
	return (0);
}*/
