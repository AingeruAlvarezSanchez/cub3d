/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_resolution_init.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adel-cor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 13:00:50 by adel-cor          #+#    #+#             */
/*   Updated: 2022/09/19 16:07:23 by adel-cor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubed.h"

void	ft_swap(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void    ft_color_res(t_vault *vault)
{
        vault->Rx = 2000;
        vault->Ry = 1000;
        vault->F = 16842496;
        vault->C = 25198720;
}

void    ft_init(t_vault *vault)
{
    vault->NO = NULL;
    vault->SO = NULL;
    vault->WE = NULL;
    vault->EA = NULL;
    vault->F = 0;
    vault->C = 0;
    vault->Rx = 0;
    vault->Ry = 0;
//    vault->map = NULL;
//    vault->init_x = 3;
//    vault->init_y = 16;
//    vault->compass = 'E';
    vault->data.img = NULL;
    vault->texture[0].img = NULL;
    vault->texture[1].img = NULL;
    vault->texture[2].img = NULL;
    vault->texture[3].img = NULL;
    vault->data.mlx_win = NULL;
//    vault->map = NULL;
	ft_swap(&vault->init_x, &vault->init_y);

}
