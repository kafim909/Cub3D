/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtournay <mtournay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 18:20:23 by mtournay          #+#    #+#             */
/*   Updated: 2022/05/19 18:37:01 by mtournay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../head/cub3d.h"

void	print_map(char **line)
{
	int	i;

	i = -1;
	while (line[++i])
		printf("%s\n", line[i]);
}

int	count_lines_map(char **line)
{
	int	i;

	i = -1;
	while (line[++i]);
	return (i);
}

int	init_map(char **line, t_dmap *dmap)
{
	int	i;
	int	j;
	
	i = -1;
	j = -1;
	while (line[++i] && line[i][0] != ' ' && line[i][0] != '1');
	dmap->map = malloc(sizeof(char *) * (count_lines_map(&line[i]) + 1));
	if (!dmap->map)
		return (1);
	while (line[i])
	{
		dmap->map[++j] = ft_strdup(line[i]);
		if (!dmap->map[j])
			return (1);
		i++;
	}
	dmap->map[++j] = NULL;
	return (0);
}

int	firstlast_error(char *line1, char *line2)
{
	int	i;

	i = -1;
	while (line1[++i])
		if (line1[i] != '1' && line1[i] != ' ')
			return (1);
	i = -1;
	while (line2[++i])
		if (line2[i] != '1' && line2[i] != ' ')
			return (1);
	return (0);
}

int	in_map_char(char c)
{
	if (c == '0' || c == 'N' || c == 'S' || c == 'W'
		|| c == 'E')
		return (1);
	return (0);
}

int	cardinals(char c)
{
	if (c == 'N' || c == 'S' || c == 'W'
		|| c == 'E')
		return (1);
	return (0);
}

void	max_sizemap(double *x, double *y, char **map)
{
	int	tempx;
	int	i;
	int	j;

	tempx = 0;
	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
			if (tempx < j)
				tempx = j;
	}
	*y = i;
	*x = ++tempx;
}

void	cub_size(t_var *v, char **map)
{
	double	xmax;
	double	ymax;

	(void)v;
	max_sizemap(&xmax, &ymax, map);
	v->d_map.cubsizex = ((double)v->width / (double)xmax) / SIZE_MINIMAP;
	v->d_map.cubsizey = ((double)v->height / (double)ymax) / SIZE_MINIMAP;
}

int	player_pos(char **map, t_dfile *dfile, t_dmap dmap)
{
	int	i;
	int	j;

	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (cardinals(map[i][j]))
			{
				dfile->posx = j * dmap.cubsizex;
				dfile->posy = i * dmap.cubsizey;
				return (0);
			}
		}
	}
	return (1);
}

int	border_error(char *mid, char *up, char *down)
{
	int	i;

	i = -1;
	if (!down)
		return (0);
	while (mid[++i])
	{
		if (in_map_char(mid[i]))
			if (mid[i - 1] == ' ' || mid[i + 1] == ' ' ||
				up[i - 1] == ' ' || up[i] == ' ' || up[i + 1] == ' ' ||
				down[i - 1] == ' ' || down[i] == ' ' || down[i + 1] == ' ')
				return (1);
	}
	return (0);
}

int	error_map(char **line)
{
	int	i;
	
	i = 0;
	if (firstlast_error(line[0], line[count_lines_map(line) - 1]))
		return (1);
	while (line[++i])
	{
		if (border_error(line[i], line[i - 1], line[i + 1]))
			return (1);
	}
	return (0);

}

int   parse_map(t_var *v)
{	
	if (init_map(v->dfile.file, &v->d_map))
		exit(1);
	if (error_map(v->d_map.map))
		return (error_msg("error map"));
	cub_size(v, v->d_map.map);
	if (player_pos(v->d_map.map, &v->dfile, v->d_map))
		return (error_msg("player position missing"));
	v->d_eng.posx = v->dfile.posx;
	v->d_eng.posy = v->dfile.posy;
	return (0);
}