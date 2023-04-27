/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_char.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftataje- <ftataje-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 17:26:43 by ftataje-          #+#    #+#             */
/*   Updated: 2023/04/27 15:39:38 by ftataje-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

void	check_walls(t_parameter *parameter)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i++ <= parameter->width)
	{
		if (parameter->map[0][i] != 1 ||
			parameter->map[parameter->height][i] != 1)
			printerrors("Error, hay un hueco en la pared de arriba o abajo");
	}
	while (j++ <= parameter->height)
	{
		if (parameter->map[j][0] != 1 ||
			parameter->map[j][parameter->width] != 1)
			printerrors("Error, hay un hueco en la pared de los lados");
	}
}

void	rev_chars(t_parameter *parameter)
{
	check_walls(parameter);
}
