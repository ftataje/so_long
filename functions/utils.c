/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftataje- <ftataje-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 14:59:31 by ftataje-          #+#    #+#             */
/*   Updated: 2023/05/01 19:50:00 by ftataje-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

void	printerrors(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	exit (1);
}

int	search_x(t_parameter *parameter, char c)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < parameter->height)
	{
		j = 0;
		while (j < parameter->width)
		{
			if (parameter->map[i][j] == c)
				return (j);
			j++;
		}
		i++;
	}
	printerrors("Error, no se encontro el char en el eje X");
	return (-1);
}

int	search_y(t_parameter *parameter, char c)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < parameter->height)
	{
		j = 0;
		while (j < parameter->width)
		{
			if (parameter->map[i][j] == c)
				return (i);
			j++;
		}
		i++;
	}
	printerrors("Error, no se encontro el char en el eje Y");
	return (-1);
}