/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images_mlx.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftataje- <ftataje-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 13:49:34 by ftataje-          #+#    #+#             */
/*   Updated: 2023/05/02 19:21:51 by ftataje-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

void	charge_images(t_total *game)
{
	int	i;
	int	j;

	game->mlxtot.fondo = mlx_xpm_file_to_image(game->mlxtot.mlxptr,
			"img/xpm/fondo1.xpm", &i, &j);
	game->mlxtot.wall = mlx_xpm_file_to_image(game->mlxtot.mlxptr,
			"img/xpm/wall2.xpm", &i, &j);
	game->mlxtot.player = mlx_xpm_file_to_image(game->mlxtot.mlxptr,
			"img/xpm/player.xpm", &i, &j);
	game->mlxtot.door = mlx_xpm_file_to_image(game->mlxtot.mlxptr,
			"img/xpm/door.xpm", &i, &j);
	game->mlxtot.collect = mlx_xpm_file_to_image(game->mlxtot.mlxptr,
			"img/xpm/collect1.xpm", &i, &j);
	if (!game->mlxtot.fondo || !game->mlxtot.wall || !game->mlxtot.player
		|| !game->mlxtot.door || !game->mlxtot.collect)
		printerrors("Error, al tratar de cargar la imagen xpm");
}

void	put_icon(t_total *game, int x, int y)
{
	mlx_put_image_to_window(game->mlxtot.mlxptr, game->mlxtot.wingame,
		game->mlxtot.fondo, x * 50, y * 50);
	if (game->parameter.map[y][x] == '1')
		mlx_put_image_to_window(game->mlxtot.mlxptr, game->mlxtot.wingame,
			game->mlxtot.wall, x * 50, y * 50);
	if (game->parameter.map[y][x] == 'E')
		mlx_put_image_to_window(game->mlxtot.mlxptr, game->mlxtot.wingame,
			game->mlxtot.door, x * 50, y * 50);
	if (game->parameter.map[y][x] == 'C')
		mlx_put_image_to_window(game->mlxtot.mlxptr, game->mlxtot.wingame,
			game->mlxtot.collect, x * 50, y * 50);
	if (game->parameter.map[y][x] == 'P')
	{
		game->mlxtot.playerposx = x;
		game->mlxtot.playerposy = y;
		mlx_put_image_to_window(game->mlxtot.mlxptr, game->mlxtot.wingame,
			game->mlxtot.player, x * 50, y * 50);
	}
}

void	charge_in_map(t_total *game)
{
	int	j;
	int	i;

	j = 0;
	while (game->parameter.map[j])
	{
		i = 0;
		while (game->parameter.map[j][i])
		{
			put_icon(game, i, j);
			i++;
		}
		j++;
	}
}
