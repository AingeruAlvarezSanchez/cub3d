/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thundercaster_move.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adel-cor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 14:47:03 by adel-cor          #+#    #+#             */
/*   Updated: 2022/09/20 18:01:05 by adel-cor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubed.h"

void	ft_forward_back(t_vault *vault)
{
	if (vault->data.forward == 1)
	{
		if (vault->map[(int)(vault->ray.posX + vault->ray.dirX
				* vault->ray.movespeed)][(int)vault->ray.posY] != '1')
			vault->ray.posX += vault->ray.dirX * vault->ray.movespeed;
		if (vault->map[(int)(vault->ray.posX)][(int)(vault->ray.posY
					+ vault->ray.dirY * vault->ray.movespeed)] != '1')
			vault->ray.posY += vault->ray.dirY * vault->ray.movespeed;
	}
	if (vault->data.back == 1)
	{
		if (vault->map[(int)(vault->ray.posX - vault->ray.dirX
				* vault->ray.movespeed)][(int)(vault->ray.posY)] != '1')
			vault->ray.posX -= vault->ray.dirX * vault->ray.movespeed;
		if (vault->map[(int)(vault->ray.posX)][(int)(vault->ray.posY
				- vault->ray.dirY * vault->ray.movespeed)] != '1')
			vault->ray.posY -= vault->ray.dirY * vault->ray.movespeed;
	}
}

void	ft_left_right(t_vault *vault)
{
	if (vault->data.right == 1)
	{
		if (vault->map[(int)(vault->ray.posX + vault->ray.dirY
				* vault->ray.movespeed)][(int)vault->ray.posY] != '1')
			vault->ray.posX += vault->ray.dirY * vault->ray.movespeed;
		if (vault->map[(int)vault->ray.posX][(int)(vault->ray.posY
			- vault->ray.dirX * vault->ray.movespeed)] != '1')
			vault->ray.posY -= vault->ray.dirX * vault->ray.movespeed;
	}
	if (vault->data.left == 1)
	{
		if (vault->map[(int)(vault->ray.posX - vault->ray.dirY
				* vault->ray.movespeed)][(int)vault->ray.posY] != '1')
			vault->ray.posX -= vault->ray.dirY * vault->ray.movespeed;
		if (vault->map[(int)vault->ray.posX][(int)(vault->ray.posY
			+ vault->ray.dirX * vault->ray.movespeed)] != '1')
			vault->ray.posY += vault->ray.dirX * vault->ray.movespeed;
	}
}

void	ft_rotate_right_left(t_vault *vault)
{
	if (vault->data.rotate_right == 1)
		ft_r_right(vault);
	if (vault->data.rotate_left == 1)
		ft_r_left(vault);
}

void	ft_r_right(t_vault *vault)
{
	vault->ray.oldDirX = vault->ray.dirX;
	vault->ray.dirX = vault->ray.dirX * cos(-vault->ray.rotspeed / 2)
		- vault->ray.dirY * sin(-vault->ray.rotspeed / 2);
	vault->ray.dirY = vault->ray.oldDirX * sin(-vault->ray.rotspeed / 2)
		+ vault->ray.dirY * cos(-vault->ray.rotspeed / 2);
	vault->ray.oldPlaneX = vault->ray.planX;
	vault->ray.planX = vault->ray.planX * cos(-vault->ray.rotspeed / 2)
		- vault->ray.planY * sin(-vault->ray.rotspeed / 2);
	vault->ray.planY = vault->ray.oldPlaneX * sin(-vault->ray.rotspeed / 2)
		+ vault->ray.planY * cos(-vault->ray.rotspeed / 2);
}

void	ft_r_left(t_vault *vault)
{
	vault->ray.oldDirX = vault->ray.dirX;
	vault->ray.dirX = vault->ray.dirX * cos(vault->ray.rotspeed / 2)
		- vault->ray.dirY * sin(vault->ray.rotspeed / 2);
	vault->ray.dirY = vault->ray.oldDirX * sin(vault->ray.rotspeed / 2)
		+ vault->ray.dirY * cos(vault->ray.rotspeed / 2);
	vault->ray.oldPlaneX = vault->ray.planX;
	vault->ray.planX = vault->ray.planX * cos(vault->ray.rotspeed / 2)
		- vault->ray.planY * sin(vault->ray.rotspeed / 2);
	vault->ray.planY = vault->ray.oldPlaneX * sin(vault->ray.rotspeed / 2)
		+ vault->ray.planY * cos(vault->ray.rotspeed / 2);
}
