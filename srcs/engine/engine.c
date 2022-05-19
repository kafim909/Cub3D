/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtournay <mtournay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 11:36:41 by mtournay          #+#    #+#             */
/*   Updated: 2022/05/19 19:53:00 by mtournay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../head/cub3d.h"


void	raycaster(t_engine *eng, t_var *v)
{
	int	x;
	
	x = -1;
	while (++x < v->width)
	{
		eng->camx = 2 * x / (double)v->width - 1;
		eng->raydirx = eng->dirx + eng->planex * eng->camx;
		eng->raydiry = eng->diry + eng->planey * eng->camx;
		eng->mapx = eng->posx; 
		eng->mapy = eng->posy;
	}
}

int	engine(t_var *v)
{
	minimap(v);
	return(0);
}