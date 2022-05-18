/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_image_utilis.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahid- <ozahid-@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 22:07:37 by ozahid-           #+#    #+#             */
/*   Updated: 2022/05/13 18:25:35 by ozahid-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	*get_image(t_image *img, char type)
{
	int	i;

	i = 0;
	while (i < 5)
	{
		if (img[i].type == type)
			return (img[i].img);
		i++;
	}
	return (0);
}

void	put_image(t_main ptr)
{
	int	i;
	int	j;

	i = 0;
	while (i < ptr.map.len)
	{
		j = 0;
		while (j < ptr.map.len_line - 1)
		{
			mlx_put_image_to_window(ptr.mlx_ptr, ptr.mlx_win,
				get_image(ptr.images, ptr.map.map[i][j]),
				40 * j, 40 * i);
			j++;
		}
		i++;
	}
}

void	init_image(t_image **img, void *mlxptr)
{
	*img = (t_image *) malloc(sizeof(t_image) * 5);
	(*img)[0].img = mlx_xpm_file_to_image(mlxptr,
			"/Users/ozahid-/Desktop/colct.xpm",
			&(*img)[0].img_width, &(*img)[0].img_height);
	(*img)[0].type = TP_COL;
	(*img)[1].img = mlx_xpm_file_to_image(mlxptr,
			"/Users/ozahid-/Desktop/exit.xpm",
			&(*img)[1].img_width, &(*img)[1].img_height);
	(*img)[1].type = TP_EXIT;
	(*img)[2].img = mlx_xpm_file_to_image(mlxptr,
			"/Users/ozahid-/Desktop/ground.xpm",
			&(*img)[2].img_width, &(*img)[2].img_height);
	(*img)[2].type = TP_GROUND;
	(*img)[3].img = mlx_xpm_file_to_image(mlxptr,
			"/Users/ozahid-/Desktop/wall.xpm",
			&(*img)[3].img_width, &(*img)[3].img_height);
	(*img)[3].type = TP_WALL;
	(*img)[4].img = mlx_xpm_file_to_image(mlxptr,
			"/Users/ozahid-/Desktop/player.xpm",
			&(*img)[4].img_width, &(*img)[4].img_height);
	(*img)[4].type = TP_PLAYER;
}
