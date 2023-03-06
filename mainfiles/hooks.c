/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albrusso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 17:14:17 by albrusso          #+#    #+#             */
/*   Updated: 2023/03/06 13:48:15 by albrusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>


int	key_hook(int keycode, void *g)
{
	t_program	*game;
	t_vector	old;
	static int		old_keycode;
	static int		moves_nbr;
	char		*print_moves;

	game = (t_program *)g;
	old.x = game->sprite_position.x;
	old.y = game->sprite_position.y;
	if (keycode == 65307 || keycode == 53)
		exit(0);
	if (keycode == 97 || keycode == 65361 || keycode == 0 || keycode == 123)
	{
		if (game->sprite_position.x - 60 > 0)
			game->sprite_position.x -= 60;
		old_keycode = 1;
		ft_refresh_img(game, "image/character1.xpm");
		moves_nbr++;
	}
	else if (keycode == 100 || keycode == 65363 || keycode == 2 || keycode == 124)
	{
		if (game->sprite_position.x + 60 < (game->win.size.x - 60))
			game->sprite_position.x += 60;
		old_keycode = 0;
		ft_refresh_img(game, "image/character.xpm");
		moves_nbr++;
	}
	else if (keycode == 115 || keycode == 65364 || keycode == 1 || keycode == 125)
	{
		if (game->sprite_position.y + 60 < (game->win.size.y - 60))
			game->sprite_position.y += 60;
		if (old_keycode == 0)
			ft_refresh_img(game, "image/character.xpm");
		else if (old_keycode == 1)
			ft_refresh_img(game, "image/character1.xpm");
		moves_nbr++;
	}
	else if (keycode == 119 || keycode == 65362 || keycode == 13 || keycode == 126)
	{
		if (game->sprite_position.y - 60 > 0)
			game->sprite_position.y -= 60;
		if (old_keycode == 0)
			ft_refresh_img(game, "image/character.xpm");
		else if (old_keycode == 1)
			ft_refresh_img(game, "image/character1.xpm");
		moves_nbr++;
	}
	print_moves = ft_itoa(moves_nbr);
	mlx_clear_window(game->mlx, game->win.reference);
	game->map.map = ft_refresh_map(keycode, game);
	mlx_string_put(game->mlx, game->win.reference, (game->map.width * 60) - 20, (game->map.height * 60) + 10, 0xffffff, print_moves);
	return (0);
}
