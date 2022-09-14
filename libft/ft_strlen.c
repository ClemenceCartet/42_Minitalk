/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccartet <ccartet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 14:35:01 by ccartet           #+#    #+#             */
/*   Updated: 2021/12/16 10:35:50 by ccartet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *s)
{
	size_t	count;

	count = 0;
	if (!s)
		return (0);
	while (s[count] != '\0')
		count++;
	return (count);
}

/*#include <string.h>
#include <stdio.h>

int	main(int argc, char **argv)
{
	(void)argc;

	printf("%lu\n", strlen(argv[1]));
	printf("%zu\n", ft_strlen(argv[1]));
	return (0);
}*/