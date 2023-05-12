/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erigolon <erigolon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 12:10:20 by erigolon          #+#    #+#             */
/*   Updated: 2023/04/09 21:13:38 by erigolon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft/libft.h"
# include "printf/ft_printf.h"
# include "get_next_line/get_next_line.h"
# include "MLX42/include/MLX42/MLX42.h"
# include <stdio.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <memory.h>
# include <fcntl.h>
# include <stdint.h>

# define MAP_EXIT 'E'
# define MAP_ENTRY 'P'
# define MAP_COLLECTABLE 'C'
# define MAP_WALL '1'
# define MAP_FLOOR '0'

# define FILE_MSG "Error\nIncorrect number of parameters, only 2 are accepted.\n"
# define FILE_EXT_MSG "Error\nFile has invalid file extension\n"
# define EMPTY_MSG "Error\nMap is empty\n"
# define RECT_MSG "Error\nMap is not rectangle.\n"
# define WRONG_MSG "Error\nMap have the wrongs components\n"
# define WALL_MSG "Error\nMap don't have close walls\n"
# define MIN_TILES_MSG "Error\nYou don't have the correct components\n"
# define PATH_MSG "Error\nThere is not a valid path\n"

# define BUFF_SIZE 10000
# define FALSE		1
# define TRUE		0
# define MOVE		32

typedef struct s_textures {
	mlx_texture_t	*floor;
	mlx_texture_t	*wall;
	mlx_texture_t	*collec;
	mlx_texture_t	*chara;
	mlx_texture_t	*exit;
	mlx_texture_t	*exit_2;
}				t_textures;

typedef struct s_images {
	mlx_image_t	*floor;
	mlx_image_t	*wall;
	mlx_image_t	*collec;
	mlx_image_t	*chara;
	mlx_image_t	*exit;
	mlx_image_t	*exit_2;
}				t_images;

typedef struct s_game
{
	struct s_textures	*textu;
	struct s_images		*imag;
	mlx_t				*mlx;
	char				**map;
	int					map_width;
	int					map_height;
	int					count_collec;
	int					move_count;
	int					n_collec;
	char				**map_2;
}						t_game;

int		init_game(t_game *game);
int		check_extension(const char *fn);
char	**read_map(char *map);
int		check_map(char **map);
int		empty_map(char **map);
int		rectangle_map(char **map);
int		wrong_map(char **map);
int		wall_map(char **map);
void	size_map(t_game *game, char **map);
int		valid_path(t_game *game, char *fd);
int		*start_pos(char **map);
void	flood_map(t_game *game, int x, int y);
int		check_flood(char **map);
int		total_collec(t_game *game);
void	free_map(char **map);
int		min_tiles(char **map);
void	get_textures(t_game *game);
void	get_images(t_game *game);
void	draw_map(t_game *game, t_images *image);
void	my_key_hook(mlx_key_data_t keydata, void *param);
void	move_up(t_game *game);
void	move_right(t_game *game);
void	move_down(t_game *game);
void	move_left(t_game *game);
void	collec_orbs(t_game *game);
void	delete_orbs(t_game *game);

#endif