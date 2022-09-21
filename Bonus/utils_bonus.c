/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalvarez <aalvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 02:48:49 by aalvarez          #+#    #+#             */
/*   Updated: 2022/09/20 16:05:19 by adel-cor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubed.h"
#include <stdlib.h>

void	ft_freedata(t_vault *vault)
{
	free(vault->north_texture);
	free(vault->south_texture);
	free(vault->west_texture);
	free(vault->east_texture);
	ft_doublefree(vault->map);
}

void	ft_init_structs(t_vault *vault, t_color *color)
{
	vault->north_texture = NULL;
	vault->south_texture = NULL;
	vault->west_texture = NULL;
	vault->east_texture = NULL;
	vault->map = NULL;
	vault->floor = -1;
	vault->ceiling = -1;
	color->ceiling_integer = -1;
	color->floor_integer = -1;
	vault->data.forward = 0;
	vault->data.back = 0;
	vault->data.left = 0;
	vault->data.right = 0;
	vault->data.rotate_right = 0;
	vault->data.rotate_left = 0;
	vault->ray.dir_x = 0;
	vault->ray.dir_y = 0;
	vault->ray.plan_x = 0;
	vault->ray.plan_y = 0;
}

void	ft_trim_data(t_vault *vault)
{
	char	*tmp;

	tmp = ft_strdup(vault->north_texture);
	free(vault->north_texture);
	vault->north_texture = ft_strtrim(tmp, " \n");
	free(tmp);
	tmp = ft_strdup(vault->south_texture);
	free(vault->south_texture);
	vault->south_texture = ft_strtrim(tmp, " \n");
	free(tmp);
	tmp = ft_strdup(vault->west_texture);
	free(vault->west_texture);
	vault->west_texture = ft_strtrim(tmp, " \n");
	free(tmp);
	tmp = ft_strdup(vault->east_texture);
	free(vault->east_texture);
	vault->east_texture = ft_strtrim(tmp, " \n");
	free(tmp);
}
