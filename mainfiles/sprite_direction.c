/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_direction.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albrusso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 14:31:10 by albrusso          #+#    #+#             */
/*   Updated: 2023/03/04 16:06:16 by albrusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_enemy_direction(t_program *game)
{
	t_vector	character_position;
	t_vector	enemy_position;

	character_position = ft_find_coordinates(&game->map, 'P');
	enemy_position = ft_find_coordinates(&game->map, 'E');
	if (enemy_position.x <= character_position.x)
	{
		mlx_destroy_image(game->mlx, game->enemy.reference);
		game->enemy = newSprite(game->mlx, "image/enemy.xpm");
	}
	if (enemy_position.x >= character_position.x)
	{
		mlx_destroy_image(game->mlx, game->enemy.reference);
		game->enemy = newSprite(game->mlx, "image/enemy1.xpm");
	}
}