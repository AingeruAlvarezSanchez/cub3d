/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_initial_errors.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalvarez <aalvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 01:05:27 by aalvarez          #+#    #+#             */
/*   Updated: 2022/09/07 00:54:02 by aalvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubed.h"
#include <stdlib.h>

static void	ft_create_trgb(t_color *color)
{
	//TODO all in data or in color??
}

static int	ft_check_rgb_value(t_color *color, char *line, int color_len)
{
	static int	color_start;
	static int	rgb_checker;
	char		*tmp;

	if (!line[color_start + color_len + 1])
	{
		tmp = ft_substr(line, color_start, color_len + 1);
		color_start = -1;
	}
	else
		tmp = ft_substr(line, color_start, color_len);
	if (ft_atoi(tmp) > 255 || ft_atoi(tmp) < 0)
		return (free(tmp), 1);
	if (rgb_checker == 0)
		color->color_r = ft_atoi(tmp);
	else if (rgb_checker == 1)
		color->color_g = ft_atoi(tmp);
	else if (rgb_checker == 2)
	{
		color->color_b = ft_atoi(tmp);
		rgb_checker = -1;
		ft_create_trgb(color);
	}
	return (color_start += color_len + 1, rgb_checker++, free(tmp), 0);
}

static int	ft_check_color_values(t_color *color, char *line)
{
	int	i;
	int	color_len;
	int	color_n;

	i = -1;
	color_n = 0;
	color_len = -1;
	while (line[++i])
	{
		color_len++;
		if (!ft_isdigit(line[i]) && line[i] != ',')
			return (free(line), 1);
		if (line[i] == ',' || !line[i + 1])
		{
			color_n++;
			if (color_n > 3 || color_len > 3 || (!line[i + 1] && color_n < 3))
				return (free(line), 1);
			if (ft_check_rgb_value(color, line, color_len))
				return (free(line), 1);
			color_len = -1;
		}
	}
	return (free(line), 0);
}

int	ft_invalidcolor_line(t_color *color, char **file_content)
{
	char	*tmp;
	int		i;

	i = -1;
	while (file_content[++i])
	{
		tmp = ft_strtrim(file_content[i], " \n");
		if (*tmp == 'F')
		{
			if (color->ceiling_integer != -1)
				return (free(tmp), 1);
			if (ft_check_color_values(color, ft_strtrim(tmp, "F ")))
				return (free(tmp), 1);
		}
		if (*tmp == 'C')
		{
			if (color->floor_integer != -1)
				return (free(tmp), 1);
			if (ft_check_color_values(color, ft_strtrim(tmp, "C ")))
				return (free(tmp), 1);
		}
		free(tmp);
	}
	return (0);
}
