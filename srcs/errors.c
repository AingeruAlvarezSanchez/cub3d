/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalvarez <aalvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 17:45:21 by aalvarez          #+#    #+#             */
/*   Updated: 2022/09/07 00:53:20 by aalvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubed.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>

static int	ft_isvalid_content(const char *line)
{
	char	*tmp;
	int		i;

	tmp = ft_strtrim(line, " \n");
	i = 0;
	if (((!ft_strncmp(tmp, "NO", 2)
				|| !ft_strncmp(tmp, "SO", 2)
				|| !ft_strncmp(tmp, "WE", 2)
				|| !ft_strncmp(tmp, "EA", 2)) && tmp[i + 2] == ' ')
		|| *tmp == 'F' || *tmp == 'C' || *tmp == '1')
		return (free(tmp), 1);
	return (free(tmp), 0);
}

static int	ft_isvalid_line(const char *line)
{
	if (!line)
		return (0);
	while (*line)
	{
		if (ft_isalnum(*line))
		{
			if (ft_isvalid_content(line))
				return (0);
			return (1);
		}
		line++;
	}
	return (0);
}

static int	ft_isvalid_file(t_data *data, t_color *color, char **file_content)
{
	int	i;

	i = -1;
	ft_init_structs(data, color);
	while (file_content[++i])
		if (ft_fill_data(data, file_content[i]))
			return (1);
	if (!data->north_texture || !data->south_texture
		|| !data->west_texture || !data->east_texture)
		return (1);
	if (ft_invalidmap_line(file_content))
		return (1);
	if (ft_invalidcolor_line(color, file_content))
		return (1);
	ft_trim_data(data);
	if (open(data->north_texture, O_RDONLY) < 0
		|| open(data->south_texture, O_RDONLY) < 0
		|| open(data->west_texture, O_RDONLY) < 0
		|| open(data->east_texture, O_RDONLY) < 0)
		return (perror("Error "), 1);
	if (ft_create_map(data, file_content))
		return (1);
	return (0);
}

int	ft_file_errors(t_info *info, t_data *data, t_color *color)
{
	char	**file_content;
	int		i;

	i = -1;
	file_content = (char **)ft_calloc(info->file_size + 2, sizeof(char *));
	if (!file_content)
		return (1);
	while (++i < (info->file_size + 1))
	{
		file_content[i] = ft_get_next_line(info->file_fd);
		if (ft_isvalid_line(file_content[i]))
		{
			file_content[i + 1] = 0;
			ft_doublefree(file_content);
			return (printf("Error : %s\n", strerror(22)));
		}
	}
	file_content[i] = 0;
	if (ft_isvalid_file(data, color, file_content))
		return (ft_freedata(data), ft_doublefree(file_content),
			printf("Error : %s\n", strerror(22)));
	return (free(info->file), ft_doublefree(file_content), 0);
}

int	ft_input_errors(int argc, char *file)
{
	if (argc == 1)
		return (printf("Error : %s\n", strerror(22)));
	if (argc > 2)
		return (printf("Error : %s\n", strerror(7)));
	if (ft_checkext(file, ".cub"))
		return (printf("Error : %s\n", strerror(22)));
	if (ft_checkfile(file))
		return (perror("Error "), 1);
	return (0);
}
