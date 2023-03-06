/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albrusso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 12:36:22 by albrusso          #+#    #+#             */
/*   Updated: 2023/03/04 16:02:36 by albrusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minilibx/mlx.h"
#include "../libft/libft.h"
#include "get_next_line.h"
#include <fcntl.h>
#include <string.h>
#include <errno.h>
#include <stdlib.h>
#ifndef SO_LONG_H
#define SO_LONG_H

typedef struct	s_vector
{
	int	x;
	int	y;
}				t_vector;

typedef struct	s_window {
	void		*reference;
	t_vector	size;
}				t_window;


typedef struct s_color {
	int	r;
	int g;
	int b;
	int a;
}	t_color;

typedef struct	s_image {
	void		*reference;
	t_vector	size;
	char		*pixels;
	int			bits_per_pixel;
	int			line_size;
	int			endian;
}				t_image;

typedef struct s_map
{
	int	width;
	int	height;
	char	**map;
}				t_map;


typedef struct	s_program {
	void		*mlx;
	t_window	win;
	t_image		characters;
	t_image		wallpaper;
	t_image		exit;
	t_image		wall;
	t_image		collect_obj;
	t_image		enemy;
	t_map		map;
	t_vector	sprite_position;
}				t_program;

t_image	newImage(void *mlx, int width, int height);

t_image newSprite(void *mlx, char *path);

int ft_close ();

t_window	ft_new_window(void *mlx, int widht, int height, char *name);

int	key_hook(int keycode, void *g);

void	ft_put_wall(void	*mlx, t_window win, t_image wall);

void	ft_refresh_img(t_program *game, const char *s);

void	ft_put_wallpaper(t_program *game, t_image wallpaper);

char	**ft_map(char *av[], t_map *map);

void	ft_view_map(char **map);

void	ft_draw_map(t_program *game, t_image *wall, t_map *map);

char	**ft_refresh_map(int keycode, t_program *game);

int	ft_check_map(t_map *map);

t_vector	ft_find_coordinates(t_map *map, char c);

int	ft_check_path_map(t_program *game);

char	*ft_strdup(const char *str);

char	*ft_itoa(int n);

void	ft_enemy_direction(t_program *game);

#endif
