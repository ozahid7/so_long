/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_functions_needs.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahid- <ozahid-@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/01 06:23:20 by ozahid-           #+#    #+#             */
/*   Updated: 2022/05/18 23:07:04 by ozahid-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_ber(char *str)
{
	int	i;
	int	j;

	i = ft_strlen(str) - 1;
	j = 0;
	j += (str[i] == 'r' && str[i - 1] == 'e');
	j += (str[i - 2] == 'b' && str[i - 3] == '.');
	if (j == 2)
		return (1);
	return (ft_printf("file name error"), 0);
}

int	ft_init(t_main *ptr)
{
	ptr->mlx_ptr = mlx_init();
	if (ptr->mlx_ptr == NULL)
		return (1);
	ptr->mlx_win = mlx_new_window(ptr->mlx_ptr,
			(ptr->map.len_line - 1) * 40, ptr->map.len * 40, "so_long");
	if (ptr->mlx_win == NULL)
	{
		free(ptr->mlx_win);
		return (1);
	}
	ptr->img.img = mlx_new_image(ptr->mlx_ptr,
			(ptr->map.len_line - 1) * 40, ptr->map.len * 40);
	ptr->img.addr = mlx_get_data_addr(ptr->img.img,
			&ptr->img.bits_per_pixel, &ptr->img.line_length, &ptr->img.endian);
	mlx_put_image_to_window(ptr->mlx_ptr, ptr->mlx_win, ptr->img.img, 0, 0);
	return (0);
}

int	check_vertical_walls(t_map map)
{
	int	i;
	int	j;

	j = 1;
	if (check_side_wals(map))
		return (6);
	while (j < map.len_line - 2)
	{
		i = 1;
		while (map.map[i][j] == '1' || map.map[i][j] == 'E')
		{
			i++;
			if (i == map.len - 1)
				return (8);
		}
		j++;
	}
	return (0);
}
