/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtournay <mtournay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 19:44:06 by mtournay          #+#    #+#             */
/*   Updated: 2022/06/01 13:00:21 by mtournay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../head/cub3d.h"

int	error_msg(char *s)
{
	printf(ANSI_COLOR_RED  "ERROR\n" ANSI_COLOR_RESET);
	if (s)
		printf("%s\n", s);
	printf("Missing or invalid data/map\n");
	return (exit(1), 1);
}

void	init_error_bools(t_err *err)
{
	err->n = 1;
	err->c = 1;
	err->f = 1;
	err->w = 1;
	err->e = 1;
	err->s = 1;	
}

int error_char_2(char c, t_err *err)
{
	if (c == 'W' && err->w)
	{
		err->w = 0;
		return (0);
	}
	if (c == 'E' && err->e)
	{
		err->e = 0;
		return (0);
	}
	if (c == 'S' && err->s)
	{
		err->s = 0;
		return (0);
	}
    if (c == '\0' || c == ' ' || c == '1')
        return (0);
	return (1);
}

int error_char(char c, t_err *err)
{
	if (c == 'N' && err->n)
	{
		err->n = 0;
		return (0);
	}
	if (c == 'C' && err->c)
	{
		err->c = 0;
		return (0);
	}
	if (c == 'F' && err->f)
	{
		err->f = 0;
		return (0);
	}
    return (error_char_2(c, err));
}

int	valid_char_map(char c)
{
	if (c != '1' && c != '0' && c != ' ' && c != '\0' && c != 'N' && c != 'S'
		&& c != 'W' && c != 'E')
		return (1);
	return (0);
}

int	error_line(char *line, t_err *err)
{
	int i;

	i = -1;
	if (error_char(line[i + 1], err))
		return (1);
	if (line[i + 1] == ' ' || line[i + 1] == '1')
	{
		while (line[++i] && line[i] == ' ');
		if (line[i] != '1')
			return (1);
		while (line[++i])
			if (valid_char_map(line[i]))
				return (1);
	}
	return (0);
}

int	error_file(t_var *v)
{
	int		i;

	i = -1;
    init_error_bools(&v->err_bool);
	while(v->dfile.file[++i])
		if(error_line(v->dfile.file[i], &v->err_bool))
			error_msg("error file");
	return (0);
}

int	missing_data(t_err err)
{
	if (err.c || err.e || err.f || err.n || err.s || err.w)
		error_msg("missing data");
	return (0);
}