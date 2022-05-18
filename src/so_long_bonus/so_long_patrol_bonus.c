/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_patrol_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahid- <ozahid-@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 19:46:39 by ozahid-           #+#    #+#             */
/*   Updated: 2022/05/17 22:33:34 by ozahid-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ptrexit(t_main *ptr)
{
	if (ptr->map.map[ptr->pos.y][ptr->pos.x] == 'N')
	{
		ft_printf("### 5serti a m3alm ####\n");
		exit(1);
	}
}

int	patroldown(t_main *ptr)
{		
	if (ptr->map.map[ptr->pos.ey + 1][ptr->pos.ex] == '1'
		|| ptr->map.map[ptr->pos.ey + 1][ptr->pos.ex] == 'C'
		|| ptr->map.map[ptr->pos.ey + 1][ptr->pos.ex] == 'E' )
		mlx_loop_hook(ptr->mlx_ptr, patrolup, ptr);
	patroldneed(ptr);
	ptrexit(ptr);
	ptr->patrol++;
	return (0);
}

int	patroldneed(t_main *ptr)
{
	if (ptr->patrol == 700)
	{
		mlx_put_image_to_window(ptr->mlx_ptr, ptr->mlx_win,
			get_image(ptr->images, '0'), ptr->pos.ex * 40, ptr->pos.ey * 40);
		ptr->map.map[ptr->pos.ey][ptr->pos.ex] = '0';
		ptr->pos.ey++;
		ptr->map.map[ptr->pos.ey][ptr->pos.ex] = 'N';
	}
	else if (ptr->patrol == 1400)
		mlx_put_image_to_window(ptr->mlx_ptr, ptr->mlx_win,
			get_image(ptr->images, 'N'), ptr->pos.ex * 40, ptr->pos.ey * 40);
	else if (ptr->patrol == 2400)
	{
		mlx_put_image_to_window(ptr->mlx_ptr, ptr->mlx_win,
			get_image(ptr->images, 'K'), ptr->pos.ex * 40, ptr->pos.ey * 40);
	}
	else if (ptr->patrol == 3400)
	{
		mlx_put_image_to_window(ptr->mlx_ptr, ptr->mlx_win,
			get_image(ptr->images, 'H'), ptr->pos.ex * 40, ptr->pos.ey * 40);
		ptr->patrol = 0;
	}
	return (0);
}

int	patrolupneeds(t_main *ptr)
{
	if (ptr->patrol == 700)
	{
		mlx_put_image_to_window(ptr->mlx_ptr, ptr->mlx_win,
			get_image(ptr->images, '0'), ptr->pos.ex * 40, ptr->pos.ey * 40);
		ptr->map.map[ptr->pos.ey][ptr->pos.ex] = '0';
		ptr->pos.ey--;
		ptr->map.map[ptr->pos.ey][ptr->pos.ex] = 'N';
	}
	else if (ptr->patrol == 1400)
	{
		mlx_put_image_to_window(ptr->mlx_ptr, ptr->mlx_win,
			get_image(ptr->images, 'G'), ptr->pos.ex * 40, ptr->pos.ey * 40);
	}
	else if (ptr->patrol == 2400)
	{
		mlx_put_image_to_window(ptr->mlx_ptr, ptr->mlx_win,
			get_image(ptr->images, 'M'), ptr->pos.ex * 40, ptr->pos.ey * 40);
	}
	else if (ptr->patrol == 3400)
	{
		mlx_put_image_to_window(ptr->mlx_ptr, ptr->mlx_win,
			get_image(ptr->images, 'H'), ptr->pos.ex * 40, ptr->pos.ey * 40);
		ptr->patrol = 0;
	}
	return (0);
}

int	patrolup(t_main *ptr)
{
	if (ptr->map.map[ptr->pos.ey - 1][ptr->pos.ex] == '1'
		|| ptr->map.map[ptr->pos.ey - 1][ptr->pos.ex] == 'C'
		|| ptr->map.map[ptr->pos.ey - 1][ptr->pos.ex] == 'E' )
		mlx_loop_hook(ptr->mlx_ptr, patroldown, ptr);
	patrolupneeds(ptr);
	ptrexit(ptr);
	ptr->patrol++;
	return (0);
}
