/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   door_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolivare <jolivare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 12:05:50 by jolivare          #+#    #+#             */
/*   Updated: 2025/02/20 20:02:33 by jolivare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

static void	door_count(t_game *game)
{
	int	i;
	int	j;
	int	count;

	i = -1;
	count = 0;
	while (game->map.map[++i])
	{
		j = -1;
		while (game->map.map[i][++j])
		{
			if (game->map.map[i][j] == 'D')
				count++;
		}
	}
	if (count != 0)
	{
		game->door = malloc(sizeof(t_door) * count);
		if (!game->door)
			print_errors(1);
	}
	game->door_count = count;
}

int	check_door_touch(int ray_x, int ray_y, t_game *game)
{
	int	i;

	i = -1;
	while (++i < game->door_count)
	{
		if (ray_x == game->door[i].x && ray_y == game->door[i].y
			&& !game->door[i].open)
			return (1);
	}
	return (0);
}

void	init_door(t_game *game)
{
	int	door_index;
	int	i;
	int	j;

	door_index = 0;
	door_count(game);
	i = -1;
	while (game->map.map[++i])
	{
		j = -1;
		while (game->map.map[i][++j])
		{
			if (game->map.map[i][j] == 'D')
			{
				game->door[door_index].x = j;
				game->door[door_index].y = i;
				game->door[door_index].open = false;
				door_index++;
			}
		}
	}
}

int	check_door_collision(t_game *game, int x, int y)
{
	int	i;

	i = -1;
	while (++i < game->door_count)
	{
		if (x == game->door[i].x && y == game->door[i].y
			&& !game->door[i].open)
			return (1);
	}
	return (0);
}

void	open_door(t_game *game)
{
	int	i;
	int	player_x;
	int	player_y;

	player_x = (int)game->player.x / BLOCK_SIZE;
	player_y = (int)game->player.y / BLOCK_SIZE;
	i = -1;
	while (++i < game->door_count)
	{
		if (((player_x == game->door[i].x \
					&& abs(player_y - game->door[i].y) == 1)
				|| (player_y == game->door[i].y
					&& abs(player_x - game->door[i].x) == 1)))
		{
			game->door[i].open = !game->door[i].open;
			break ;
		}
	}
}
