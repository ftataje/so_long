/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftataje- <ftataje-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 14:59:31 by ftataje-          #+#    #+#             */
/*   Updated: 2023/05/17 16:09:16 by ftataje-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

void	printerrors(char *str)
{
	int	i;

	i = 0;
	write(1, "\033[31m", 5);
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	write(1, "\033[0m", 4);
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

void	fill_way(char **map, int x, int y)
{
	if (map[y][x] == '0' || map[y][x] == 'C' ||
		map[y][x] == 'P')
	{
		map[y][x] = 'A';
		fill_way(map, x + 1, y);
		fill_way(map, x - 1, y);
		fill_way(map, x, y + 1);
		fill_way(map, x, y - 1);
	}
	if (map[y][x] == 'E')
	{
		map[y][x] = 'Z';
	}
}

char	**ft_strdup(t_parameter *parameter)
{
	char	**new;
	int		i;
	int		j;

	new = (char **)malloc(sizeof(char **) * (parameter->height + 1));
	if (!new)
		return (NULL);
	j = 0;
	while (j < parameter->height)
	{
		new[j] = (char *)malloc(sizeof(char) * (parameter->width + 1));
		i = 0;
		while (i < parameter->width)
		{
			new[j][i] = parameter->map[j][i];
			i++;
		}
		new[j][i] = '\0';
		j++;
	}
	new[j] = NULL;
	return (new);
}
