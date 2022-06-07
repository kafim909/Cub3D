/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_manager.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtournay <mtournay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 14:11:47 by mtournay          #+#    #+#             */
/*   Updated: 2022/05/25 11:08:24 by mtournay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../head/cub3d.h"

int	keyhook(int keycode, t_var *v)
{
	// printf("%d\n", keycode);
	if (keycode == 53)
	{
		mlx_destroy_image(v->mlx, v->dimg[0].img);
		mlx_destroy_image(v->mlx, v->dimg[1].img);
		mlx_destroy_window(v->mlx, v->mlx_win);
		exit(0);
	}
	if (keycode == 13 || keycode == 1 || keycode == 0 || 
		keycode == 2)
		move_player(keycode, &v->d_eng.posx, &v->d_eng.posy, v->d_map);
	return (0);
}