/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahid- <ozahid-@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/01 02:37:05 by ozahid-           #+#    #+#             */
/*   Updated: 2022/05/01 07:25:38 by ozahid-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_map read_map(char *path)
{
	t_map   map;
	int fd;
	char *line;
	
	map.map = 0;
	fd = open(path, O_RDONLY);
	line = get_next_line(fd);
	while (line)
	{
		map.map = ft_realloc(map.map, line);
		line = get_next_line(fd);
	}
	map.len = 0;
	while (map.map[map.len])
		map.len++;
	map.len_line = ft_strlen(map.map[0]);
	return (map);
}


int	main(void)
{
	void	*mlx_ptr;
	void	*mlx_win;
	t_data  img;
	t_map map;
	
	map = read_map("map.ber");
	ft_printf("error %d \n", check_map(map));
	
	mlx_ptr = mlx_init();
	if (mlx_ptr == NULL)
		return (1);
	mlx_win = mlx_new_window(mlx_ptr, 800, 500, "ha2");
	if (mlx_win == NULL)
	{
		free(mlx_win);
		return (1);
	}
	img.img = mlx_new_image(mlx_ptr, 800, 500);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								&img.endian);
	mlx_put_image_to_window(mlx_ptr, mlx_win, img.img, 0, 0);
	mlx_loop(mlx_ptr);
}