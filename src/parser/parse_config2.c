/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_config2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolivare <jolivare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 12:27:36 by rpisoner          #+#    #+#             */
/*   Updated: 2024/12/29 13:05:59 by jolivare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

void	load_floor_color(t_game *game, int i)
{
	char	**aux;

	aux = ft_split(game->map.raw_file[i], ' ');
	game->floor_str = ft_strdup(aux[1]);
	free_str(aux);
}

void	load_ceiling_color(t_game *game, int i)
{
	char	**aux;

	aux = ft_split(game->map.raw_file[i], ' ');
	game->ceiling_str = ft_strdup(aux[1]);
	free_str(aux);
}

bool	textures_ready(t_game *game)
{
	return (game->north_texture && game->east_texture && game->west_texture
		&& game->south_texture && game->floor_str && game->ceiling_str);
}
