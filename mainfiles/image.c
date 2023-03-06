/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albrusso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 16:46:27 by albrusso          #+#    #+#             */
/*   Updated: 2023/03/04 15:41:42 by albrusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_image	newImage(void *mlx, int width, int height)
{
	t_image img;

	img.reference = mlx_new_image(mlx, width, height);
	img.size.x = width;
	img.size.y = height;
	img.pixels = mlx_get_data_addr(img.reference, &img.bits_per_pixel, &img.line_size, &img.endian);
	return (img);
}

t_image newSprite(void *mlx, char *path)
{
	t_image img;
	img.reference = mlx_xpm_file_to_image(mlx, path, &img.size.x, &img.size.y);
	img.pixels  = mlx_get_data_addr(img.reference, &img.bits_per_pixel, &img.line_size, &img.endian);
	return (img);
}

void	ft_destroy_all_img(t_program *game)
{
	mlx_destroy_image(game->mlx, game->characters.reference);
	mlx_destroy_image(game->mlx, game->collect_obj.reference);
	mlx_destroy_image(game->mlx, game->enemy.reference);
	mlx_destroy_image(game->mlx, game->exit.reference);
	mlx_destroy_image(game->mlx, game->wall.reference);
	mlx_destroy_image(game->mlx, game->wallpaper.reference);
}

int ft_close (t_program *game)
{
	ft_destroy_all_img(game);
	mlx_destroy_window(game->mlx, game->win.reference);
	exit(0);
}

t_window	ft_new_window(void *mlx, int widht, int height, char *name)
{
	t_window	window;

	window.reference = mlx_new_window(mlx, widht, height, name);
	window.size.x = widht;
	window.size.y = height;
	mlx_hook(window.reference, 17, 0, ft_close, 0);
	return (window);
}