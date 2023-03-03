/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albrusso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 14:49:07 by albrusso          #+#    #+#             */
/*   Updated: 2023/03/03 16:07:34 by albrusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_check_wall_up(char *line)
{
	int	i;

	i = 0;
	while (line[i] != '\0')
	{
		if (line[i] != '1')
			return (0);
		i++;
	}
	return (1);
}

int	ft_check_wall_down(char *line, int bool)
{
	int	i;

	i = 0;
	if (bool == 0)
		return (0);
	while (line[i] != '\0')
	{
		if (line[i] != '1')
			return (0);
		i++;
	}
	return (1);
}

int	ft_check_wall_left(t_map *map, int bool)
{
	int	i;

	i = 0;
	if (bool == 0)
		return (0);
	while (i < map->height)
	{
		if (map->map[i][0] != '1')
			return (0);
		i++;
	}
	return (1);
}

int	ft_check_wall_right(t_map *map, int bool)
{
	int	i;

	i = 0;
	if (bool == 0)
		return (0);
	while (i < map->height)
	{
		if (map->map[i][map->width - 1] != '1')
			return (1);
		i++;
	}
	return (1);
}

int	ft_check_wall(t_map *map)
{
	int	bool;
	bool = ft_check_wall_up(map->map[0]);
	bool = ft_check_wall_down(map->map[map->height - 1], bool);
	bool = ft_check_wall_left(map, bool);
	bool = ft_check_wall_right(map, bool);
	return (bool);
}

int	ft_check_start(t_map *map, int bool)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	count = 0;
	if (bool == 0)
		return (0);
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			if (map->map[i][j] == 'P')
				count++;
			j++;
		}
		i++;
	}
	if (count != 1)
		return (0);
	return (count);
}

int	ft_check_exit(t_map *map, int bool)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	count = 0;
	if (bool == 0)
		return (0);
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			if (map->map[i][j] == 'E')
				count++;
			j++;
		}
		i++;
	}
	if (count != 1)
		return (0);
	return (count);
}

int	ft_check_path(t_map *map, int bool)
{
	int	i;
	int	j;

	i = 0;
	if (bool == 0)
		return (0);
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			j++;
		}
		i++;
	}
	return (1);
}

int	ft_check_map(t_map *map)
{
	int	bool;

	if (map->height == map->width)
		return (0);
	bool = ft_check_wall(map);
	bool = ft_check_start(map, bool);
	bool = ft_check_exit(map, bool);
	bool = ft_check_path(map, bool);
	return (bool);
}