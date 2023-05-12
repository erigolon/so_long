/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erigolon <erigolon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 16:05:08 by erigolon          #+#    #+#             */
/*   Updated: 2023/04/09 21:11:52 by erigolon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	init_game(t_game *game)
{
	game->move_count = 0;
	game->count_collec = 0;
	game->mlx = mlx_init(game->map_width, game->map_height, "so_long", false);
	if (!(game->mlx))
		return (FALSE);
	get_textures(game);
	get_images(game);
	draw_map(game, game->imag);
	mlx_key_hook(game->mlx, &my_key_hook, game);
	mlx_loop(game->mlx);
	mlx_terminate(game->mlx);
	free_map(game->map);
	free(game->textu);
	free(game->imag);
	return (TRUE);
}

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
		return (ft_printf(FILE_MSG), 1);
	if (check_extension(argv[1]) == FALSE)
		return (ft_printf(FILE_EXT_MSG), 1);
	game.map = read_map(argv[1]);
	if (!game.map)
		return (1);
	if (check_map(game.map) == FALSE)
		return (free_map(game.map), 1);
	size_map(&game, game.map);
	if (valid_path(&game, argv[1]) == FALSE)
		return (free_map(game.map), 1);
	if (init_game(&game) == FALSE)
		return (1);
	return (0);
}
