/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtournay <mtournay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 11:36:41 by mtournay          #+#    #+#             */
/*   Updated: 2022/05/25 11:07:53 by mtournay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../head/cub3d.h"


void	raycaster(t_engine *eng, t_var *v)
{
	int	x;
	
	x = -1;
	while (++x < v->width)
	{
		unsigned int temp;
		eng->camx = 2 * x / (double)v->width - 1;
		eng->raydirx = eng->dirx + eng->planex * eng->camx;
		eng->raydiry = eng->diry + eng->planey * eng->camx;
		eng->mapx = eng->posx; 
		eng->mapy = eng->posy;
		temp = 1 / eng->raydirx;
		eng->deltadistx = temp;
		// eng->deltadistx = abs(1 / eng->raydirx);
		// eng->deltadisty = abs(1 / eng->raydiry);
		eng->hit = 0;
		if (eng->raydirx < 0)
		{
			eng->stepx = -1;
			eng->sidedistx = (eng->posx - eng->mapx) * eng->deltadistx;
		}
		else
      	{
       		eng->stepx = 1;
    		eng->sidedistx = (eng->mapx + 1.0 - eng->posx) * eng->deltadistx;
      	}
      	if (eng->raydiry < 0)
      	{
      		eng->stepy = -1;
			eng->sidedisty = (eng->posy - eng->mapy) * eng->deltadisty;
      	}
      	else
      	{
        	eng->stepy = 1;
        	eng->sidedisty = (eng->mapy + 1.0 - eng->posy) * eng->deltadisty;
      	}
      	while (eng->hit == 0)
      	{
        	if (eng->sidedistx < eng->sidedisty)
        	{
          		eng->sidedistx += eng->deltadistx;
          		eng->mapx += eng->stepx;
          		eng->side = 0;
        	}
        	else
        	{
          		eng->sidedisty += eng->deltadisty;
          		eng->mapy += eng->stepy;
          		eng->side = 1;
			}
        	if (v->d_map.map[eng->mapx][eng->mapy] > 0) 
				eng->hit = 1;
      	}
		if(eng->side == 0)
			eng->perpwalldist = (eng->sidedisty - eng->deltadistx);
      	else
		  	eng->perpwalldist = (eng->sidedisty - eng->deltadisty);
		
      	eng->lineheight = (int)(v->height / eng->perpwalldist);
		eng->drawstart = -eng->lineheight / 2 + v->height / 2;		
		if(eng->drawstart < 0)
			eng->drawstart = 0;		
		eng->drawend = eng->lineheight / 2 + v->height / 2;		
		if(eng->drawend >= v->height)
			eng->drawend = v->height - 1;
		if (v->d_map.map[v->d_eng.mapy][v->d_eng.mapx] == '1')
			v->color = 0xFF0000;
		if (v->d_eng.side == 1)
			v->color = v->color / 2;
		verline(x, *v, v->color);
	}
	// v->d_eng.oldtime = v->d_eng.time;
	// v->d_eng.time = 
	
}

int	engine(t_var *v)
{
	minimap(v);
	// raycaster(&v->d_eng, v);
	return(0);
}