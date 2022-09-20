/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adel-cor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 14:37:04 by adel-cor          #+#    #+#             */
/*   Updated: 2022/09/20 19:50:45 by adel-cor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubed.h"

int	ft_brush(t_vault *vault)
{
	int	j;
	int	i;

	j = -1;
	i = vault->ray.drawEnd;
	while (++j < vault->ray.drawStart)
		vault->data.addr[j * vault->data.line_length / 4
			+ vault->ray.x] = vault->ceiling;
	if (j <= vault->ray.drawEnd)
		ft_draw_text(vault, vault->ray.x, j);
	j = i;
	while (++j < vault->Ry)
		vault->data.addr[j * vault->data.line_length / 4
			+ vault->ray.x] = vault->floor;
	return (0);
}

void	ft_draw_text(t_vault *vault, int x, int y)
{
	y = vault->ray.drawStart - 1;
	ft_init_texture(vault);
	vault->t.step = 1.0 * vault->texture[0].height / vault->ray.lineHeight;
	vault->t.texX = (int)(vault->t.wallX
			* (double)vault->texture[vault->t.texdir].width);
	if (vault->ray.side == 0 && vault->ray.rayDirX > 0)
		vault->t.texX = vault->texture[vault->t.texdir].width
			- vault->t.texX - 1;
	if (vault->ray.side == 1 && vault->ray.rayDirY < 0)
		vault->t.texX = vault->texture[vault->t.texdir].width
			- vault->t.texX - 1;
	vault->t.texPos = (vault->ray.drawStart - vault->Ry / 2
			+ vault->ray.lineHeight / 2) * vault->t.step;
	while (++y <= vault->ray.drawEnd)
	{
		vault->t.texY = (int)vault->t.texPos
			& (vault->texture[vault->t.texdir].height - 1);
		vault->t.texPos += vault->t.step;
		if (y < vault->Ry && x < vault->Rx)
			vault->data.addr[y * vault->data.line_length / 4 + x]
				= vault->texture[vault->t.texdir].addr[vault->t.texY
				* vault->texture[vault->t.texdir].line_length
				/ 4 + vault->t.texX];
	}
}
