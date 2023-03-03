/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albrusso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 16:16:37 by albrusso          #+#    #+#             */
/*   Updated: 2023/03/03 12:48:26 by albrusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_draw_map(t_program *game, t_image *wall, t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while(i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			if (map->map[i][j] == '1')
				mlx_put_image_to_window(game->mlx, game->win.reference, wall->reference, 60 * j, 60 * i);
			else if (map->map[i][j] == '0')
				mlx_put_image_to_window(game->mlx, game->win.reference, game->wallpaper.reference, 60 * j, 60 * i);
			else	if (map->map[i][j] == 'P')
			{
				mlx_put_image_to_window(game->mlx, game->win.reference, game->characters.reference, 60 * j, 60 * i);
				game->sprite_position.x = 60 * j;
				game->sprite_position.y = 60 * i;
			}
			else if (map->map[i][j] == 'E')
				mlx_put_image_to_window(game->mlx, game->win.reference, game->exit.reference, 60 * j, 60 * i);
			else if (map->map[i][j] == 'N')
				mlx_put_image_to_window(game->mlx, game->win.reference,game->enemy.reference, 60 * j, 60 * i);
			j++;
		}
		i++;
	}
}