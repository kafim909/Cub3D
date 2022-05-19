/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_minimap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtournay <mtournay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 16:12:30 by mtournay          #+#    #+#             */
/*   Updated: 2022/05/19 18:35:18 by mtournay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../head/cub3d.h"

void	draw_square(t_var *v, int x, int y, int color)
{
	int	i;
	int	j;
	int temp;

	i = -1;
	x *= v->d_map.cubsizex;
	y *= v->d_map.cubsizey;
	temp = x;
	while (++i < v->d_map.cubsizey)
	{
		j = -1;
		x = temp;
		while (++j < v->d_map.cubsizex)
		{
			if (x >= 0 && y >= 0)
			{
				my_mlx_pixel_put(&v->dimg[0], x, y, color);
				my_mlx_pixel_put(&v->dimg[1], x, y, color);
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
				draw_square(v, j, i, 0x2d1f5d);
			if (map[i][j] == '0' || cardinals(map[i][j]))
				draw_square(v, j, i, 0xfcf0f4);
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
	while (++i < (v->d_map.cubsizey - 5))
	{
		j = -1;
		x = temp;
		while (++j < (v->d_map.cubsizex - 5))
		{
			my_mlx_pixel_put(&v->dimg[0], x, y, v->dfile.color_c);
			my_mlx_pixel_put(&v->dimg[1], x, y, v->dfile.color_c);
			x++;
		}
		y++;
	}
}

void	minimap(t_var *v)
{
	draw_map(v, v->d_map.map);
	draw_player(v, v->d_eng.posx, v->d_eng.posy);
}