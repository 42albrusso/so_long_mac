/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albrusso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 12:36:04 by albrusso          #+#    #+#             */
/*   Updated: 2023/03/03 19:47:41 by albrusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "../libft/libft.h"

int	main(int ac, char *argv[])
{

	t_program	game;

	game.map.map = ft_map(argv, &game.map);
	if (ft_check_map(&game.map) == 0 || ft_check_path_map(&game) == 0)
	{
		printf("%s", strerror(errno));
		free(game.map.map);
		return (0);
	}
	game.mlx = mlx_init();
	game.win = ft_new_window(game.mlx, game.map.width * 60, (game.map.height * 60) + 20, "so_long");

	game.wall = newSprite(game.mlx, "image/wall.xpm");
	game.wallpaper = newSprite(game.mlx, "image/wallpaper.xpm");
	game.characters = newSprite(game.mlx, "image/character.xpm");
	game.exit = newSprite(game.mlx, "image/exit.xpm");
	game.enemy = newSprite(game.mlx, "image/enemy.xpm");
	
	ft_draw_map(&game, &game.wall, &game.map);
	mlx_string_put(game.mlx, game.win.reference, (60), (game.map.height * 60) + 10, 0x00FF0000, "Use WASD or arrow to move");
	mlx_key_hook(game.win.reference, key_hook, &game);
	//free(game.map.map);
	mlx_loop(game.mlx);
}