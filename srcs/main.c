/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtournay <mtournay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 12:17:19 by mtournay          #+#    #+#             */
/*   Updated: 2022/05/16 19:55:13 by mtournay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	error_msg(char *s1, char *s2, char *s3, int *ret)
{
	write(1, "ERROR\n", 6);
	if (s1)
		printf("%s", s1);
	if (s2)
		printf("%s", s2);
	if (s3)
		printf("%s\n", s3);
	*ret = 1;
	return (exit(1), 1);
}

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

void	draw_img(t_var *v)
{
	int	x;
	int	y;

	x = 200;
	y = 50;
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

void    init(t_var *v)
{
	int	i;

	i = -1;
    v->mlx = mlx_init();
	v->mlx_win = mlx_new_window(v->mlx, v->width, v->height, "Hello world!"); 
	while (++i < 2)
	{
		v->dimg[i].img = mlx_new_image(v->mlx, v->width, v->height);
		v->dimg[i].addr = mlx_get_data_addr(v->dimg[i].img, &v->dimg[i].bits_per_pixel, 
							&v->dimg[i].line_length, &v->dimg[i].endian);
	}
}

void	init_struct(t_var *v)
{
	v->width = 1024;
	v->height = 576;
}

int main(int argc, char **argv)
{
	t_var	v;

	(void)argc;
	init_struct(&v);
	parsing(argc, argv[1], &v);
	init(&v);
	draw_img(&v);
	mlx_put_image_to_window(v.mlx, v.mlx_win, v.dimg[0].img, 0, 0);
	mlx_loop(v.mlx);
}