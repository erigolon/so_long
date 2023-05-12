/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erigolon <erigolon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 12:30:16 by erigolon          #+#    #+#             */
/*   Updated: 2023/04/10 12:08:24 by erigolon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	get_textures(t_game *game)
{
	game->textu = ft_calloc(1, sizeof(t_textures));
	game->textu->floor = mlx_load_png("./textures/floor.png");
	game->textu->wall = mlx_load_png("./textures/wall.png");
	game->textu->collec = mlx_load_png("./textures/spark21.png");
	game->textu->chara = mlx_load_png("./textures/mago.png");
	game->textu->exit = mlx_load_png("./textures/salida.png");
	game->textu->exit_2 = mlx_load_png("./textures/salida2.png");
}

void	get_images(t_game *game)
{
	game->imag = ft_calloc(1, sizeof(t_images));
	game->imag->floor = mlx_texture_to_image(game->mlx, game->textu->floor);
	game->imag->wall = mlx_texture_to_image(game->mlx, game->textu->wall);
	game->imag->collec = mlx_texture_to_image(game->mlx, game->textu->collec);
	game->imag->chara = mlx_texture_to_image(game->mlx, game->textu->chara);
	game->imag->exit = mlx_texture_to_image(game->mlx, game->textu->exit);
	game->imag->exit_2 = mlx_texture_to_image(game->mlx, game->textu->exit_2);
	mlx_delete_texture(game->textu->floor);
	mlx_delete_texture(game->textu->wall);
	mlx_delete_texture(game->textu->collec);
	mlx_delete_texture(game->textu->chara);
	mlx_delete_texture(game->textu->exit);
	mlx_delete_texture(game->textu->exit_2);
}

void	draw_floor(t_game *game, t_images *image)
{
	int	x;
	int	y;

	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			mlx_image_to_window(game->mlx, image->floor, x * 32, y * 32);
			if (game->map[y][x] == MAP_WALL)
				mlx_image_to_window(game->mlx, image->wall, x * 32, y * 32);
			if (game->map[y][x] == MAP_EXIT)
			{
				mlx_image_to_window(game->mlx, image->exit_2, x * 32, y * 32);
				mlx_image_to_window(game->mlx, image->exit, x * 32, y * 32);
			}
			x++;
		}
		y++;
	}
}

void	draw_map(t_game *game, t_images *image)
{
	int	x;
	int	y;

	draw_floor(game, image);
	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			if (game->map[y][x] == MAP_COLLECTABLE)
				mlx_image_to_window(game->mlx, image->collec, x * 32, y * 32);

			if (game->map[y][x] == MAP_ENTRY)
				mlx_image_to_window(game->mlx, image->chara, x * 32, y * 32);
			x++;
		}
		y++;
	}
}
