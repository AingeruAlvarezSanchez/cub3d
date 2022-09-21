/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thundercaster_move.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adel-cor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 14:47:03 by adel-cor          #+#    #+#             */
/*   Updated: 2022/09/21 11:23:18 by adel-cor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubed.h"

void	ft_forward_back(t_vault *vault)
{
	if (vault->data.forward == 1)
	{
		if (vault->map[(int)(vault->ray.pos_x + vault->ray.dir_x
				* vault->ray.movespeed)][(int)vault->ray.pos_y] != '1')
			vault->ray.pos_x += vault->ray.dir_x * vault->ray.movespeed;
		if (vault->map[(int)(vault->ray.pos_x)][(int)(vault->ray.pos_y
					+ vault->ray.dir_y * vault->ray.movespeed)] != '1')
			vault->ray.pos_y += vault->ray.dir_y * vault->ray.movespeed;
	}
	if (vault->data.back == 1)
	{
		if (vault->map[(int)(vault->ray.pos_x - vault->ray.dir_x
				* vault->ray.movespeed)][(int)(vault->ray.pos_y)] != '1')
			vault->ray.pos_x -= vault->ray.dir_x * vault->ray.movespeed;
		if (vault->map[(int)(vault->ray.pos_x)][(int)(vault->ray.pos_y
				- vault->ray.dir_y * vault->ray.movespeed)] != '1')
			vault->ray.pos_y -= vault->ray.dir_y * vault->ray.movespeed;
	}
}

void	ft_left_right(t_vault *vault)
{
	if (vault->data.right == 1)
	{
		if (vault->map[(int)(vault->ray.pos_x + vault->ray.dir_y
				* vault->ray.movespeed)][(int)vault->ray.pos_y] != '1')
			vault->ray.pos_x += vault->ray.dir_y * vault->ray.movespeed;
		if (vault->map[(int)vault->ray.pos_x][(int)(vault->ray.pos_y
			- vault->ray.dir_x * vault->ray.movespeed)] != '1')
			vault->ray.pos_y -= vault->ray.dir_x * vault->ray.movespeed;
	}
	if (vault->data.left == 1)
	{
		if (vault->map[(int)(vault->ray.pos_x - vault->ray.dir_y
				* vault->ray.movespeed)][(int)vault->ray.pos_y] != '1')
			vault->ray.pos_x -= vault->ray.dir_y * vault->ray.movespeed;
		if (vault->map[(int)vault->ray.pos_x][(int)(vault->ray.pos_y
			+ vault->ray.dir_x * vault->ray.movespeed)] != '1')
			vault->ray.pos_y += vault->ray.dir_x * vault->ray.movespeed;
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
	vault->ray.olddir_x = vault->ray.dir_x;
	vault->ray.dir_x = vault->ray.dir_x * cos(-vault->ray.rotspeed / 2)
		- vault->ray.dir_y * sin(-vault->ray.rotspeed / 2);
	vault->ray.dir_y = vault->ray.olddir_x * sin(-vault->ray.rotspeed / 2)
		+ vault->ray.dir_y * cos(-vault->ray.rotspeed / 2);
	vault->ray.oldplane_x = vault->ray.plan_x;
	vault->ray.plan_x = vault->ray.plan_x * cos(-vault->ray.rotspeed / 2)
		- vault->ray.plan_y * sin(-vault->ray.rotspeed / 2);
	vault->ray.plan_y = vault->ray.oldplane_x * sin(-vault->ray.rotspeed / 2)
		+ vault->ray.plan_y * cos(-vault->ray.rotspeed / 2);
}

void	ft_r_left(t_vault *vault)
{
	vault->ray.olddir_x = vault->ray.dir_x;
	vault->ray.dir_x = vault->ray.dir_x * cos(vault->ray.rotspeed / 2)
		- vault->ray.dir_y * sin(vault->ray.rotspeed / 2);
	vault->ray.dir_y = vault->ray.olddir_x * sin(vault->ray.rotspeed / 2)
		+ vault->ray.dir_y * cos(vault->ray.rotspeed / 2);
	vault->ray.oldplane_x = vault->ray.plan_x;
	vault->ray.plan_x = vault->ray.plan_x * cos(vault->ray.rotspeed / 2)
		- vault->ray.plan_y * sin(vault->ray.rotspeed / 2);
	vault->ray.plan_y = vault->ray.oldplane_x * sin(vault->ray.rotspeed / 2)
		+ vault->ray.plan_y * cos(vault->ray.rotspeed / 2);
}
