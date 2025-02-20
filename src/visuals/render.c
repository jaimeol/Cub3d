/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolivare <jolivare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 16:48:52 by jolivare          #+#    #+#             */
/*   Updated: 2025/02/20 18:53:13 by jolivare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

static int	get_color(t_game *game)
{
	int	color;

	if (game->is_door == 1)
		color = get_texture_color(game->door_texture, \
			game, TEXTURE_WIDTH, TEXTURE_WIDTH);
	else
	{
		if (game->orientation == 1)
			color = get_texture_color(game->north_texture, \
				game, TEXTURE_WIDTH, TEXTURE_WIDTH);
		else if (game->orientation == 2)
			color = get_texture_color(game->south_texture, \
				game, TEXTURE_WIDTH, TEXTURE_WIDTH);
		else if (game->orientation == 3)
			color = get_texture_color(game->west_texture, \
				game, TEXTURE_WIDTH, TEXTURE_WIDTH);
		else if (game->orientation == 4)
			color = get_texture_color(game->east_texture, \
				game, TEXTURE_WIDTH, TEXTURE_WIDTH);
	}
	return (color);
}

static void	render_raycast(t_game *game, int start_y, int end)
{
	int	color;

	while (start_y < end)
	{
		game->texture_y = (start_y - game->vars.center_y + \
			game->vars.projected_height / 2) * \
			TEXTURE_WIDTH / game->vars.projected_height;
		if (game->texture_y < 0)
			game->texture_y = 0;
		color = get_color(game);
		put_pixel(game->vars.index, start_y, color, game);
		start_y++;
	}
}

static float	calculate_wall_pos(t_game *game)
{
	float	wall_pos;

	if (game->is_door)
	{
		if (game->door_orientation == 1 || game->door_orientation == 2)
			wall_pos = game->vars.ray_x;
		else
			wall_pos = game->vars.ray_y;
	}
	else
	{
		if (game->orientation == 1 || game->orientation == 2)
			wall_pos = game->vars.ray_x;
		else
			wall_pos = game->vars.ray_y;
	}
	wall_pos = fmod(wall_pos, BLOCK_SIZE);
	return (wall_pos);
}

void	render(t_game *game, float dist)
{
	int		start_y;
	int		end;
	float	wall_pos;

	game->vars.center_y = HEIGHT / 2;
	game->vars.projected_height = (int)((BLOCK_SIZE / dist) * (WIDTH / 2));
	start_y = game->vars.center_y - game->vars.projected_height / 2;
	end = game->vars.center_y + game->vars.projected_height / 2;
	wall_pos = calculate_wall_pos(game);
	game->texture_x = (int)(wall_pos / BLOCK_SIZE * TEXTURE_WIDTH);
	if (game->orientation == 4)
		game->texture_x = TEXTURE_WIDTH - 1 - game->texture_x;
	render_raycast(game, start_y, end);
}
