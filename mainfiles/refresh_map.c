/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   refresh_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albrusso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 17:23:17 by albrusso          #+#    #+#             */
/*   Updated: 2023/03/04 16:02:55 by albrusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_vector	ft_find_coordinates(t_map *map, char c)
{
	int	i;
	int	j;
	t_vector coordinates;

	i = 0;
	while (i < map->height)
	{
		j = 0;
		while(j < map->width)
		{
			if (map->map[i][j] == c)
				break ;
			j++;
		}
		if (map->map[i][j] == c)
			break ;
		i++;
	}
	coordinates.x = j;
	coordinates.y = i;
	return(coordinates);
}

char	**ft_refresh_map(int keycode, t_program *game)
{
	t_vector	coordinates;
	char		nbr;

	coordinates = ft_find_coordinates(&game->map, 'P');
	ft_enemy_direction(game);
	if (keycode == 97 || keycode == 65361 || keycode == 0 || keycode == 123)
	{
		if (game->map.map[coordinates.y][coordinates.x - 1] != '1' && game->map.map[coordinates.y][coordinates.x - 1] != 'E' && game->map.map[coordinates.y][coordinates.x - 1] != 'N')
		{
			nbr = game->map.map[coordinates.y][coordinates.x];
			game->map.map[coordinates.y][coordinates.x] = game->map.map[coordinates.y][coordinates.x - 1];
			game->map.map[coordinates.y][coordinates.x - 1] = nbr;
		}
	}
	else if (keycode == 100 || keycode == 65363 || keycode == 2 || keycode == 124)
	{
		if (game->map.map[coordinates.y][coordinates.x + 1] != '1' && game->map.map[coordinates.y][coordinates.x + 1] != 'E' && game->map.map[coordinates.y][coordinates.x + 1] != 'N')
		{
			nbr = game->map.map[coordinates.y][coordinates.x];
			game->map.map[coordinates.y][coordinates.x] = game->map.map[coordinates.y][coordinates.x + 1];
			game->map.map[coordinates.y][coordinates.x + 1] = nbr;
		}
	}
	else if (keycode == 115 || keycode == 65364 || keycode == 1 || keycode == 125)
	{
		if (game->map.map[coordinates.y + 1][coordinates.x] != '1' && game->map.map[coordinates.y + 1][coordinates.x] != 'E'  && game->map.map[coordinates.y + 1][coordinates.x] != 'N')
		{
			nbr = game->map.map[coordinates.y][coordinates.x];
			game->map.map[coordinates.y][coordinates.x] = game->map.map[coordinates.y + 1][coordinates.x];
			game->map.map[coordinates.y + 1][coordinates.x] = nbr;
		}
	}
	else if (keycode == 119 || keycode == 65362 || keycode == 13 || keycode == 126)
	{
		if (game->map.map[coordinates.y - 1][coordinates.x] != '1' && game->map.map[coordinates.y - 1][coordinates.x] != 'E' && game->map.map[coordinates.y - 1][coordinates.x] != 'N')
		{
			nbr = game->map.map[coordinates.y][coordinates.x];
			game->map.map[coordinates.y][coordinates.x] = game->map.map[coordinates.y - 1][coordinates.x];
			game->map.map[coordinates.y - 1][coordinates.x] = nbr;
		}
	}
	ft_draw_map(game, &game->wall, &game->map);
	return (game->map.map);
}