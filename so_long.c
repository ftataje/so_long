/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftataje- <ftataje-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 13:44:00 by ftataje-          #+#    #+#             */
/*   Updated: 2022/09/30 13:44:02 by ftataje-         ###   ########.fr       */
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

void	map_step(t_game *game, char *)
{

}

int	main(int argc, char **argv)
{
	t_game	game;

	if(argc != 2)
		perror("Error en cantidad de argumentos");
	ft_memset(&game, 0, sizeof(t_game));
	map_step(&game, argv[1]);


	
	

	


	

}