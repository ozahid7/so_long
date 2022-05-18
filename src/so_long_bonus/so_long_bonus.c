/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahid- <ozahid-@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/01 02:37:05 by ozahid-           #+#    #+#             */
/*   Updated: 2022/05/17 21:22:19 by ozahid-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

t_map	*read_mapb(char *path, t_map *map)
{
	int		fd;
	char	*line;

	map->map = 0;
	fd = open(path, O_RDWR);
	if (fd < 0)
		return (ft_printf("file does not exist %s\n"), NULL);
	line = get_next_line(fd);
	while (line)
	{
		map->map = ft_reallocb(map->map, line);
		line = get_next_line(fd);
	}
	map->len = 0;
	while (map->map[map->len])
		map->len++;
	map->len_line = ft_strlen(map->map[0]);
	return (map);
}

void	find_p(t_map map, t_main *cord)
{
	cord->pos.y = 1;
	while (cord->pos.y < map.len - 1)
	{
		cord->pos.x = 1;
		while (cord->pos.x < map.len_line - 1
			&& map.map[cord->pos.y][cord->pos.x] != 'P')
			cord->pos.x++;
		if (map.map[cord->pos.y][cord->pos.x] == 'P')
			break ;
		cord->pos.y++;
	}
}

int	ft_countcollect(t_map map)
{
	int	i;
	int	j;
	int	c;

	i = 1;
	c = 0;
	while (i < map.len - 1)
	{
		j = 1;
		while (j < map.len_line - 1)
		{
			if (map.map[i][j] == 'C')
				c++;
			j++;
		}
		i++;
	}
	return (c);
}

int	ft_key(int key_code, t_main *ptr)
{
	ft_goright(key_code, ptr);
	ft_goleft(key_code, ptr);
	ft_godown(key_code, ptr);
	ft_goup(key_code, ptr);
	mlx_put_image_to_window(ptr->mlx_ptr, ptr->mlx_win,
		get_image(ptr->images, '1'), 0 * 40, 0 * 40);
	mlx_string_put(ptr->mlx_ptr, ptr->mlx_win, ptr->pos.y,
		ptr->pos.y, 0xffffff, ft_itoa(ptr->moves));
	if (key_code == 53)
		exit(0);
	return (0);
}

int	main(int ac, char **av)
{
	t_main	ptr;

	if (ac != 2)
		return (ft_printf("arguments error"), 1);
	if (check_ber(av[1]))
	{
		if (!read_mapb(av[1], &ptr.map))
			return (0);
		if (check_map(ptr.map))
			return (ft_printf("map error"), 1);
		ptr.c = ft_countcollect(ptr.map);
		find_p(ptr.map, &ptr);
		find_e(ptr.map, &ptr);
		ft_init(&ptr);
		init_image(&ptr.images, ptr.mlx_ptr);
		put_image(ptr);
	}
	mlx_hook(ptr.mlx_win, 2, 0, ft_key, &ptr);
	mlx_hook(ptr.mlx_win, 17, 0, ft_exit, &ptr);
	mlx_loop_hook(ptr.mlx_ptr, patrolup, &ptr);
	mlx_loop(ptr.mlx_ptr);
	return (0);
}
