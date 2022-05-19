/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtournay <mtournay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 14:49:02 by mtournay          #+#    #+#             */
/*   Updated: 2022/05/19 18:35:25 by mtournay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../head/cub3d.h"

// W = 13
// S = 1
// A = 0
// D = 2

int	is_wall(t_dmap dmap, double x, double y)
{
	double right_x;
	double right_y;

	right_x = (x + dmap.cubsizex - 5) / (dmap.cubsizex);
	right_y = (y + dmap.cubsizey - 5) / (dmap.cubsizey);
	x = x / dmap.cubsizex;
	y = y / dmap.cubsizey;
	if (dmap.map[(int)y][(int)x] == '1' || dmap.map[(int)y][(int)right_x] == '1' 
		|| dmap.map[(int)right_y][(int)x] == '1' 
		|| dmap.map[(int)right_y][(int)right_x] == '1')
		return (1);
	return (0);
}

void	move_player(int keycode, double *x, double *y, t_dmap dmap)
{
	if (keycode == 13 && !is_wall(dmap, *x, *y - 3))
		*y -= 3;
	if (keycode == 1 && !is_wall(dmap, *x, *y + 3))
		*y += 3;
	if (keycode == 0 && !is_wall(dmap, *x - 3, *y))
		*x -= 3;
	if (keycode == 2 && !is_wall(dmap, *x + 3, *y))
		*x += 3;
}

int	ft_close(void)
{
	exit(1);
	return (0);
}
