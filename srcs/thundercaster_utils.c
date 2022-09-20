/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thundercaster_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adel-cor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 14:49:08 by adel-cor          #+#    #+#             */
/*   Updated: 2022/09/20 18:16:33 by adel-cor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubed.h"

void	ft_sidedist(t_vault *vault)
{
	if (vault->ray.raydir_x < 0)
	{
		vault->ray.step_x = -1;
		vault->ray.sidedist_x = (vault->ray.pos_x - vault->ray.map_x)
			* vault->ray.deltadist_x;
	}
	else
	{
		vault->ray.step_x = 1;
		vault->ray.sidedist_x = (vault->ray.map_x + 1.0 - vault->ray.pos_x)
			* vault->ray.deltadist_x;
	}
	if (vault->ray.raydir_y < 0)
	{
		vault->ray.step_y = -1;
		vault->ray.sidedist_y = (vault->ray.pos_y - vault->ray.map_y)
			* vault->ray.deltadist_y;
	}
	else
	{
		vault->ray.step_y = 1;
		vault->ray.sidedist_y = (vault->ray.map_y + 1.0 - vault->ray.pos_y)
			* vault->ray.deltadist_y;
	}
	ft_ray_inc(vault);
}

void	ft_ray_inc(t_vault *vault)
{
	while (vault->ray.hit == 0)
	{
		if (vault->ray.sidedist_x < vault->ray.sidedist_y)
		{
			vault->ray.sidedist_x += vault->ray.deltadist_x;
			vault->ray.map_x += vault->ray.step_x;
			vault->ray.side = 0;
		}
		else
		{
			vault->ray.sidedist_y += vault->ray.deltadist_y;
			vault->ray.map_y += vault->ray.step_y;
			vault->ray.side = 1;
		}
		if (vault->map[vault->ray.map_x][vault->ray.map_y] == '1')
			vault->ray.hit = 1;
	}
	ft_drawstarte(vault);
}

void	ft_drawstarte(t_vault *vault)
{
	if (vault->ray.side == 0)
		vault->ray.perpwalldist = ((double)vault->ray.map_x
				- vault->ray.pos_x + (1 - (double)vault->ray.step_x)
				/ 2) / vault->ray.raydir_x;
	else
		vault->ray.perpwalldist = ((double)vault->ray.map_y
				-vault->ray.pos_y + (1 - (double)vault->ray.step_y)
				/ 2) / vault->ray.raydir_y;
	vault->ray.lineheight = (int)(vault->ry / vault->ray.perpwalldist);
	vault->ray.drawstart = -vault->ray.lineheight / 2 + vault->ry / 2;
	if (vault->ray.drawstart < 0)
		vault->ray.drawstart = 0;
	vault->ray.drawend = vault->ray.lineheight / 2 + vault->ry / 2;
	if (vault->ray.drawend >= vault->ry || vault->ray.drawend < 0)
		vault->ray.drawend = vault->ry - 1;
}

void	ft_magic(t_vault *vault)
{
	void	*tmp;

	tmp = vault->data.img;
	vault->data.img = vault->data.img2;
	vault->data.img2 = tmp;
	tmp = vault->data.addr;
	vault->data.addr = vault->data.addr2;
	vault->data.addr2 = tmp;
}
