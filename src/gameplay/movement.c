/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolivare <jolivare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 12:52:56 by jolivare          #+#    #+#             */
/*   Updated: 2024/11/13 23:51:19 by jolivare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

void	move_player(t_game *game)
{
	int		speed;
	float	angle_speed;
	float	cos_angle;
	float	sin_angle;

	speed = 2;
	angle_speed = 0.03;
	cos_angle = cos(game->player.angle);
	sin_angle = sin(game->player.angle);

	if (game->player.left_rotation)
		game->player.angle -= angle_speed;
	if (game->player.right_rotation)
		game->player.angle += angle_speed;
	if (game->player.angle > 2 * M_PI)
		game->player.angle = 0;
	if (game->player.angle < 0)
		game->player.angle = 2 * M_PI;
	if (game->player.key_door && is_door(game, speed, cos_angle, sin_angle))
	{
		if (game->door_open == true)
			game->door_open = false;
		else if (game->door_open == false)
			game->door_open = true;
	}
	if (game->player.key_up && !is_wall_up(game, speed, cos_angle, sin_angle))
	{
		game->player.x += cos_angle * speed;
		game->player.y += sin_angle * speed;
	}
	if (game->player.key_down && !is_wall_down(game, speed, cos_angle, sin_angle))
	{
		game->player.x -= cos_angle * speed;
		game->player.y -= sin_angle * speed;
	}
	if (game->player.key_left && !is_wall_left(game, speed, cos_angle, sin_angle))
	{
		game->player.x += sin_angle * speed;
		game->player.y -= cos_angle * speed;
	}
	if (game->player.key_right && !is_wall_right(game, speed, cos_angle, sin_angle))
	{
		game->player.x -= sin_angle * speed;
		game->player.y += cos_angle * speed;
	}
}
