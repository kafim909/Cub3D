/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtournay <mtournay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 19:44:06 by mtournay          #+#    #+#             */
/*   Updated: 2022/05/16 19:56:43 by mtournay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../head/cub3d.h"

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

int	error_line(char *line, t_err *err)
{
	int i;

	i = -1;
	if (error_char(line[i + 1], err))
		return (1);
	if (line[i + 1] == ' ')
	{
		while (line[++i])
		{
			if (line[i] == '1')
				break ;
			if (line[i] != ' ')
				return (1); 
		}
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
			return (error_msg(NULL, NULL, "Invalid characters in file", &v->dfile.error));
	return (0);
}