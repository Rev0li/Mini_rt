/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yafahfou <yafahfou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 17:55:06 by yafahfou          #+#    #+#             */
/*   Updated: 2025/08/19 14:08:23 by yafahfou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "mini_rt.h"

static void	cleanup_gnl(char *buff, char **str)
{
	ft_reset(buff, 0);
	if (str && *str)
	{
		free(*str);
		*str = NULL;
	}
}

char	*ft_strjoin_check(char *s1, char *s2)
{
	char	*tmp;
	int		index_line;

	index_line = ft_index_line(s2);
	tmp = ft_strjoin_gnl(s1, s2, index_line + 1);
	if (s1)
		free(s1);
	if (!tmp)
		return (NULL);
	return (tmp);
}
int	read_file(char *buff, char **str, int fd)
{
	ssize_t	bytes;

	bytes = -2;
	if (buff[0])
	{
		*str = ft_strjoin_check(*str, buff);
		if (!*str)
			return (-1);
		ft_reset(buff, ft_index_line(buff) + 1);
	}
	while (ft_index_line(*str) < 0 && bytes != 0)
	{
		bytes = read(fd, buff, 1000);
		if (bytes <= 0)
			return (bytes);
		buff[bytes] = '\0';
		*str = ft_strjoin_check(*str, buff);
		if (!*str)
			return (-1);
		ft_reset(buff, ft_index_line(buff) + 1);
	}
	return (bytes);
}

char	*get_next_line(int fd)
{
	static char	buff[1001];
	char		*str;
	ssize_t		bytes;

	if (1000 <= 0 || fd < 0)
		return (cleanup_gnl(buff, NULL), NULL);
	str = NULL;
	bytes = read_file(buff, &str, fd);
	if (bytes == -1)
		return (cleanup_gnl(buff, &str), NULL);
	if (bytes == 0)
		return (str);
	if (ft_index_line(buff) != -1 && bytes == -2
		&& ft_index_line(str) == -1)
	{
		str = ft_strjoin_check(str, buff);
		if (!str)
			return (cleanup_gnl(buff, NULL), NULL);
	}
	return (str);
}
