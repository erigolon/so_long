/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collectibles.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erigolon <erigolon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 11:40:15 by erigolon          #+#    #+#             */
/*   Updated: 2023/04/09 21:22:46 by erigolon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	total_collec(t_game *game)
{
	int	total;
	int	i;
	int	o;

	total = 0;
	i = 0;
	while (game->map[i])
	{
		o = 0;
		while (game->map[i][o])
		{
			if (game->map[i][o] == 'C')
				total++;
			o++;
		}
		i++;
	}
	return (total);
}

void	delete_orbs(t_game *game)
{
	int	i;
	int	count;

	i = 0;
	count = game->n_collec;
	while (i < count)
	{
		if (((game->imag->collec->instances[i].y
					== game->imag->chara->instances->y)
				&& (game->imag->collec->instances[i].x
					== game->imag->chara->instances->x))
			&& game->imag->collec->instances[i].enabled == true)
		{
			count--;
			game->imag->collec->instances[i].enabled = false;
			return ;
		}
		i++;
	}
}

void	collec_orbs(t_game *game)
{
	if (game->map[game->imag->chara->instances->y / 32]
		[game->imag->chara->instances->x / 32] == MAP_COLLECTABLE)
	{
		delete_orbs(game);
		game->map[game->imag->chara->instances->y / 32]
		[game->imag->chara->instances->x / 32] = MAP_FLOOR;
		game->count_collec++;
		if (game->count_collec == game->n_collec)
			game->imag->exit->instances->enabled = false;
	}
	if (game->map[game->imag->chara->instances->y / 32]
		[game->imag->chara->instances->x / 32] == MAP_EXIT)
	{
		if (game->count_collec == game->n_collec)
			mlx_close_window(game->mlx);
	}
}
