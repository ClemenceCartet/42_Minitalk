/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccartet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 15:22:19 by ccartet           #+#    #+#             */
/*   Updated: 2021/11/04 17:15:55 by ccartet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(const char *str)
{
	int	num;
	int	i;
	int	resultat;

	num = 1;
	i = 0;
	resultat = 0;
	if (str[i] == '\0')
		return (0);
	while (str[i] && (str[i] == 32 || (str[i] >= 9 && str[i] <= 13)))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			num = -num;
		i++;
	}
	while (str[i] >= 48 && str[i] <= 57)
	{
		resultat = resultat * 10 + (str[i] - '0');
		i++;
	}
	return (resultat * num);
}	

/*#include <stdlib.h>
#include <stdio.h>

int	main()
{
	printf("%d\n", atoi("   + 48"));
	printf("%d\n", ft_atoi("   + 48"));
	return (0);
}*/