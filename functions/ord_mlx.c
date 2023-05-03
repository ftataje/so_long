/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ord_mlx.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftataje- <ftataje-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 18:09:50 by ftataje-          #+#    #+#             */
/*   Updated: 2023/05/03 16:05:07 by ftataje-         ###   ########.fr       */
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
	if (game->parameter.map[y][x] == 'C' || game->parameter.map[y][x] == '0')
	{
		game->parameter.map[y][x] = 'P';
		game->mlxtot.steps++;
		ft_putstr("Step #");
		ft_putnbr(game->mlxtot.steps);
		write(1, "\n", 1);
	}
	if (game->parameter.map[y][x] == 'E')
	{
		game->mlxtot.steps++;
		ft_putstr("Step #");
		ft_putnbr(game->mlxtot.steps);
		write(1, "\n", 1);
		ft_putstr("Has ganado!!!!");
		finishgame(game);
	}
	return (1);
}

static int	key_up_down(t_total *game, int move, int x, int y)
{
	x = game->mlxtot.playerposx;
	y = game->mlxtot.playerposy;
	if (move == 13)
	{
		if (game->parameter.map[y -1][x] == '1')
			return (0);
		if (game->parameter.map[y -1][x] == 'E' && exist_collect(game) == 0)
			return (0);
		y--;
		rotate(game, x, y);
		game->parameter.map[y +1][x] = '0';
	}
	if (move == 1)
	{
		if (game->parameter.map[y +1][x] == '1')
			return (0);
		if (game->parameter.map[y +1][x] == 'E' && exist_collect(game) == 0)
			return (0);
		y++;
		rotate(game, x, y);
		game->parameter.map[y -1][x] = '0';
	}
	return (1);
}

static int	key_right_left(t_total *game, int move, int x, int y)
{
	x = game->mlxtot.playerposx;
	y = game->mlxtot.playerposy;
	if (move == 0)
	{
		if (game->parameter.map[y][x -1] == '1')
			return (0);
		if (game->parameter.map[y][x -1] == 'E' && exist_collect(game) == 0)
			return (0);
		x--;
		rotate(game, x, y);
		game->parameter.map[y][x +1] = '0';
	}
	if (move == 2)
	{
		if (game->parameter.map[y][x +1] == '1')
			return (0);
		if (game->parameter.map[y][x +1] == 'E' && exist_collect(game) == 0)
			return (0);
		x++;
		rotate(game, x, y);
		game->parameter.map[y][x -1] = '0';
	}
	return (1);
}

int	func_ord(int key, t_total *game)
{
	int	z;
	int	x;
	int	y;

	z = 0;
	x = 0;
	y = 0;
	if (key == 13)
		z = key_up_down(game, key, x, y);
	if (key == 2)
		z = key_right_left(game, key, x, y);
	if (key == 1)
		z = key_up_down(game, key, x, y);
	if (key == 0)
		z = key_right_left(game, key, x, y);
	if (key == 53)
		exit(1);
	if (z)
	{
		charge_in_map(game);
	}
	return (1);
}
