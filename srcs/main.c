/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtournay <mtournay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 12:17:19 by mtournay          #+#    #+#             */
/*   Updated: 2022/05/18 18:39:27 by mtournay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

void	my_mlx_pixel_put(t_dimg *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void    init(t_var *v)
{
	int	i;

	i = -1;
    v->mlx = mlx_init();
	v->mlx_win = mlx_new_window(v->mlx, v->width, v->height, "Hello world!");
	generate_img(v, &v->dimg[0]);
	generate_img(v, &v->dimg[1]);
}

void	init_struct(t_var *v)
{
	v->width = 1024;
	v->height = 512;
}

int	instance(t_var *v)
{
	engine(v);
	img_loop(v);
	mlx_hook(v->mlx_win, 17, 1L << 5, ft_close, v);
	mlx_hook(v->mlx_win, 2, 1L << 0, keyhook, v);
	return (0);
}

int main(int argc, char **argv)
{
	t_var	v;

	(void)argc;
	init_struct(&v);
	parsing(argc, argv[1], &v);
	init(&v);
	// draw_img(&v);
	mlx_loop_hook(v.mlx, instance, &v);
	mlx_loop(v.mlx);
}