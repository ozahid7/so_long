/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahid- <ozahid-@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/01 02:37:05 by ozahid-           #+#    #+#             */
/*   Updated: 2022/05/07 22:49:37 by ozahid-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_map *read_map(char *path, t_map *map)
{
	int fd;
	char *line;
	
	map->map = 0;
	fd = open(path, O_RDWR);
	if (fd < 0)
		return (ft_printf("file does not exist %s\n"), NULL);
	line = get_next_line(fd);
	while (line)
	{
		map->map = ft_realloc(map->map, line);
		line = get_next_line(fd);
	}
	map->len = 0;
	while (map->map[map->len])
		map->len++;
	map->len_line = ft_strlen(map->map[0]);
	return (map);
}


int check_ber(char *str)
{
	int i;
	int j;
	
	i = ft_strlen(str) - 1;
	j = 0;
	j += (str[i] == 'r' && str[i - 1] == 'e');
	j += (str[i - 2] == 'b' && str[i - 3] == '.');
	if (j == 2)
		return (1);
	return (ft_printf("file name error"), 0);
}
int ft_init(t_main *ptr)
{
	ptr->mlx_ptr = mlx_init();
	if (ptr->mlx_ptr == NULL)
		return (1);
	ptr->mlx_win = mlx_new_window(ptr->mlx_ptr, (ptr->map.len_line - 1) * 40, ptr->map.len * 40, "ha2");
	if (ptr->mlx_win == NULL)
	{
		free(ptr->mlx_win);
		return (1);
	}
	ptr->img.img = mlx_new_image(ptr->mlx_ptr, 800, 500);
	ptr->img.addr = mlx_get_data_addr(ptr->img.img, &ptr->img.bits_per_pixel, &ptr->img.line_length,
								&ptr->img.endian);
	mlx_put_image_to_window(ptr->mlx_ptr, ptr->mlx_win, ptr->img.img, 0, 0);
	return (0);
}
void init_image(t_image **img, void *mlxptr)
{
	*img = (t_image *) malloc(sizeof(t_image) * 5);
	(*img)[0].img = mlx_xpm_file_to_image(mlxptr, "colct.xpm", &(*img)[0].img_width, &(*img)[0].img_height);
	(*img)[0].type = TP_COL;
	(*img)[1].img = mlx_xpm_file_to_image(mlxptr, "exit.xpm", &(*img)[1].img_width, &(*img)[1].img_height);
	(*img)[1].type = TP_EXIT;
	(*img)[2].img = mlx_xpm_file_to_image(mlxptr, "ground.xpm", &(*img)[2].img_width, &(*img)[2].img_height);
	(*img)[2].type = TP_GROUND;
	(*img)[3].img = mlx_xpm_file_to_image(mlxptr, "wall.xpm", &(*img)[3].img_width, &(*img)[3].img_height);
	(*img)[3].type = TP_WALL;
	(*img)[4].img = mlx_xpm_file_to_image(mlxptr, "player.xpm", &(*img)[4].img_width, &(*img)[4].img_height);
	(*img)[4].type = TP_PLAYER;	
}
void *get_image(t_image *img, char type)
{
	int i;
	
	i = 0;
	while (i < 5)
	{
		if(img[i].type == type)
			return (img[i].img);
		i++;
	}
	return (0);
}
void put_image(t_main ptr)
{
	int i;
	int j;
	
	i = 0;
	while (i < ptr.map.len)
	{
		//don't forget to check the case where a charecter is undefined
		j = 0;
		while( j < ptr.map.len_line - 1)
		{
			mlx_put_image_to_window(ptr.mlx_ptr, ptr.mlx_win, get_image(ptr.images, ptr.map.map[i][j]), 40 * j, 40 * i);
			j++;
		}
		i++;
	}
}

int ft_checkmap_char(t_main ptr)
{
	t_cord a;
	a.y = 1;
	while (a.y < ptr.map.len - 1)
	{
		 a.x = 1;
		while (a.x < ptr.map.len_line)
		{
			if (ptr.map.map[a.y][a.x] != 'P' || ptr.map.map[a.y][a.x] != 'E' 
				|| ptr.map.map[a.y][a.x] != 'C' || ptr.map.map[a.y][a.x] != '1' || ptr.map.map[a.y][a.x] != '0')
				return (1);
				a.x++;
		}
		a.y++;
	}
	return (0);
}

int ft_key(int key_code, t_main *ptr)
{
	(void)ptr;
	printf("%d\n", key_code);
	static int x = 1;
	static int y = 1;
	mlx_put_image_to_window(ptr->mlx_ptr, ptr->mlx_win, get_image(ptr->images, '0'), x * 40, y * 40);
	if ((key_code == 2 || key_code == 124) && x < ptr->map.len_line - 3 && ptr->map.map[y][x + 1] != '1')
		x++;
	if ((key_code == 0 || key_code == 123) && x > 1 && ptr->map.map[y][x - 1] != '1')
		x--;
	if ((key_code == 1 || key_code == 125) && y < ptr->map.len - 2 && ptr->map.map[y + 1][x] != '1')
		y++;
	if ((key_code == 13 || key_code == 126) && y > 1 && ptr->map.map[y - 1][x] != '1')
		y--;
	mlx_put_image_to_window(ptr->mlx_ptr, ptr->mlx_win, get_image(ptr->images, 'P'), x * 40, y * 40);
	return (0);
}

int	main(int ac, char **av)
{
	t_main  ptr;
	t_map map;
	 int x = 1;
	 int y = 1;
	if (ac != 2)
		return (ft_printf("arguments error"), 0);
	if(check_map(map.map[y][x]))
	 	return (ft_printf("map characters error"), 0);
	if (check_ber(av[1]))
	{
		if (!read_map(av[1], &ptr.map))
			return (0);
		ft_printf("error %d \n", check_map(ptr.map));
		ft_init(&ptr);
		init_image(&ptr.images, ptr.mlx_ptr);
		put_image(ptr);
	}
	mlx_key_hook(ptr.mlx_win, &ft_key, &ptr);
	mlx_loop(ptr.mlx_ptr);
}