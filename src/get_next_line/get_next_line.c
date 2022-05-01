/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahid- <ozahid-@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 03:14:21 by ozahid-           #+#    #+#             */
/*   Updated: 2022/05/01 05:33:38 by ozahid-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/get_next_line.h"

int	newline(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] == '\n')
		{
			return (1);
		}
		i++;
	}
	return (0);
}

char	*ft_check(char *str)
{
	int		i;
	char	*dst;

	i = 0;
	if (!str[i])
		return (free(str), NULL);
	while (str[i] && str[i] != '\n')
		i++;
	i += (str[i] == '\n');
	dst = malloc(sizeof(char) * i + 1);
	if (!dst)
		return (0);
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		dst[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
	{
		dst[i] = str[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

char	*ft_rest(char *str)
{
	char	*rest;
	int		i;
	int		a;

	i = 0;
	a = 0;
	if (!str)
		return (0);
	while (str[i] && str[i] != '\n')
		i++;
	i += (str[i] == '\n');
	rest = malloc(sizeof(char) * ft_strlen(str) - i + 1);
	if (!rest)
		return (0);
	while (str[i])
		rest[a++] = str[i++];
	rest[a] = '\0';
	free(str);
	return (rest);
}

char	*ft_read(int fd, char *buffer)
{
	int		nb;
	char	*line;

	nb = 1;
	line = (char *) malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!line)
		return (0);
	while (!newline(buffer) && nb != 0)
	{
		nb = read(fd, line, BUFFER_SIZE);
		if (nb == 0)
			return (free(line), buffer);
		if (nb == -1)
			return (free(buffer), free(line), NULL);
		line[nb] = 0;
		buffer = ft_strjoin(buffer, line);
	}	
	return (free(line), buffer);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	buffer = ft_read(fd, buffer);
	if (!buffer)
		return (0);
	line = ft_check(buffer);
	if (line == 0)
		return (0);
	buffer = ft_rest(buffer);
	return (line);
}
