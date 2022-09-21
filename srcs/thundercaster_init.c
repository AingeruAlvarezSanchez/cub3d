/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thundercaster_init.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adel-cor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 14:44:48 by adel-cor          #+#    #+#             */
/*   Updated: 2022/09/21 11:23:03 by adel-cor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubed.h"

void	ft_init_2(t_vault *vault)
{
	vault->ray.pos_x = (double)vault->init_x + 0.5;
	vault->ray.pos_y = (double)vault->init_y + 0.5;
	if (vault->compass == 'N')
		vault->ray.dir_x = -1;
	if (vault->compass == 'S')
		vault->ray.dir_x = 1;
	if (vault->compass == 'E')
		vault->ray.dir_y = 1;
	if (vault->compass == 'W')
		vault->ray.dir_y = -1;
	if (vault->compass == 'N')
		vault->ray.plan_y = 0.66;
	if (vault->compass == 'S')
		vault->ray.plan_y = -0.66;
	if (vault->compass == 'E')
		vault->ray.plan_x = 0.66;
	if (vault->compass == 'W')
		vault->ray.plan_x = -0.66;
}

void	ft_init_3(t_vault *vault)
{
	vault->ray.hit = 0;
	vault->ray.perpwalldist = 0;
	vault->ray.camera_x = 2 * vault->ray.x / (double)vault->rx - 1;
	vault->ray.raydir_x = vault->ray.dir_x + vault->ray.plan_x
		* vault->ray.camera_x;
	vault->ray.raydir_y = vault->ray.dir_y + vault->ray.plan_y
		* vault->ray.camera_x;
	vault->ray.map_x = (int)vault->ray.pos_x;
	vault->ray.map_y = (int)vault->ray.pos_y;
	vault->ray.movespeed = 0.1;
	vault->ray.rotspeed = 0.033 * 1.8;
	vault->ray.deltadist_x = fabs(1 / vault->ray.raydir_x);
	vault->ray.deltadist_y = fabs(1 / vault->ray.raydir_y);
}

void	ft_init_texture(t_vault *vault)
{
	if (vault->ray.side == 0 && vault->ray.raydir_x < 0)
		vault->t.texdir = 0;
	if (vault->ray.side == 0 && vault->ray.raydir_x >= 0)
		vault->t.texdir = 1;
	if (vault->ray.side == 1 && vault->ray.raydir_y < 0)
		vault->t.texdir = 2;
	if (vault->ray.side == 1 && vault->ray.raydir_y >= 0)
		vault->t.texdir = 3;
	if (vault->ray.side == 0)
		vault->t.wallx = vault->ray.pos_y + vault->ray.perpwalldist \
						* vault->ray.raydir_y;
	else
		vault->t.wallx = vault->ray.pos_x + vault->ray.perpwalldist \
						* vault->ray.raydir_x;
	vault->t.wallx -= floor((vault->t.wallx));
}
