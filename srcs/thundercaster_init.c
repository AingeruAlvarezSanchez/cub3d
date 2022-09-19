/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thundercaster_init.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adel-cor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 14:44:48 by adel-cor          #+#    #+#             */
/*   Updated: 2022/09/19 13:14:42 by adel-cor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubed.h"

void    ft_init_2(t_vault *vault)
{
    vault->data.forward = 0;
    vault->data.back = 0;
    vault->data.left = 0;
    vault->data.right = 0;
    vault->data.rotate_right = 0;
    vault->data.rotate_left = 0;
    vault->ray.posX = (double)vault->init_x;
    vault->ray.posY = (double)vault->init_y;
    vault->ray.dirX = 0;
    vault->ray.dirY = 0;
    vault->ray.planX = 0;
    vault->ray.planY = 0;
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

void    ft_init_3(t_vault *vault)
{
    vault->ray.hit = 0;
    vault->ray.perpWallDist = 0;
    vault->ray.cameraX = 2 * vault->ray.x / (double)vault->Rx - 1;
    vault->ray.rayDirX = vault->ray.dirX + vault->ray.planX * \
                        vault->ray.cameraX; 
    vault->ray.rayDirY = vault->ray.dirY + vault->ray.planY * \
                        vault->ray.cameraX;
    vault->ray.mapX = (int)vault->ray.posX;
    vault->ray.mapY = (int)vault->ray.posY;
    vault->ray.movespeed = 0.1;
    vault->ray.rotspeed = 0.033 * 1.8;
//    vault->ray.deltaDistX = (vault->ray.rayDirY == 0) ? 0 : \
  //          ((vault->ray.rayDirX == 0) ? 1 : sqrt(1 + (vault->ray.rayDirY * \
    //        vault->ray.rayDirY) / (vault->ray.rayDirX * vault->ray.rayDirX)));
//    vault->ray.deltaDistY = (vault->ray.rayDirX == 0) ? 0 : \
  //          ((vault->ray.rayDirY == 0) ? 1 : sqrt(1 + (vault->ray.rayDirX * \
    //        vault->ray.rayDirX) / (vault->ray.rayDirY * vault->ray.rayDirY)));
	vault->ray.deltaDistX =   fabs(1 / vault->ray.rayDirX);
	vault->ray.deltaDistY =   fabs(1 / vault->ray.rayDirY);
}

void    ft_init_texture(t_vault *vault)
{
    if (vault->ray.side == 0 && vault->ray.rayDirX < 0) //NO
        vault->t.texdir = 0;
    if (vault->ray.side == 0 && vault->ray.rayDirX >= 0) // S
        vault->t.texdir = 1;
    if (vault->ray.side == 1 && vault->ray.rayDirY < 0) // WE
        vault->t.texdir = 2;
    if (vault->ray.side == 1 && vault->ray.rayDirY >= 0) // EA
        vault->t.texdir = 3;
    if (vault->ray.side == 0)
        vault->t.wallX = vault->ray.posY + vault->ray.perpWallDist \
                        * vault->ray.rayDirY;
    else
        vault->t.wallX = vault->ray.posX + vault->ray.perpWallDist \
                        * vault->ray.rayDirX;
    vault->t.wallX -= floor((vault->t.wallX));
}
