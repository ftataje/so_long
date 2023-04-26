/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftataje- <ftataje-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 17:22:32 by ftataje-          #+#    #+#             */
/*   Updated: 2023/04/24 17:42:05 by ftataje-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <errno.h>
# include <string.h>
# include "get_next_line.h"
# include "../miniLIBX/mlx.h"

typedef struct s_game
{
	

}	t_game;

void	perror(char *str);


int		exit_point(t_complete *game);
int		map_reading(t_complete *game, char **argv);
int		controls_working(int command, t_complete *game);
void	adding_in_graphics(t_complete *game);
void	place_images_in_game(t_complete *game);
void	check_errors(t_complete *game);
int		showerror(t_complete *game, char *str);


void	ft_putchar(char c);
void	ft_putnbr(int n);
void	ft_putstr(char *str);
void	*ft_memset(void *str, int c, size_t len)

#endif
