/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adel-cor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 14:40:54 by adel-cor          #+#    #+#             */
/*   Updated: 2022/09/20 19:55:49 by adel-cor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubed.h"

int	ft_key_press(int keycode, t_vault *vault)
{
	if (keycode == FORWARD_W_Z)
		vault->data.forward = 1;
	else if (keycode == BACK_S_S)
		vault->data.back = 1;
	else if (keycode == LEFT_A_Q)
		vault->data.left = 1;
	else if (keycode == RIGHT_D_D)
		vault->data.right = 1;
	else if (keycode == ROTATE_LEFT)
		vault->data.rotate_left = 1;
	else if (keycode == ROTATE_RIGHT)
		vault->data.rotate_right = 1;
	else if (keycode == 53)
		ft_exit(vault);
	return (1);
}

int	ft_key_release(int keycode, t_vault *vault)
{
	if (keycode == FORWARD_W_Z)
		vault->data.forward = 0;
	else if (keycode == BACK_S_S)
		vault->data.back = 0;
	else if (keycode == LEFT_A_Q)
		vault->data.left = 0;
	else if (keycode == RIGHT_D_D)
		vault->data.right = 0;
	else if (keycode == ROTATE_LEFT)
		vault->data.rotate_left = 0;
	else if (keycode == ROTATE_RIGHT)
		vault->data.rotate_right = 0;
	return (1);
}
