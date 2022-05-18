/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtournay <mtournay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 12:21:20 by mtournay          #+#    #+#             */
/*   Updated: 2022/05/18 12:51:31 by mtournay         ###   ########.fr       */
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
# include "../libft/libft.h"

# define ANSI_COLOR_RED     "\x1b[31m"
# define ANSI_COLOR_RESET   "\x1b[0m"

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
	int		posx;
	int		posy;
}               t_dfile;

typedef struct s_dmap
{
	char	**map;
	int		start_x;
    int		start_y;
    char	dir;
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
	double	oldTime;
	double	camx;
	double	raydirx;
	double	raydiry;
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
	int			fd;
	int			width;
	int			height;
	void		*mlx;
	void		*mlx_win;
	t_dimg		dimg[2];
	t_dfile		dfile;
	t_err		err_bool;
	t_dmap		d_map;
}               t_var;

int		engine(t_var *v);

void 	read_file(char *path, t_dfile *dfile);
int		parsing(int argc, char *path, t_var *v);
void    parse_data(t_var *v);
int	    parse_map(t_var *v);

int		create_trgb(int t, int r, int g, int b);

int		error_file(t_var *v);
int		error_msg(char *s);
int		missing_data(t_err err);
int		valid_char_map(char c);


#endif