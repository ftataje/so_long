/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftataje- <ftataje-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 13:44:00 by ftataje-          #+#    #+#             */
/*   Updated: 2023/04/26 17:24:39 by ftataje-         ###   ########.fr       */
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
	rev_ber(&game->parameter);
	rev_open(&game->parameter, arg);
	rev_rectangular(&game->parameter);
	rev_chars(&game->parameter);

	/*revisa que sea .ber
	Abre y revisa si el archivo abre
	Revision errores*/

}

int	main(int argc, char **argv)
{
	t_total	game;

	if (argc != 2)
		perror("Error en cantidad de argumentos");
	ft_memset(&game, 0, sizeof(t_total));
	map_step(&game, argv[1]);
}
