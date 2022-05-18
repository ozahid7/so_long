/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_map_utilis_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahid- <ozahid-@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/01 02:34:29 by ozahid-           #+#    #+#             */
/*   Updated: 2022/05/18 21:24:11 by ozahid-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

char	**ft_copy(char **str, int len, char *allocate)
{
	int		i;
	char	**ptr;

	ptr = malloc(sizeof(char *) * (len + 2));
	i = 0;
	if (str != NULL)
	{
		while (str[i])
		{
			ptr[i] = str[i];
			i++;
		}
	}
	ptr[i++] = allocate;
	ptr[i] = 0;
	return (ptr);
}

char	**ft_reallocb(char **str, char *allocate)
{
	int		lt;
	char	**ptr;

	lt = 0;
	if (str == NULL)
		lt = 1;
	else
	{
		while (str[lt])
			lt++;
	}
	ptr = ft_copy(str, lt, allocate);
	free (str);
	return (ptr);
}

int	check_line_len(t_map map, t_element *elm)
{
	int	i;

	i = 1;
	elm->c = 0;
	elm->e = 0;
	elm->p = 0;
	while (i < map.len - 1)
	{
		if (map.len_line != ft_strlen(map.map[i]))
			return (1);
		i++;
	}
	i = 0;
	while (i < map.len_line - 1)
	{
		if (map.map[0][i] != '1' || map.map[map.len - 1][i] != '1')
			return (2);
		i++;
	}
	return (0);
}

int	check_side_wals(t_map map)
{
	int	i;

	i = 1;
	if (map.len_line > 65)
		return (9);
	if (map.len == map.len_line - 1)
		return (7);
	while (i < map.len - 1)
	{
		if (map.map[i][0] != '1' || map.map[i][map.len_line - 2] != '1')
			return (6);
		i++;
	}
	return (0);
}

int	check_map(t_map map)
{
	t_element	elm;

	elm.i = 1;
	if (check_vertical_walls(map))
		return (8);
	if (check_line_len(map, &elm))
		return (7);
	while (elm.i < map.len - 1)
	{
		elm.j = -1;
		while (++elm.j < map.len_line - 1)
		{
			if ((map.map[elm.i][elm.j] != 'C') && (map.map[elm.i][elm.j] != 'P')
			&& (map.map[elm.i][elm.j] != 'E')
			&& (map.map[elm.i][elm.j] != '0')
			&& (map.map[elm.i][elm.j] != '1')
			&& (map.map[elm.i][elm.j] != 'N'))
				return (4);
		}
		elm.i++;
	}
	countchar(&elm);
	if (elm.c == 0 || elm.e == 0 || elm.p > 1 || elm.n < 0 || elm.n > 1)
		return (3);
	return (0);
}
