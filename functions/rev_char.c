/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_char.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftataje- <ftataje-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 17:26:43 by ftataje-          #+#    #+#             */
/*   Updated: 2023/05/17 16:15:32 by ftataje-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

void	check_walls(t_parameter *parameter)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < parameter->width)
	{
		if (parameter->map[0][i] != '1' ||
			parameter->map[parameter->height -1][i] != '1')
			printerrors("Error, hay un hueco en la pared de arriba o abajo");
		i++;
	}
	while (j < parameter->height)
	{
		if (parameter->map[j][0] != '1' ||
			parameter->map[j][parameter->width -1] != '1')
			printerrors("Error, hay un hueco en la pared de los lados");
		j++;
	}
}

void	check_existchar(t_parameter *parameter)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (j < parameter->height)
	{
		i = 0;
		while (i < parameter->width)
		{
			if (parameter->map[j][i] == 'C')
				parameter->ccollect++;
			else if (parameter->map[j][i] == 'P')
				parameter->cplayer++;
			else if (parameter->map[j][i] == 'E')
				parameter->cexit++;
			i++;
		}
		j++;
	}
	if (parameter->ccollect < 1)
		printerrors("Error, mínimo debe haber un C en el mapa");
	if (parameter->cplayer != 1 || parameter->cexit != 1)
		printerrors("Error, solo debe haber un P y un E en el mapa");
}

void	check_validchar(t_parameter *parameter)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (j < parameter->height)
	{
		i = 0;
		while (i < parameter->width)
		{
			if (parameter->map[j][i] != 'C' && parameter->map[j][i] != 'P' &&
			parameter->map[j][i] != 'E' && parameter->map[j][i] != '1' &&
			parameter->map[j][i] != '0')
			{
				printerrors("Error, hay un char inválido");
			}
			i++;
		}
		j++;
	}
}

void	check_way(t_parameter *parameter)
{
	char	**m2;
	int		i;
	int		j;
	int		k;

	i = 0;
	j = 0;
	k = 0;
	m2 = ft_strdup(parameter);
	fill_way(m2, search_x(parameter, 'P'), search_y(parameter, 'P'));
	while (j < parameter->height)
	{
		i = 0;
		while (i < parameter->width)
		{
			if (m2[j][i] == 'E' || m2[j][i] == 'C')
				printerrors("Error, no hay camino a la salida");
			i++;
		}
		j++;
	}
	while (m2[k] != NULL)
		free(m2[k++]);
	free(m2);
}

void	rev_chars(t_parameter *parameter)
{
	check_walls(parameter);
	check_existchar(parameter);
	check_validchar(parameter);
	check_way(parameter);
}
