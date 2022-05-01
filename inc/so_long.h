/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahid- <ozahid-@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/01 02:20:25 by ozahid-           #+#    #+#             */
/*   Updated: 2022/05/01 07:11:06 by ozahid-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
#define SO_LONG_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include "get_next_line.h"
#include "ft_printf.h"
#include <mlx.h>

typedef struct sa_mage
{
	void	*mlx;
	void	*img;
	char	*relative_path;
	int		img_width;
	int		img_height;
	
}t_image;

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

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}   t_data;


//so_long_map_functions
int check_line_len(t_map map, t_element *elm);
int check_side_wals(t_map map);
int check_map(t_map map);
char **ft_realloc(char **str, char *allocate);
char ** ft_copy(char **str, int len, char *allocate);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);








#endif