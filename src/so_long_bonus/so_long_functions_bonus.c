/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_functions_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahid- <ozahid-@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 21:04:47 by ozahid-           #+#    #+#             */
/*   Updated: 2022/05/18 16:18:13 by ozahid-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	find_e(t_map map, t_main *cord)
{
	cord->pos.ey = 1;
	while (cord->pos.ey < map.len - 1)
	{
		cord->pos.ex = 1;
		while (cord->pos.ex < map.len_line - 1
			&& map.map[cord->pos.ey][cord->pos.ex] != 'N')
			cord->pos.ex++;
		if (map.map[cord->pos.ey][cord->pos.ex] == 'N')
			break ;
		cord->pos.ey++;
	}
}

int	counter(long n)
{
	int	count;

	count = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		count++;
		n = -n;
	}
	while (n)
	{
		count++;
		n = n / 10;
	}
	return (count);
}

char	*ft_itoa(int nb)
{
	char		*str;
	int			len;
	long long	n;

	n = nb;
	len = counter(n);
	str = (char *)malloc(len + 1);
	if (str == NULL)
		return (free(str), NULL);
	str[len] = '\0';
	len--;
	if (n == 0)
		str[0] = 48;
	if (n < 0)
	{
		str[0] = '-';
		n = n * -1;
	}
	while (n > 0)
	{
		str[len--] = n % 10 + 48;
		n = n / 10;
	}
	return (str);
}

t_element	countchar(t_element *elm)
{
	t_map	map;

	elm->i = 0;
	while (elm->i < map.len - 1)
	{
		elm->j = -1;
		while (++elm->j < map.len_line - 1)
		{
			elm->c += (map.map[elm->i][elm->j] == 'C');
			elm->p += (map.map[elm->i][elm->j] == 'P');
			elm->e += (map.map[elm->i][elm->j] == 'E');
			elm->e += (map.map[elm->i][elm->j] == 'N');
		}
		elm->i++;
	}
	return (*(elm));
}
