/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albrusso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 14:47:03 by albrusso          #+#    #+#             */
/*   Updated: 2023/02/20 17:05:31 by albrusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <string.h>

char	*ft_ret(char *str)
{
	int		i;
	char	*ret;

	i = 0;
	if (str[0] == 0)
		return (NULL);
	while (str[i])
		i++;
	ret = (char *)ft_calloc_gnl(i, 1);
	i = 0;
	while (str[i] != '\n' && str[i])
	{
		ret[i] = str[i];
		i++;
	}
	ret[i] = '\0';
	return (ret);
}

char	*ft_read(int fd, char *str)
{
	int		byte_read;
	char	*s;

	byte_read = 1;
	while (byte_read > 0)
	{
		s = (char *)ft_calloc_gnl(BUFFER_SIZE + 1, 1);
		byte_read = read (fd, s, BUFFER_SIZE);
		if (byte_read == -1)
			return (NULL);
		str = ft_strjoin_gnl(str, s);
		if (byte_read == 0)
			break ;
		if (ft_strchr_gnl(str, '\n') == 1)
			break ;
	}
	if (str[0] == 0 && byte_read == 0)
	{
		free (str);
		str = NULL;
	}
	return (str);
}

char	*get_next_line(int fd)
{
	char		*str;
	char		*ret;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	str = ft_calloc_gnl(1, 1);
	str = ft_read(fd, str);
	if (str == NULL)
	{
		free (str);
		return (NULL);
	}
	ret = ft_ret(str);
	free(str);
	str = NULL;
	return (ret);
}
/*
int main(void)
{
	char *s;
	int i;
	int fd;

	fd = open("map.ber", O_RDONLY);
	if (fd == -1)
		return (0);
	i = 0;
	while (1)
	{
		s = get_next_line(fd);
		if (s == NULL)
			break ;
		printf("s: %s\n", s);
		free(s);
		i++;
	}
}
*/
