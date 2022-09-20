/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thundercaster_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adel-cor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 14:49:08 by adel-cor          #+#    #+#             */
/*   Updated: 2022/09/20 13:20:33 by adel-cor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubed.h"

void    ft_sideDist(t_vault *vault) 
{
        if (vault->ray.rayDirX < 0)
        {
            vault->ray.stepX = -1;
            vault->ray.sideDistX = (vault->ray.posX - vault->ray.mapX) \
                                   * vault->ray.deltaDistX;
        }
        else
        {
            vault->ray.stepX = 1;
            vault->ray.sideDistX = (vault->ray.mapX + 1.0 - vault->ray.posX) \
                                   * vault->ray.deltaDistX;
        }
        if (vault->ray.rayDirY < 0)
        {
            vault->ray.stepY = -1;
            vault->ray.sideDistY = (vault->ray.posY - vault->ray.mapY) \
                                   * vault->ray.deltaDistY;
        }
        else
        {
            vault->ray.stepY = 1;
            vault->ray.sideDistY = (vault->ray.mapY + 1.0 - vault->ray.posY) \
                                   * vault->ray.deltaDistY;
        }
        ft_ray_inc(vault);
}

void    ft_ray_inc(t_vault *vault)
{
    while (vault->ray.hit == 0)
    {
        if (vault->ray.sideDistX < vault->ray.sideDistY)
        {
            vault->ray.sideDistX += vault->ray.deltaDistX;
            vault->ray.mapX += vault->ray.stepX;
            vault->ray.side = 0;
        }
        else
        {
            vault->ray.sideDistY += vault->ray.deltaDistY;
            vault->ray.mapY += vault->ray.stepY;
            vault->ray.side = 1;
        }
        if (vault->map[vault->ray.mapX][vault->ray.mapY] == '1') 
            vault->ray.hit = 1;
    }

        ft_drawStartE(vault);
}

void    ft_drawStartE(t_vault *vault)
{

        if (vault->ray.side == 0)
            vault->ray.perpWallDist = ((double)vault->ray.mapX - \
                    vault->ray.posX + (1 - (double)vault->ray.stepX) / 2) / vault->ray.rayDirX;
        else
            vault->ray.perpWallDist = ((double)vault->ray.mapY - \
                    vault->ray.posY + (1 - (double)vault->ray.stepY) / 2) / vault->ray.rayDirY;

        vault->ray.lineHeight = (int)(vault->Ry / vault->ray.perpWallDist);
        vault->ray.drawStart = - vault->ray.lineHeight / 2 + vault->Ry / 2;
        if (vault->ray.drawStart < 0)
            vault->ray.drawStart = 0;
        vault->ray.drawEnd = vault->ray.lineHeight / 2 + vault->Ry / 2;
        if (vault->ray.drawEnd >= vault->Ry || vault->ray.drawEnd < 0)
            vault->ray.drawEnd = vault->Ry - 1;
}

void    ft_magic(t_vault *vault)
{
    void *tmp;

    tmp = vault->data.img;
    vault->data.img = vault->data.img2;
    vault->data.img2 = tmp;
    tmp = vault->data.addr;
    vault->data.addr = vault->data.addr2;
    vault->data.addr2 = tmp;
}
