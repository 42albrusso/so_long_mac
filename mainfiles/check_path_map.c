/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albrusso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 14:38:46 by albrusso          #+#    #+#             */
/*   Updated: 2023/03/03 15:12:36 by albrusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**ft_copy_map(t_program *game)
{
	char	**copy_map;
	int		i;

	i = 0;
	copy_map = (char **)malloc(sizeof(char *) * game->map.height);
	while (i < game->map.height)
	{
		copy_map[i] = ft_strdup(game->map.map[i]);
		i++;
	}
	return(copy_map);
}

void	ft_flood_fill(char **map, char wall, int x, int y)
{
	map[y][x] = '1';
	if (map[y][x + 1] != '1')
		ft_flood_fill(map, wall, x + 1, y);
	if(map[y][x - 1] != '1')
		ft_flood_fill(map, wall, x - 1, y);
	if (map[y + 1][x] != '1')
		ft_flood_fill(map, wall, x, y + 1);
	if (map[y - 1][x] != '1')
		ft_flood_fill(map, wall, x, y - 1);
}

int	ft_check_path_map(t_program *game)
{
	char	**copy_map;
	t_vector	character_position;
	int	i;
	int	j;

	i = 0;
	character_position = ft_find_coordinates(&game->map);
	copy_map = ft_copy_map(game);
	ft_flood_fill(copy_map, '1', character_position.x, character_position.y);
	while (i < game->map.height)
	{
		j = 0;
		while (j < game->map.width)
		{
			if (copy_map[i][j] == 'E' || copy_map[i][j] == 'C')
			{
				free(copy_map);
				return(0);
			}
			j++;
		}
		i++;
	}
	return(1);
}