/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtournay <mtournay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 15:33:03 by mtournay          #+#    #+#             */
/*   Updated: 2022/05/18 15:57:56 by mtournay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../head/cub3d.h"

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