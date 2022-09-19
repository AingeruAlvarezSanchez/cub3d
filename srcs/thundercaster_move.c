/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thundercaster_move.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adel-cor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 14:47:03 by adel-cor          #+#    #+#             */
/*   Updated: 2022/09/19 16:36:29 by adel-cor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubed.h"

void    ft_forward_back(t_vault *vault)
{
/*    char        *worldMap[24] = { "111111111111111111111111",
                              "100000000000000000000001",
                              "100000000000000000000001",
                              "100000000000000000000001",
                              "100000000000000000000001",
                              "100000000000000000000001",
                              "100000000000000000000001",
                              "100000000000000000000001",
                              "100000000110011000000001",
                              "100000000100001000000001",
                              "100000000100001000000001",
                              "100000000100001000000001",
                              "100000000100001000000001",
                              "100000000100001000000001",
                              "100000000100001000000001",
                              "100000000000000000000001",
                              "100000000000000000000001",
                              "100000000000000000000001",
                              "100000000000000000000001",
                              "100000000000000000000001",
                              "100000000000000000000001",
                              "100000000000000000000001",
                              "100000000000000000000001",
                              "111111111111111111111111",
};*/
    if (vault->data.forward == 1)
    {
        if (vault->map[(int)(vault->ray.posX + vault->ray.dirX * vault->ray.movespeed)][(int)vault->ray.posY] != '1')
            vault->ray.posX += vault->ray.dirX * vault->ray.movespeed;
        if (vault->map[(int)(vault->ray.posX)][(int)(vault->ray.posY + vault->ray.dirY * vault->ray.movespeed)] != '1')
            vault->ray.posY += vault->ray.dirY * vault->ray.movespeed;
    }
    if (vault->data.back == 1)
    {
        if (vault->map[(int)(vault->ray.posX - vault->ray.dirX * vault->ray.movespeed)][(int)(vault->ray.posY)] != '1')
            vault->ray.posX -= vault->ray.dirX * vault->ray.movespeed;
        if (vault->map[(int)(vault->ray.posX)][(int)(vault->ray.posY - vault->ray.dirY * vault->ray.movespeed)] != '1')
            vault->ray.posY -= vault->ray.dirY * vault->ray.movespeed;
    }
}

void    ft_left_right(t_vault *vault)
{
  /*  char        *worldMap[24] = { "111111111111111111111111",
                              "100000000000000000000001",
                              "100000000000000000000001",
                              "100000000000000000000001",
                              "100000000000000000000001",
                              "100000000000000000000001",
                              "100000000000000000000001",
                              "100000000000000000000001",
                              "100000000110011000000001",
                              "100000000100001000000001",
                              "100000000100001000000001",
                              "100000000100001000000001",
                              "100000000100001000000001",
                              "100000000100001000000001",
                              "100000000100001000000001",
                              "100000000000000000000001",
                              "100000000000000000000001",
                              "100000000000000000000001",
                              "100000000000000000000001",
                              "100000000000000000000001",
                              "100000000000000000000001",
                              "100000000000000000000001",
                              "100000000000000000000001",
                              "111111111111111111111111",
};*/
    if (vault->data.right == 1)
    {
        if (vault->map[(int)(vault->ray.posX + vault->ray.dirY *
                    vault->ray.movespeed)][(int)vault->ray.posY] != '1')
            vault->ray.posX += vault->ray.dirY * vault->ray.movespeed;
        if (vault->map[(int)vault->ray.posX][(int)(vault->ray.posY - vault->ray.dirX *
                    vault->ray.movespeed)] != '1')
            vault->ray.posY -=  vault->ray.dirX * vault->ray.movespeed;
    }
    if (vault->data.left == 1)
    {
        if (vault->map[(int)(vault->ray.posX - vault->ray.dirY *
                    vault->ray.movespeed)][(int)vault->ray.posY] != '1')
            vault->ray.posX -= vault->ray.dirY * vault->ray.movespeed;
        if (vault->map[(int)vault->ray.posX][(int)(vault->ray.posY + vault->ray.dirX *
                    vault->ray.movespeed)] != '1')
            vault->ray.posY +=  vault->ray.dirX * vault->ray.movespeed;
    }
}

void    ft_rotate_right_left(t_vault *vault)
{
    if (vault->data.rotate_right == 1)
    {
        double oldDirX = vault->ray.dirX;
        vault->ray.dirX = vault->ray.dirX * cos(-vault->ray.rotspeed / 2) - vault->ray.dirY * sin(-vault->ray.rotspeed / 2);
        vault->ray.dirY = oldDirX * sin(-vault->ray.rotspeed / 2) + vault->ray.dirY * cos(-vault->ray.rotspeed / 2);
        double oldPlanX = vault->ray.planX;
        vault->ray.planX = vault->ray.planX * cos(-vault->ray.rotspeed / 2) - vault->ray.planY * sin(-vault->ray.rotspeed / 2);
        vault->ray.planY = oldPlanX * sin(-vault->ray.rotspeed / 2) + vault->ray.planY * cos(-vault->ray.rotspeed / 2);
    }
    if (vault->data.rotate_left == 1)
    {
        double oldDirX = vault->ray.dirX;
        vault->ray.dirX = vault->ray.dirX * cos(vault->ray.rotspeed / 2) - vault->ray.dirY * sin(vault->ray.rotspeed / 2);
        vault->ray.dirY = oldDirX * sin(vault->ray.rotspeed / 2) + vault->ray.dirY * cos(vault->ray.rotspeed / 2);
        double oldPlaneX = vault->ray.planX;
        vault->ray.planX = vault->ray.planX * cos(vault->ray.rotspeed / 2) - vault->ray.planY * sin(vault->ray.rotspeed / 2);
        vault->ray.planY = oldPlaneX * sin(vault->ray.rotspeed / 2) + vault->ray.planY * cos(vault->ray.rotspeed / 2);
    }
}
