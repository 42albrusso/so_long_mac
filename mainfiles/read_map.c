/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albrusso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 16:24:47 by albrusso          #+#    #+#             */
/*   Updated: 2023/02/22 16:28:40 by albrusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_keep_width(char *path)
{
	int	i;
	int	fd;
	char	*map_nbr;

	i = 0;
	fd = open(path, O_RDONLY);
	if (fd == -1)
		return(-1);
	while (1)
	{
		map_nbr = ft_calloc_gnl(2, 1);
		read(fd, map_nbr, 1);
		if (map_nbr[0] == '\n')
			break ;
		free(map_nbr);
		i++;
	}
	free(map_nbr);
	return (i);
}

int	ft_keep_height(char *path)
{
	int	i;
	int	fd;
	char	*map_nbr;

	i = 0;
	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (-1);
	while (1)
	{
		map_nbr = ft_calloc_gnl(2, 1);
		read(fd, map_nbr, 1);
		if (map_nbr[0] == '\n')
			i++;
		if (map_nbr[0] == '\0')
			break ;
		free(map_nbr);
	}
	free(map_nbr);
	return (i);
}

char	**ft_craft_map(char *av[], t_map *maps)
{
	int	width;
	int	height;
	char	**map;
	int	i;

	i = 0;
	maps->width = ft_keep_width(av[1]);
	maps->height = ft_keep_height(av[1]);
	map = (char **)malloc((maps->height) * sizeof(char *));
	while(maps->height > 0)
	{
		map[i] = (char *)malloc((maps->width + 1) * sizeof(char));
		i++;
		maps->height--;
	}
	maps->height = ft_keep_height(av[1]);
	return (map);
}

char	**ft_add_content_map(char *av[], char *map[])
{
	int	i;
	int	j;
	int	fd;
	char	*map_nbr;

	i = 0;
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
		return (0);
	while (i < 6)
	{
		j = 0;
		while (j < 21)
		{
			map_nbr = ft_calloc_gnl(2, 1);
			read(fd, map_nbr, 1);
			if (map_nbr[0] != '\n' && map_nbr[0] != '\0')
				map[i][j] = map_nbr[0];
			else if (map_nbr[0] == '\n' || map_nbr[0] == '\0')
			{
				map[i][j] = '\0';
				free(map_nbr);
				break;
			}
			j++;
			free(map_nbr);
		}
		i++;
	}
	return (map);
}

char	**ft_map(char *av[], t_map *map)
{
	char	**maps;
	int	i;

	i = 0;
	maps = ft_craft_map(av, map);
	maps = ft_add_content_map(av, maps);
	return(maps);
}

void	ft_view_map(char **map)
{
	int	i;

	i = 0;
	while(i < 6)
	{
		printf("%s\n", map[i]);
		i++;
	}
}