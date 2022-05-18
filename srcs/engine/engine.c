/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtournay <mtournay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 11:36:41 by mtournay          #+#    #+#             */
/*   Updated: 2022/05/18 12:54:24 by mtournay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../head/cub3d.h"

void	draw_img(t_var *v)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (++x < 500)
		my_mlx_pixel_put(&v->dimg[0], x, y, v->dfile.color_c);
	while (++y < 300)
		my_mlx_pixel_put(&v->dimg[0], x, y, v->dfile.color_f);
	x = 200;
	y = 50;
	while (++y < 300)
		my_mlx_pixel_put(&v->dimg[0], x, y, v->dfile.color_f);
	while (++x < 500)
		my_mlx_pixel_put(&v->dimg[0], x, y, v->dfile.color_c);
}

void	draw_player(t_var *v, )
{
	my_mlx_pixel_put(&v->dimg[0], )
}

int	engine(t_var *v)
{
	draw_player(v);
}