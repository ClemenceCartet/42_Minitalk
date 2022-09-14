/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccartet <ccartet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 15:15:24 by ccartet           #+#    #+#             */
/*   Updated: 2021/12/18 15:55:05 by ccartet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_find_n(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

static char	*ft_strjoinf(char const *s1, char const *s2)
{
	char	*dest;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!s1 && !s2)
		return (0);
	dest = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!dest)
	{
		free ((char *)s1);
		return (0);
	}
	while (s1 && s1[i])
	{
		dest[i] = s1[i];
		i++;
	}
	while (s2[j])
		dest[i++] = s2[j++];
	dest[i] = '\0';
	free ((char *)s1);
	return (dest);
}

static char	*get_line(char **save)
{
	char	*line;
	char	*tmp;
	int		index;

	index = ft_find_n(*save);
	if (index == -1)
		line = ft_strdup(*save);
	else
		line = ft_substr(*save, 0, index + 1);
	tmp = *save;
	if (index == -1)
		*save = NULL;
	else
		*save = ft_strdup(&(*save)[index + 1]);
	free (tmp);
	return (line);
}

static int	read_value(char **save, int fd)
{
	int		size;
	char	buf[BUFFER_SIZE + 1];

	ft_bzero(buf, BUFFER_SIZE + 1);
	size = read(fd, buf, BUFFER_SIZE);
	if (size == -1)
		return (-1);
	while (size > 0)
	{
		*save = ft_strjoinf(*save, buf);
		if (!save)
			return (-1);
		if (ft_find_n(*save) != -1)
			return (size);
		ft_bzero(buf, BUFFER_SIZE + 1);
		size = read(fd, buf, BUFFER_SIZE);
		if (size == -1)
			return (-1);
	}
	return (size);
}

char	*get_next_line(int fd)
{
	static char	*save;
	int			size;

	if (fd < 0 || fd > OPEN_MAX || BUFFER_SIZE < 1)
		return (NULL);
	if (save && ft_find_n(save) != -1)
		return (get_line(&save));
	size = read_value(&save, fd);
	if (size > 0)
		return (get_line(&save));
	if (size == 0 && save && ft_strlen(save))
		return (get_line(&save));
	free (save);
	save = NULL;
	return (NULL);
}

// int	main(void)
// {
// 	int		i;
// 	int		fd;
// 	char	*str;

// 	i = 0;
// 	fd = open("get_next_line.c", O_RDONLY);
// 	//printf("%s", get_next_line(fd));
// 	str = (char *)1;
// 	while ((str = get_next_line(fd)))
// 	{
// 		printf("%s", str);
// 		i++;
// 		free (str);
// 	}
// 	close(fd);
// 	return (0);
// }
