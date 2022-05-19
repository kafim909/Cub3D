/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtournay <mtournay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 11:36:41 by mtournay          #+#    #+#             */
/*   Updated: 2022/05/18 18:37:37 by mtournay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../head/cub3d.h"

void	draw_square(t_var *v, int x, int y)
{
	int	i;
	int	j;
	int temp;

	i = -1;
	// printf("%lf %lf \n", v->d_map.cubsizex, v->d_map.cubsizey);
	// x *= v->d_map.cubsizex;
	y *= v->d_map.cubsizey;
	temp = x;
	// printf("%d %d\n", x, y);
	while (++i < v->d_map.cubsizey)
	{
		j = -1;
		x = temp;
		while (++j < v->d_map.cubsizex)
		{
			if (x >= 0 && y >= 0)
			{
				my_mlx_pixel_put(&v->dimg[0], x, y, v->dfile.color_f);
				my_mlx_pixel_put(&v->dimg[1], x, y, v->dfile.color_f);
			}
			x++;	
		}
		y++;
	}
}

void	draw_map(t_var *v, char **map)
{
	int	i;
	int	j;
	int offset;

	i = -1;
	offset = 0;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (map[i][j] == '1')
				draw_square(v, j, i);
		}
	}
}

void	draw_player(t_var *v, int x, int y)
{
	int	i;
	int	j;
	int	temp;

	i = -1;
	temp = x;
	while (++i < 8)
	{
		j = -1;
		x = temp;
		while (++j < 8)
		{
			my_mlx_pixel_put(&v->dimg[0], x, y, v->dfile.color_c);
			my_mlx_pixel_put(&v->dimg[1], x, y, v->dfile.color_c);
			x++;
		}
		y++;
	}
}

int	engine(t_var *v)
{
	draw_map(v, v->d_map.map);
	draw_player(v, v->dfile.posx, v->dfile.posy);
	return(0);
}