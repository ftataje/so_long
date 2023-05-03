/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_mls.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftataje- <ftataje-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 14:03:31 by ftataje-          #+#    #+#             */
/*   Updated: 2023/05/03 16:08:10 by ftataje-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int n)
{
	if (n / 10)
		ft_putnbr(n / 10);
	ft_putchar(n % 10 + '0');
}

void	ft_putstr(char *s)
{
	int	i;

	if (!s)
		return ;
	i = 0;
	while (s[i])
	{
		ft_putchar(s[i]);
		i++;
	}
}

void	finishgame(t_total *game)
{
	int	j;

	j = 0;
	mlx_destroy_window(game->mlxtot.mlxptr, game->mlxtot.wingame);
	while (game->parameter.map[j])
	{
		free(game->parameter.map[j]);
		j++;
	}
	free(game->parameter.map);
	exit (0);
}
