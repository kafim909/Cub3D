/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtournay <mtournay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 12:21:20 by mtournay          #+#    #+#             */
/*   Updated: 2022/05/16 20:02:49 by mtournay         ###   ########.fr       */
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
	int		start_x;
    int		start_y;
    char	dir;
    char	**file;
	int		size_file;
	int		error;
	char	**map;
}               t_dfile;

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
}               t_var;

void read_file(char *path, t_dfile *dfile);
int	parsing(int argc, char *path, t_var *v);
void    parse_data(t_var *v);
void    parse_map(t_var *v);
int	error_file(t_var *v);


int	create_trgb(int t, int r, int g, int b);

int	error_msg(char *s1, char *s2, char *s3, int *ret);

#endif