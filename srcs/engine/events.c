/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtournay <mtournay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 14:49:02 by mtournay          #+#    #+#             */
/*   Updated: 2022/05/18 18:25:32 by mtournay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../head/cub3d.h"

// W = 13
// S = 1
// A = 0
// D = 2

void	move_player(int keycode, double *x, double *y, char **map)
{
	(void)map;
	if (keycode == 13)
		*y -= 3;
	if (keycode == 1)
		*y += 3;
	if (keycode == 0)
		*x -= 3;
	if (keycode == 2)
		*x += 3;
}

int	ft_close(void)
{
	exit(1);
	return (0);
}

int	keyhook(int keycode, t_var *v)
{
	if (keycode == 53)
	{
		mlx_destroy_image(v->mlx, v->dimg[0].img);
		mlx_destroy_image(v->mlx, v->dimg[1].img);
		mlx_destroy_window(v->mlx, v->mlx_win);
		exit(0);
	}
	if (keycode == 13 || keycode == 1 || keycode == 0 || 
		keycode == 2)
		move_player(keycode, &v->dfile.posx, &v->dfile.posy, v->d_map.map);
	return (0);
}
