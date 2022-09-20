/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thundercaster_init.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adel-cor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 14:44:48 by adel-cor          #+#    #+#             */
/*   Updated: 2022/09/20 16:18:13 by adel-cor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubed.h"

void	ft_init_2(t_vault *vault)
{
	vault->ray.posX = (double)vault->init_x + 0.5;
	vault->ray.posY = (double)vault->init_y + 0.5;
	if (vault->compass == 'N')
		vault->ray.dirX = -1;
	if (vault->compass == 'S')
		vault->ray.dirX = 1;
	if (vault->compass == 'E')
		vault->ray.dirY = 1;
	if (vault->compass == 'W')
		vault->ray.dirY = -1;
	if (vault->compass == 'N')
		vault->ray.planY = 0.66;
	if (vault->compass == 'S')
		vault->ray.planY = -0.66;
	if (vault->compass == 'E')
		vault->ray.planX = 0.66;
	if (vault->compass == 'W')
		vault->ray.planX = -0.66;
}

void	ft_init_3(t_vault *vault)
{
	vault->ray.hit = 0;
	vault->ray.perpWallDist = 0;
	vault->ray.cameraX = 2 * vault->ray.x / (double)vault->Rx - 1;
	vault->ray.rayDirX = vault->ray.dirX + vault->ray.planX
		* vault->ray.cameraX;
	vault->ray.rayDirY = vault->ray.dirY + vault->ray.planY
		* vault->ray.cameraX;
	vault->ray.mapX = (int)vault->ray.posX;
	vault->ray.mapY = (int)vault->ray.posY;
	vault->ray.movespeed = 0.1;
	vault->ray.rotspeed = 0.033 * 1.8;
	vault->ray.deltaDistX = fabs(1 / vault->ray.rayDirX);
	vault->ray.deltaDistY = fabs(1 / vault->ray.rayDirY);
}

void	ft_init_texture(t_vault *vault)
{
	if (vault->ray.side == 0 && vault->ray.rayDirX < 0)
		vault->t.texdir = 0;
	if (vault->ray.side == 0 && vault->ray.rayDirX >= 0)
		vault->t.texdir = 1;
	if (vault->ray.side == 1 && vault->ray.rayDirY < 0)
		vault->t.texdir = 2;
	if (vault->ray.side == 1 && vault->ray.rayDirY >= 0)
		vault->t.texdir = 3;
	if (vault->ray.side == 0)
		vault->t.wallX = vault->ray.posY + vault->ray.perpWallDist \
						* vault->ray.rayDirY;
	else
		vault->t.wallX = vault->ray.posX + vault->ray.perpWallDist \
						* vault->ray.rayDirX;
	vault->t.wallX -= floor((vault->t.wallX));
}
