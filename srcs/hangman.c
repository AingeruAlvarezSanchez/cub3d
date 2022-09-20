/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hangman.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adel-cor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 14:38:40 by adel-cor          #+#    #+#             */
/*   Updated: 2022/09/20 19:53:55 by adel-cor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubed.h"

int	ft_exit(t_vault *vault)
{
	if (vault->data.img)
		mlx_destroy_image(vault->data.mlx_ptr, vault->data.img);
	if (vault->texture[0].img)
		mlx_destroy_image(vault->data.mlx_ptr, vault->texture[0].img);
	if (vault->texture[1].img)
		mlx_destroy_image(vault->data.mlx_ptr, vault->texture[1].img);
	if (vault->texture[2].img)
		mlx_destroy_image(vault->data.mlx_ptr, vault->texture[2].img);
	if (vault->texture[3].img)
		mlx_destroy_image(vault->data.mlx_ptr, vault->texture[3].img);
	if (vault->data.mlx_win)
		mlx_destroy_window(vault->data.mlx_ptr, vault->data.mlx_win);
	exit(0);
}
