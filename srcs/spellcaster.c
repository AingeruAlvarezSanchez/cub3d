/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spellcaster.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adel-cor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 14:42:18 by adel-cor          #+#    #+#             */
/*   Updated: 2022/09/20 19:59:43 by adel-cor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubed.h"

int	ft_start(t_vault *vault)
{
	ft_init(vault);
	ft_color_res(vault);
	if (ft_draw(vault))
		return (1);
	return (0);
}
