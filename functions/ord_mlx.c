/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ord_mlx.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftataje- <ftataje-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 18:09:50 by ftataje-          #+#    #+#             */
/*   Updated: 2023/05/02 20:06:55 by ftataje-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

int	exist_collect(t_total *game)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	game->mlxtot.ccollect2 = 0;
	while (j < game->parameter.height)
	{
		i = 0;
		while (i < game->parameter.width)
		{
			if (game->parameter.map[j][i] == 'C')
				game->mlxtot.ccollect2++;
			i++;
		}
		j++;
	}
	if (game->mlxtot.ccollect2 < 1)
		return (1);
	return (0);
}

static int	rotate(t_total *game, int x, int y)
{
	if (game->parameter.map[y][x] == 'C')
		game->parameter.map[y][x] = '0';
	
}

static int	key_up_down(t_total *game, int move)
{
	int	x;
	int	y;

	if (move == 13)
	{
		x = game->mlxtot.playerposx;
		y = game->mlxtot.playerposy;
		if (game->parameter.map[y -1][x] == '1')
			return (0);
		if (game->parameter.map[y -1][x] == 'E' && exist_collect(game) == 0)
			return (0);
		y--;
		rotate(game, x, y);
		game->parameter.map[y +1][x] == '0';
	}
	if (move == 1)
	{
		/* code */
	}
}

int	func_ord(int key, t_total *game)
{
	int	z;

	if (key == 13) //arriba
		z = key_up_down(game, key);
	if (key == 2) //derecha
		z = key_right_left(game, key);
	if (key == 1) //abajo
		z = key_up_down(game, key);
	if (key == 0) //izq
		z = key_right_left(game, key);
	if (key == 53)
		exit(1);
	if (z)
	{
		//write move
		//add in grafic
	}
	return (1);
}
