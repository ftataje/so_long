/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftataje- <ftataje-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 17:22:32 by ftataje-          #+#    #+#             */
/*   Updated: 2023/04/28 16:05:27 by ftataje-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <errno.h>
# include <string.h>
# include "../gnl/get_next_line.h"
# include "../miniLIBX/mlx.h"

typedef struct s_parameter
{
	int		fd;
	int		width;
	int		height;
	char	**map;
	char	*name;
	int		ccollect;
	int		cexit;
	int		cplayer;
}	t_parameter;

typedef struct s_total
{
	t_parameter	parameter;
	
}	t_total;

void	printerrors(char *str);
void	rev_ber(t_parameter *parameter, char *arg);
void	rev_open(t_parameter *parameter, char *arg);
void	rev_rectangular(t_parameter *parameter);
void	rev_chars(t_parameter *parameter);

/*
void	ft_putchar(char c);
void	ft_putnbr(int n);
void	ft_putstr(char *str);
*/

#endif
