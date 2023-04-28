/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftataje- <ftataje-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 15:03:57 by ftataje-          #+#    #+#             */
/*   Updated: 2023/04/28 15:25:28 by ftataje-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

void	rev_ber(t_parameter *parameter, char *str)
{
	int	i;

	i = 0;
	parameter->name = str;
	i = ft_strlen(parameter->name);
	if (parameter->name[i - 1] != 'r' || parameter->name[i - 2] != 'e'
		|| parameter->name[i - 3] != 'b' || parameter->name[i - 4] != '.')
	{
		printerrors("Error, el mapa no es '.ber'");
	}
}

void	rev_open(t_parameter *parameter, char *arg)
{
	parameter->fd = open(arg, O_RDONLY);
	if (parameter->fd < 0 ) // || parameter->fd > 2)
	{
		close(parameter->fd);
		printerrors("Error, al abrir el argumento indicado");
	}
}

static int	map_width(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	if (str[i-1] == '\n')
	{
		i--;
	}
	return (i);
}

static int	check_widths(t_parameter *parameter, char *str)
{
	char	**tmp;
	int		i;
	
	if (!str)
		return (0);
	i = -1;
	parameter->height++;
	tmp = (char **)malloc(sizeof(char *) *(parameter->height+1));
	tmp[parameter->height] = NULL;
	while (++i < parameter->height -1)
	{
		if(map_width(str) == map_width(parameter->map[i]))
			tmp[i] = parameter->map[i];
		else
			printerrors("Error, mapa no es rectangular");
	}
	tmp[i] = str;
	if (parameter->map)
		free(parameter->map);
	parameter->map = tmp;
	return (1);
}

void	rev_rectangular(t_parameter *parameter)
{
	char	*rmap;
	//int		i;
	//char	**tmp;

	while (1)
	{
		rmap = get_next_line(parameter->fd);
		if (!check_widths(parameter, rmap))
			break ;
	}
	parameter->width = map_width(parameter->map[0]);
	if (parameter->height == parameter->width)
		printerrors("Error, es un cuadrado");
}
