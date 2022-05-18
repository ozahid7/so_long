/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahid- <ozahid-@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/01 02:20:25 by ozahid-           #+#    #+#             */
/*   Updated: 2022/05/18 16:18:43 by ozahid-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
#define SO_LONG_BONUS_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include "get_next_line.h"
#include "ft_printf.h"
#include <mlx.h>

typedef struct s_map{
	char    **map;
	int     len;
	int     len_line;
}   t_map;

typedef enum e_type{
	TP_WALL = '1',
	TP_COL =  'C',
	TP_EXIT = 'E',
	TP_PLAYER = 'P',
	ENEMY1 = 'M',
	ENEMY2 = 'K',
	ENEMY3 = 'L',
	ENEMY4 = 'H',
	ENEMY5 = 'G',
	ENEMY = 'N',
	TP_GROUND = '0'
} t_type;

typedef struct sa_mage
{
	void	*mlx;
	void	*img;
	void    *pimg;
	char	*relative_path;
	t_type  type;
	int		img_width;
	int		img_height;
	
}t_image;

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}   t_data;

typedef struct s_cord
{
	int x;
	int y;
	int ex;
	int ey;
}   t_cord;

typedef struct s_main
{
	void    *mlx_ptr;
	void    *mlx_win;
	t_image *images;
	t_image *pimages;
	t_cord pos;
	t_map   map;
	t_data img;
	int c;
	int j;
	int patrol;
	int moves;
} t_main;


typedef struct s_element{
	int c;
	int p;
	int e;
	int n;
	int i;
	int j;
} t_element;



//so_long_map_functions
int check_line_len(t_map map, t_element *elm);
int check_side_wals(t_map map);
int check_map(t_map map);
int check_vertical_walls(t_map map);
t_map	*read_mapb(char *path, t_map *map);
char **ft_reallocb(char **str, char *allocate);
char ** ft_copy(char **str, int len, char *allocate);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
int check_ber(char *str);
int ft_init(t_main *ptr);
t_element countchar(t_element *elm);
//so_long_movmentfunctions
void ft_goright(int key_code, t_main *ptr);
void ft_goleft(int key_code, t_main *ptr);
void ft_godown(int key_code, t_main *ptr);
void ft_goup(int key_code, t_main *ptr);
int	ft_exit(t_main *ptr);
int patrolup(t_main *ptr);
//so_long_images_functions
void *get_image(t_image *img, char type);
void put_image(t_main ptr);
void init_image(t_image **img, void *mlxptr);
//so_long_patrol
int patrolup(t_main *ptr);
int patrolupneeds(t_main *ptr);
int patroldneed(t_main *ptr);
int patroldown(t_main *ptr);
void ptrexit(t_main *ptr);

int 	counter(long n);
char	*ft_itoa(int nb);
void	find_e(t_map map, t_main *cord);
int	check_map(t_map map);
#endif