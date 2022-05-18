/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_movment_utilis_bonus.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahid- <ozahid-@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 21:32:39 by ozahid-           #+#    #+#             */
/*   Updated: 2022/05/17 22:28:33 by ozahid-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_goright(int key_code, t_main *ptr)
{
	if (key_code == 2 && ptr->pos.x < ptr->map.len_line - 3
		&& ptr->map.map[ptr->pos.y][ptr->pos.x + 1] != '1')
	{
		if (ptr->map.map[ptr->pos.y][ptr->pos.x + 1] != 'E')
		{
			mlx_put_image_to_window(ptr->mlx_ptr, ptr->mlx_win,
				get_image(ptr->images, '0'), ptr->pos.x * 40, ptr->pos.y * 40);
			ptr->j += (ptr->map.map[ptr->pos.y][ptr->pos.x] == 'C');
			ptr->map.map[ptr->pos.y][ptr->pos.x] = '0';
			ptr->pos.x++;
			ft_printf ("%d\n", ++ptr->moves);
			mlx_put_image_to_window(ptr->mlx_ptr, ptr->mlx_win,
				get_image(ptr->images, 'P'), ptr->pos.x * 40, ptr->pos.y * 40);
		}
		else if (ptr->map.map[ptr->pos.y][ptr->pos.x + 1] == 'E'
				&& ptr->j >= ptr->c)
		{
			ft_printf("###rba7ti###\n");
			exit (0);
		}
	}
}

void	ft_goleft(int key_code, t_main *ptr)
{
	if (key_code == 0 && ptr->pos.x > 1
		&& ptr->map.map[ptr->pos.y][ptr->pos.x - 1] != '1')
	{
		if (ptr->map.map[ptr->pos.y][ptr->pos.x - 1] != 'E')
		{
			mlx_put_image_to_window(ptr->mlx_ptr, ptr->mlx_win,
				get_image(ptr->images, '0'), ptr->pos.x * 40, ptr->pos.y * 40);
			ptr->j += (ptr->map.map[ptr->pos.y][ptr->pos.x] == 'C');
			ptr->map.map[ptr->pos.y][ptr->pos.x] = '0';
			ptr->pos.x--;
			ft_printf("%d\n", ++ptr->moves);
			mlx_put_image_to_window(ptr->mlx_ptr, ptr->mlx_win,
				get_image(ptr->images, 'P'), ptr->pos.x * 40, ptr->pos.y * 40);
		}
		else if (ptr->map.map[ptr->pos.y][ptr->pos.x - 1] == 'E'
				&& ptr->j >= ptr->c)
		{
			ft_printf("###rba7ti###\n");
			exit (0);
		}
	}
}

void	ft_godown(int key_code, t_main *ptr)
{
	if (key_code == 1 && ptr->pos.y < ptr->map.len - 2
		&& ptr->map.map[ptr->pos.y + 1][ptr->pos.x] != '1')
	{
		if (ptr->map.map[ptr->pos.y + 1][ptr->pos.x] != 'E')
		{
			mlx_put_image_to_window(ptr->mlx_ptr, ptr->mlx_win,
				get_image(ptr->images, '0'), ptr->pos.x * 40, ptr->pos.y * 40);
			ptr->j += (ptr->map.map[ptr->pos.y][ptr->pos.x] == 'C');
			ptr->map.map[ptr->pos.y][ptr->pos.x] = '0';
			ptr->pos.y++;
			ft_printf("%d\n", ++ptr->moves);
			mlx_put_image_to_window(ptr->mlx_ptr, ptr->mlx_win,
				get_image(ptr->images, 'P'), ptr->pos.x * 40, ptr->pos.y * 40);
		}
		else if (ptr->map.map[ptr->pos.y + 1][ptr->pos.x] == 'E'
				&& ptr->j >= ptr->c)
		{
			ft_printf("###rba7ti###\n");
			exit (0);
		}
	}
}

void	ft_goup(int key_code, t_main *ptr)
{
	if (key_code == 13 && ptr->pos.y > 1
		&& ptr->map.map[ptr->pos.y - 1][ptr->pos.x] != '1')
	{
		if (ptr->map.map[ptr->pos.y - 1][ptr->pos.x] != 'E')
		{
			mlx_put_image_to_window(ptr->mlx_ptr, ptr->mlx_win,
				get_image(ptr->images, '0'), ptr->pos.x * 40, ptr->pos.y * 40);
			ptr->j += (ptr->map.map[ptr->pos.y][ptr->pos.x] == 'C');
			ptr->map.map[ptr->pos.y][ptr->pos.x] = '0';
			ptr->pos.y--;
			ft_printf("%d\n", ++ptr->moves);
			mlx_put_image_to_window(ptr->mlx_ptr, ptr->mlx_win,
				get_image(ptr->images, 'P'), ptr->pos.x * 40, ptr->pos.y * 40);
		}
		else if (ptr->map.map[ptr->pos.y - 1][ptr->pos.x] == 'E'
				&& ptr->j >= ptr->c)
		{
			ft_printf("###rba7ti###\n");
			exit (0);
		}
	}
}

int	ft_exit(t_main *ptr)
{
	(void)ptr;
	exit (0);
	return (0);
}
