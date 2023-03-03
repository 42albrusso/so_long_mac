/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albrusso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 12:39:28 by albrusso          #+#    #+#             */
/*   Updated: 2023/03/02 19:22:29 by albrusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_refresh_img(t_program *game, const char *s)
{
	mlx_destroy_image(game->mlx, game->characters.reference);
	game->characters = newSprite(game->mlx, s);
	mlx_put_image_to_window(game->mlx, game->win.reference,
			game->characters.reference, game->sprite_position.x, game->sprite_position.y);
}