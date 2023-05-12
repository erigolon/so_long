/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erigolon <erigolon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 16:06:52 by erigolon          #+#    #+#             */
/*   Updated: 2023/04/10 11:57:42 by erigolon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_map(char **map)
{
	int	i;

	i = -1;
	while (map[++i])
		free(map[i]);
	free(map);
}

void	size_map(t_game *game, char **map)
{
	int	i;

	i = 0;
	game->n_collec = total_collec(game);
	game->map_width = ft_strlen(map[0]) * 32;
	while (map[i])
		i++;
	game->map_height = i * 32;
}

int	check_extension(const char *fn)
{
	int	i;

	i = ft_strlen(fn) - 1;
	if (fn[i] != 'r' || fn[i - 1] != 'e'
		|| fn[i - 2] != 'b'
		|| fn[i - 3] != '.')
		return (FALSE);
	return (TRUE);
}

char	**read_map(char *script_map)
{
	int		fd;
	char	*temp_map;
	char	**map;
	int		n;

	n = 0;
	temp_map = ft_calloc(BUFF_SIZE + 1, sizeof(char));
	if (!temp_map)
		return (0);
	fd = open(script_map, O_RDONLY);
	if (fd < 0)
	{
		free(temp_map);
		return (0);
	}
	n = read(fd, temp_map, BUFF_SIZE);
	if (n == -1 || n == 0)
	{
		free(temp_map);
		return (0);
	}
	map = ft_split(temp_map, '\n');
	free(temp_map);
	close(fd);
	return (map);
}
