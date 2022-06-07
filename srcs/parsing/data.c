/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtournay <mtournay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 15:51:22 by mtournay          #+#    #+#             */
/*   Updated: 2022/05/25 12:19:37 by mtournay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../head/cub3d.h"

int	color_conversion(int *color, char **buf)
{
	int col[3];
	int i;

	i = -1;
	while (buf[++i])
	{
		col[i] = atoi(buf[i]);
		if (col[i] > 255)
			return (1);
	}
	*color = create_trgb(0, col[0], col[1], col[2]);
	return (0);
}

int	trim_spaces(char **buf)
{
	char	*temp;
	int		i;

	i = -1;
	while (buf[++i])
	{
		temp = buf[i];
		buf[i] = ft_strtrim(buf[i], " ");
		if (!buf[i])
			exit(1);
		free(temp);
		if (!buf[i][0])
			error_msg("color missing");
	}
	return (0);
}

int	error_colors(char **buf)
{
	int	i;
	int	j;
	
	i = -1;
	while (buf[++i] && i < 3)
	{
		trim_spaces(buf);
		j = -1;
		while (buf[i][++j] && (ft_isdigit(buf[i][j]) || buf[i][j] == ' '));
		if (buf[i][j])
			return (1);
	}
	if (buf[i])
		return (1);
	if (i < 3)
		return (1);
	return (0);
}

int	parse_colors(t_dfile *dfile, char *fc, int *color)
{
	int		i;
	int		j;
	char	**buf;

	i = -1;
	j = 1;
	while (dfile->file[++i] && ft_strncmp(dfile->file[i], fc, 1));
	if (i == dfile->size_file)
		return (error_msg("colors 1"));

	if (!dfile->file[i][j] || !dfile->file[i][j + 1] ||
		(dfile->file[i][j] != ' ' && !ft_isdigit(dfile->file[i][j + 1])))
		return (error_msg("colors 2"));
	buf = ft_split(&dfile->file[i][++j], ',');
	if (!buf)
		exit(1);
	if (error_colors(buf))
		return (error_msg("colors 3"));
		(void)color;
	if (color_conversion(color, buf))
		return (error_msg("colors 4"));
	return (0);
}

int	parse_texture(t_dfile *dfile, char *texture, char **save)
{
	int	i;
	int j;

	i = -1;
	j = -1;
	while (dfile->file[++i] && ft_strncmp(dfile->file[i], texture, 2));
	if (i == dfile->size_file)
		return (error_msg("texture 1"));
	while (dfile->file[i][++j] && dfile->file[i][j + 1] && 
			dfile->file[i][j] != '.' && dfile->file[i][j + 1] != '/');
	if (!dfile->file[i][j + 1])
		return (error_msg("texture 2"));
	*save = ft_strdup(&dfile->file[i][j]);
	if (!*save)
		exit(1);
	return (0);
}

void    parse_data(t_var *v)
{
	parse_texture(&v->dfile, "NO", &v->dfile.north);
	parse_texture(&v->dfile, "SO", &v->dfile.south);
	parse_texture(&v->dfile, "WE", &v->dfile.east);
	parse_texture(&v->dfile, "EA", &v->dfile.west);
	parse_colors(&v->dfile, "F", &v->dfile.color_f);
	parse_colors(&v->dfile, "C", &v->dfile.color_c);
	missing_data(v->err_bool);
}