/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_resolution_init.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adel-cor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 13:00:50 by adel-cor          #+#    #+#             */
/*   Updated: 2022/09/20 19:46:11 by adel-cor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubed.h"

void	ft_swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void	ft_color_res(t_vault *vault)
{
	vault->Rx = 1920;
	vault->Ry = 1080;
}

void	ft_init(t_vault *vault)
{
	vault->Rx = 0;
	vault->Ry = 0;
	vault->data.img = NULL;
	vault->texture[0].img = NULL;
	vault->texture[1].img = NULL;
	vault->texture[2].img = NULL;
	vault->texture[3].img = NULL;
	vault->data.mlx_win = NULL;
	ft_swap(&vault->init_x, &vault->init_y);
}
