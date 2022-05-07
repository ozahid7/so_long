/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_map_utilis.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahid- <ozahid-@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/01 02:34:29 by ozahid-           #+#    #+#             */
/*   Updated: 2022/05/07 22:41:18 by ozahid-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char ** ft_copy(char **str, int len, char *allocate)
{
	int i;
	char **ptr;
	
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

char **ft_realloc(char **str, char *allocate)
{
	int lt;
	char **ptr;
	
	lt = 0;
	if (str == NULL)
		lt = 1;
	else 
	{
		while (str[lt])
			lt++;
	}
	ptr = ft_copy(str, lt, allocate);
	free(str);
	return (ptr);
}

int check_line_len(t_map map, t_element *elm)
{
	int i;
	
	i = 1;
	elm->c = 0;
	elm->e = 0;
	elm->p = 0;
	while (i < map.len - 1)
	{
		if (map.len_line != ft_strlen(map.map[i]))
			return(1);
		i++;
	}
	if (map.len_line != (ft_strlen(map.map[i]) + (map.map[i][ft_strlen(map.map[i]) - 1] != '\n')))
		return (1);
	i = 0;
	while (i < map.len_line - 1)
	{
		if (map.map[0][i] != '1' || map.map[map.len - 1][i] != '1')
			return(2);
		i++;
	}
	return (0);
}

int check_side_wals(t_map map)
{
	int i;
	
	i = 1;
	while (i < map.len - 1)
	{
		if (map.map[i][0] != '1' || map.map[i][map.len_line - 2] != '1')
			return (88888);
		i++;
	}
	return (0);
}

int check_map(t_map map)
{
	t_element elm;
	int i;
	int j;
	
	i = 1;
	if (check_line_len(map, &elm))
		return (100);
	if (check_side_wals(map))
		return (8000);
	while (i < map.len - 1)
	{
		j = -1;
		if (map.map[i][0] != '1' && map.map[i][map.len_line - 1] != '1')
			return (2);
		while (++j < map.len_line - 1)
		{
			if ((map.map[i][j] != 'C') && (map.map[i][j] != 'P')
				&& (map.map[i][j] != 'E') && (map.map[i][j] != '0')
				&& (map.map[i][j] != '1'))
				return (4);
			elm.c += (map.map[i][j] == 'C');
			elm.p += (map.map[i][j] == 'P');
			elm.e += (map.map[i][j] == 'E');
		}
		i++;
	}
	//printf("this is c%d\n", elm.c);
	if (elm.c == 0 || elm.e == 0 || elm.p != 1)
		return (3);
	return(0);
}