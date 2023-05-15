/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftataje- <ftataje-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 13:44:00 by ftataje-          #+#    #+#             */
/*   Updated: 2023/05/15 21:40:58 by ftataje-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/so_long.h"

static void	*ft_memset(void *str, int c, size_t len)
{
	unsigned char	*newstr;
	size_t			i;

	i = 0;
	newstr = str;
	while (i < len)
	{
		newstr[i] = (unsigned char)c;
		i++;
	}
	return (newstr);
}

void	map_step(t_total *game, char *arg)
{
	rev_ber(&game->parameter, arg);
	rev_open(&game->parameter, arg);
	rev_rectangular(&game->parameter);
	rev_chars(&game->parameter);
}

int	main(int argc, char **argv)
{
	t_total	game;

	if (argc != 2)
		printerrors("Error en cantidad de argumentos");
	ft_memset(&game, 0, sizeof(game));
	map_step(&game, argv[1]);
	game.mlxtot.mlxptr = mlx_init();
	game.mlxtot.wingame = mlx_new_window(game.mlxtot.mlxptr,
			(game.parameter.width * 50),
			(game.parameter.height * 50), "so_long");
	charge_images(&game);
	charge_in_map(&game);
	mlx_key_hook(game.mlxtot.wingame, func_ord, &game);
	mlx_hook(game.mlxtot.wingame, 17, 0, (void *)exit, 0);
	mlx_loop(game.mlxtot.mlxptr);
}
