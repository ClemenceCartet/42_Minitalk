/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccartet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 14:17:00 by ccartet           #+#    #+#             */
/*   Updated: 2021/11/05 14:17:01 by ccartet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_check_sep(char c, char sep)
{
	if (sep == c)
		return (1);
	else
		return (0);
}

static int	ft_count_words(char const *s, char sep)
{
	int	i;
	int	mot;
	int	chars;

	chars = 1;
	i = 0;
	mot = 0;
	while (s[i])
	{
		if (ft_check_sep(s[i], sep) == 1)
			chars = 1;
		else if (chars == 1)
		{
			chars = 0;
			mot++;
		}
		i++;
	}
	return (mot);
}

static char	*ft_strdupi(char const *s, char sep, int i)
{
	char	*dest;
	int		count;
	int		j;

	count = 0;
	while (s[i + count] && ft_check_sep(s[i + count], sep) != 1)
		count++;
	dest = malloc(sizeof(char) * count + 1);
	if (!dest)
		return (0);
	j = 0;
	while (s[i] && j < count)
		dest[j++] = s[i++];
	dest[j] = '\0';
	return (dest);
}

static void	ft_free(char **tab, int k)
{
	int	i;

	i = 0;
	while (i < k)
	{
		free (tab[i]);
		i++;
	}
	free (tab);
}

char	**ft_split(char const *s, char c)
{
	char	**tab;
	int		i;
	int		k;

	if (!s)
		return (0);
	tab = ft_calloc(ft_count_words(s, c) + 1, sizeof(char *));
	if (!tab)
		return (0);
	i = 0;
	k = 0;
	while (s[i] && k < ft_count_words(s, c))
	{
		while (s[i] && ft_check_sep(s[i], c) == 1)
			i++;
		tab[k] = ft_strdupi(s, c, i);
		if (!tab[k])
			ft_free(tab, k);
		k++;
		while (s[i] && ft_check_sep(s[i], c) == 0)
			i++;
	}
	return (tab);
}

/*#include <stdio.h>

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}

int	main(int argc, char **argv)
{
	(void)argc;
	char **tab;
	int	i;

	tab = ft_split(argv[1], ' ');
	i = 0;
	while (tab[i])
	{
		ft_putstr(tab[i]);
		i++;
	}
	return (0);
}*/