/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_image_utilis_bonus.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahid- <ozahid-@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 22:07:37 by ozahid-           #+#    #+#             */
/*   Updated: 2022/05/18 21:24:54 by ozahid-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	*get_image(t_image *img, char type)
{
	int	i;

	i = 0;
	while (i < 12)
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

void	init_image2(t_image **img, void *mlxptr)
{
	(*img)[5].img = mlx_xpm_file_to_image(mlxptr,
			"/Users/ozahid-/Desktop/enemy.xpm",
			&(*img)[5].img_width, &(*img)[5].img_height);
	(*img)[5].type = ENEMY;
	(*img)[6].img = mlx_xpm_file_to_image(mlxptr,
			"/Users/ozahid-/Desktop/enemy1.xpm",
			&(*img)[6].img_width, &(*img)[6].img_height);
	(*img)[6].type = ENEMY1;
	(*img)[7].img = mlx_xpm_file_to_image(mlxptr,
			"/Users/ozahid-/Desktop/enemy2.xpm",
			&(*img)[7].img_width, &(*img)[7].img_height);
	(*img)[7].type = ENEMY2;
	(*img)[8].img = mlx_xpm_file_to_image(mlxptr,
			"/Users/ozahid-/Desktop/enemy3.xpm",
			&(*img)[8].img_width, &(*img)[8].img_height);
	(*img)[8].type = ENEMY3;
	(*img)[9].img = mlx_xpm_file_to_image(mlxptr,
			"/Users/ozahid-/Desktop/enemy4.xpm",
			&(*img)[9].img_width, &(*img)[9].img_height);
	(*img)[9].type = ENEMY4;
	(*img)[10].img = mlx_xpm_file_to_image(mlxptr,
			"/Users/ozahid-/Desktop/enemy5.xpm",
			&(*img)[10].img_width, &(*img)[10].img_height);
	(*img)[10].type = ENEMY5;
}

void	init_image(t_image **img, void *mlxptr)
{
	*img = (t_image *) malloc(sizeof(t_image) * 12);
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
	init_image2(img, mlxptr);
}
