/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtournay <mtournay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 15:33:03 by mtournay          #+#    #+#             */
/*   Updated: 2022/05/20 10:19:30 by mtournay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../head/cub3d.h"

void	verline(int x, t_var v, int color)
{
	while (v.d_eng.drawstart < v.d_eng.drawend)
	{
		my_mlx_pixel_put(&v.dimg[0], x, v.d_eng.drawstart, color);
		my_mlx_pixel_put(&v.dimg[1], x, v.d_eng.drawstart, color);
		v.d_eng.drawstart++;
	}
}

void	generate_img(t_var *v, t_dimg *dimg)
{
	dimg->img = mlx_new_image(v->mlx, v->width, v->height);
	dimg->addr = mlx_get_data_addr(dimg->img, &dimg->bits_per_pixel, 
							&dimg->line_length, &v->dimg->endian);	
}

void	img_loop(t_var *v)
{
	mlx_put_image_to_window(v->mlx, v->mlx_win, v->dimg[0].img, 0, 0);
	mlx_destroy_image(v->mlx, v->dimg[1].img);
	generate_img(v, &v->dimg[1]);
	mlx_put_image_to_window(v->mlx, v->mlx_win, v->dimg[1].img, 0, 0);
	mlx_destroy_image(v->mlx, v->dimg[0].img);
	generate_img(v, &v->dimg[0]);
}