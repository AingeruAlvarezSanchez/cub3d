/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spellcaster.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adel-cor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 14:42:18 by adel-cor          #+#    #+#             */
/*   Updated: 2022/09/19 13:49:13 by adel-cor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubed.h"

int     ft_start(t_vault *vault)
{
	int	i;
	char  *tmp;
	i = -1;
	while(vault->map[++i])
	{
		tmp = ft_strtrim(vault->map[i], "\n");
		free(vault->map[i]);
		vault->map[i] = ft_strdup(tmp);
		free(tmp);
	}
    ft_init(vault);
    ft_color_res(vault);
    ft_draw(vault);
    return (0);
}

/*
int     main(void)
{
    t_vault vault;
    ft_start(&vault);
    return(0);
}*/

