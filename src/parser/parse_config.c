/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_config.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolivare < jolivare@student.42mad.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 13:10:12 by jolivare          #+#    #+#             */
/*   Updated: 2024/10/24 16:42:11 by jolivare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

void	parse_config(t_game *game)
{
	int 	i;
	char	**aux;

	i = -1;
	while (game->map.raw_file[++i])
	{
		if (ft_strncmp(game->map.raw_file[i], "NO", 2) == 0)
		{
			aux = ft_split(game->map.raw_file[i], ' ');
			game->north_texture = ft_strdup(aux[1]);
			free_str(aux);
		}
		else if (ft_strncmp(game->map.raw_file[i], "SO", 2) == 0)
		{
			aux = ft_split(game->map.raw_file[i], ' ');
			game->south_texture = ft_strdup(aux[1]);
			free_str(aux);
		}
		else if (ft_strncmp(game->map.raw_file[i], "WE", 2) == 0)
		{
			aux = ft_split(game->map.raw_file[i], ' ');
			game->west_texture = ft_strdup(aux[1]);
			free_str(aux);
		}
		else if (ft_strncmp(game->map.raw_file[i], "EA", 2) == 0)
		{
			aux = ft_split(game->map.raw_file[i], ' ');
			game->east_texture = ft_strdup(aux[1]);
			free_str(aux);
		}
		else if (ft_strncmp(game->map.raw_file[i], "F", 1) == 0)
		{
			aux = ft_split(game->map.raw_file[i], ' ');
			game->floor_color = ft_atoi(aux[1]);
			free_str(aux);
		}
		else if (ft_strncmp(game->map.raw_file[i], "C", 1) == 0)
		{
			aux = ft_split(game->map.raw_file[i], ' ');
			game->ceiling_color = ft_atoi(aux[1]);
			free_str(aux);
		}
	}
}
