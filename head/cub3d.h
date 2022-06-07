/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtournay <mtournay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 12:21:20 by mtournay          #+#    #+#             */
/*   Updated: 2022/05/20 10:40:19 by mtournay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef cub3d_H
# define cub3d_H

# include "mlx.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <math.h>
# include "../libft/libft.h"

# define ANSI_COLOR_RED     "\x1b[31m"
# define ANSI_COLOR_RESET   "\x1b[0m"

# define PI 3.1415926535
# define SIZE_MINIMAP 4

typedef struct s_error
{
	int	n;
	int	c;
	int	f;
	int	w;
	int	e;
	int	s;
}				t_err;

typedef struct s_dfile
{
    char	*north;
    char	*south;
    char	*east;
    char	*west;
	int		color_c;
	int		color_f;
    char	**file;
	int		size_file;
	double	posx;
	double	posy;
}               t_dfile;

typedef struct s_dmap
{
	char	**map;
	int		start_x;
    int		start_y;
    char	dir;
	double	cubsizex;
	double	cubsizey;
}				t_dmap;

typedef struct s_dengine
{
	double	posx;
	double	posy;
	double	dirx;
	double	diry;
	double	planex;
	double	planey;
	double	time;
	double	oldtime;
	double	camx;
	double	raydirx;
	double	raydiry;
	int		mapx;
	int		mapy;
	double	sidedistx;
	double	sidedisty;
	double	deltadistx;
	double	deltadisty;
	double	perpwalldist;
	int		stepx;
	int		stepy;
	int		hit;
	int		side;
	int		lineheight;
	int		drawstart;
	int		drawend;

}				t_engine;

typedef struct s_dimg
{
    void	*img;
    char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}               t_dimg;

typedef struct s_var
{
	int			color;
	int			fd;
	double		width;
	double		height;
	void		*mlx;
	void		*mlx_win;
	t_dimg		dimg[2];
	t_dfile		dfile;
	t_err		err_bool;
	t_dmap		d_map;
	t_engine	d_eng;
}               t_var;

void	verline(int x, t_var v, int color);
void	generate_img(t_var *v, t_dimg *dimg);
void	img_loop(t_var *v);

void	minimap(t_var *v);

void	generate_img(t_var *v, t_dimg *img);

int		keyhook(int keycode, t_var *v);

void	move_player(int keycode, double *x, double *y, t_dmap dmap);
int		close_window(int keycode, t_var *v);
int		ft_close(void);

void	my_mlx_pixel_put(t_dimg *data, int x, int y, int color);
int		create_trgb(int t, int r, int g, int b);

int		engine(t_var *v);

void 	read_file(char *path, t_dfile *dfile);
int		parsing(int argc, char *path, t_var *v);
void    parse_data(t_var *v);
int	    parse_map(t_var *v);
int		cardinals(char c);

int		create_trgb(int t, int r, int g, int b);

int		error_file(t_var *v);
int		error_msg(char *s);
int		missing_data(t_err err);
int		valid_char_map(char c);


#endif