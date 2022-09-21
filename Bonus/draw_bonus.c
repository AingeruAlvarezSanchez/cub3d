/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adel-cor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 14:37:04 by adel-cor          #+#    #+#             */
/*   Updated: 2022/09/21 11:25:15 by adel-cor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubed.h"

int	ft_brush(t_vault *vault)
{
	int	j;
	int	i;

	j = -1;
	i = vault->ray.drawend;
	while (++j < vault->ray.drawstart)
		vault->data.addr[j * vault->data.line_length / 4
			+ vault->ray.x] = vault->ceiling;
	if (j <= vault->ray.drawend)
		ft_draw_text(vault, vault->ray.x, j);
	j = i;
	while (++j < vault->ry)
		vault->data.addr[j * vault->data.line_length / 4
			+ vault->ray.x] = vault->floor;
	return (0);
}

void	ft_draw_text(t_vault *vault, int x, int y)
{
	y = vault->ray.drawstart - 1;
	ft_init_texture(vault);
	vault->t.step = 1.0 * vault->texture[0].height / vault->ray.lineheight;
	vault->t.tex_x = (int)(vault->t.wallx
			* (double)vault->texture[vault->t.texdir].width);
	if (vault->ray.side == 0 && vault->ray.raydir_x > 0)
		vault->t.tex_x = vault->texture[vault->t.texdir].width
			- vault->t.tex_x - 1;
	if (vault->ray.side == 1 && vault->ray.raydir_y < 0)
		vault->t.tex_x = vault->texture[vault->t.texdir].width
			- vault->t.tex_x - 1;
	vault->t.tex_pos = (vault->ray.drawstart - vault->ry / 2
			+ vault->ray.lineheight / 2) * vault->t.step;
	while (++y <= vault->ray.drawend)
	{
		vault->t.tex_y = (int)vault->t.tex_pos
			& (vault->texture[vault->t.texdir].height - 1);
		vault->t.tex_pos += vault->t.step;
		if (y < vault->ry && x < vault->rx)
			vault->data.addr[y * vault->data.line_length / 4 + x]
				= vault->texture[vault->t.texdir].addr[vault->t.tex_y
				* vault->texture[vault->t.texdir].line_length
				/ 4 + vault->t.tex_x];
	}
}
