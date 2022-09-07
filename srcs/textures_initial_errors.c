/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures_initial_errors.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalvarez <aalvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 20:21:36 by aalvarez          #+#    #+#             */
/*   Updated: 2022/09/01 20:24:25 by aalvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubed.h"
#include <stdlib.h>

static int	ft_isvalid_route(char *line)
{
	int		i;
	char	*tmp;

	i = 1;
	tmp = ft_strtrim(line, " \n");
	while (tmp[++i])
	{
		if (ft_isprint(tmp[i]) && tmp[i] != ' ')
		{
			while (tmp[i])
			{
				if (tmp[i] == ' ')
					return (free(tmp), 1);
				i++;
			}
			break ;
		}
	}
	return (free(tmp), 0);
}

int	ft_fill_data(t_data *data, char *line)
{
	if (!ft_strncmp(line, "NO", 2))
	{
		if (data->north_texture || ft_isvalid_route(line))
			return (free(line), 1);
		data->north_texture = ft_substr(line, 2, (ft_strlen(line) - 2));
	}
	if (!ft_strncmp(line, "SO", 2))
	{
		if (data->south_texture || ft_isvalid_route(line))
			return (free(line), 1);
		data->south_texture = ft_substr(line, 2, (ft_strlen(line) - 2));
	}
	if (!ft_strncmp(line, "WE", 2))
	{
		if (data->west_texture || ft_isvalid_route(line))
			return (free(line), 1);
		data->west_texture = ft_substr(line, 2, (ft_strlen(line) - 2));
	}
	if (!ft_strncmp(line, "EA", 2))
	{
		if (data->east_texture || ft_isvalid_route(line))
			return (free(line), 1);
		data->east_texture = ft_substr(line, 2, (ft_strlen(line) - 2));
	}
	return (free(line), 0);
}
