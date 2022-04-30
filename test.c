#include <stdlib.h>
#include <mlx.h>
#include <stdio.h>
#include <string.h>
#include "get_next_line.h"

// typedef struct	s_data {
// 	void	*img;
// 	char	*addr;
// 	int		bits_per_pixel;
// 	int		line_length;
// 	int		endian;
// }   t_data;

// void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
// {
// 	char	*dst;

// 	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
// 	*(unsigned int*)dst = color;
// }

// int allocate(char **str)
// {
// 	int fd;
// 	int i;
// 	int j;
// 	int a = 0;
// 	char *allocate;
	
// 	i = 0;
// 	j = 0;
// 	fd = open("map.ber", O_RDONLY);
// 	allocate = get_next_line(fd);
// 	while (allocate)
// 	{
// 		str[i] = malloc(strlen(allocate) + 1);
// 		i++;
// 		allocate = get_next_line(fd);
// 	}
// 	str[i] = 0;
// }
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
typedef struct s_map{
	char    **map;
	int     len;
	int     len_line;
}   t_map;

typedef struct s_element{
	int c;
	int p;
	int e;
} t_element;

int check_line_len(t_map map, t_element *elm)
{
	int i;
	
	i = 1;
	elm->c = 0;
	elm->e = 0;
	elm->p = 0;
	while (i < map.len - 1)
	{
		if (map.len_line != strlen(map.map[i]))
			return(1);
		i++;
	}
	if (map.len_line != (strlen(map.map[i]) + (map.map[i][strlen(map.map[i]) - 1] != '\n')))
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
	return  (check_line_len(map, &elm));
		// return (100);
	if (check_side_wals(map))
		return (8000);
	while (i < map.len - 1)
	{
		j = 1;
		if (map.map[i][0] != '1' && map.map[i][map.len_line - 1] != '1')
			return (2);
		while (j < map.len_line - 1)
		{
			elm.c += (map.map[i][j] == 'C');
			elm.p += (map.map[i][j] == 'P');
			elm.e += (map.map[i][j] == 'E');
			j++;
		}
		i++;
	}
	if (elm.c == 0 || elm.e == 0 || elm.p != 1)
		return (3);
	return(0);
}

int	main(void)
{
	// void	*mlx;
	// void	*mlx_win;
	// t_data	img;
	t_map map;
	map.map = 0;
	int fd;
	int i;
	char *line;
	
	i = 0;
	fd = open("map.ber", O_RDONLY);
	line = get_next_line(fd);
	while (line)
	{
		map.map = ft_realloc(map.map, line);
		line = get_next_line(fd);
	}
	while (map.map[i])
		i++;
	map.len = i;
	map.len_line = strlen(map.map[0]);
	printf("error %d \n", check_map(map));
	// int x = 350;
	// int y = 200;
	

	// read_map();
	// mlx = mlx_init();
	// if (mlx == NULL)
	// 	return (1);
	// mlx_win = mlx_new_window(mlx, 800, 500, "ha2");
	// if (mlx_win == NULL)
	// {
	// 	free(mlx_win);
	// 	return (1);
	// }
	// img.img = mlx_new_image(mlx, 800, 500);
	// img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
	// 							&img.endian);

	// while (x < 800)
	// {
	// 	if (x < 450)
	// 	my_mlx_pixel_put(&img, x,200, 0XFFFFFF);
	// 	if (x < 450)
	// 	my_mlx_pixel_put(&img, x,300, 0XFFFFFF);
	// 	if (y < 300)
	// 	my_mlx_pixel_put(&img, 350, y, 0XFFFFFF);
	// 	if (y < 300)
	// 	my_mlx_pixel_put(&img, 450, y, 0XFFFFFF);
	// 	x++;
	// 	y++;
	// }
	// mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	// mlx_loop(mlx);
}