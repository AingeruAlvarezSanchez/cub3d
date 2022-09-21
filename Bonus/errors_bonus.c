/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalvarez <aalvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 17:45:21 by aalvarez          #+#    #+#             */
/*   Updated: 2022/09/21 13:34:26 by adel-cor         ###   ########.fr       */
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
		if (*line != '\n' && *line != ' ')
			return (1);
		line++;
	}
	return (0);
}

static int	ft_isvalid_file(t_vault *vault, t_color *color, char **file_content)
{
	int	i;

	i = -1;
	ft_init_structs(vault, color);
	while (file_content[++i])
		if (ft_fill_data(vault, ft_strtrim(file_content[i], " \n")))
			return (1);
	if (!vault->north_texture || !vault->south_texture
		|| !vault->west_texture || !vault->east_texture)
		return (1);
	if (ft_invalidmap_line(file_content))
		return (1);
	if (ft_invalidcolor_line(vault, color, file_content))
		return (1);
	ft_trim_data(vault);
	if (open(vault->north_texture, O_RDONLY) < 0
		|| open(vault->south_texture, O_RDONLY) < 0
		|| open(vault->west_texture, O_RDONLY) < 0
		|| open(vault->east_texture, O_RDONLY) < 0)
		return (perror("Error "), 1);
	if (ft_create_map(vault, file_content))
		return (1);
	vault->compass = vault->map[vault->init_y][vault->init_x];
	return (0);
}

int	ft_file_errors(t_file *file, t_vault *vault, t_color *color)
{
	char	**file_content;
	int		i;

	i = -1;
	file_content = (char **)ft_calloc(file->file_size + 2, sizeof(char *));
	if (!file_content)
		return (1);
	while (++i < (file->file_size + 1))
	{
		file_content[i] = ft_get_next_line(file->file_fd);
		if (ft_isvalid_line(file_content[i]))
		{
			file_content[i + 1] = 0;
			ft_doublefree(file_content);
			return (printf("Error : %s\n", strerror(22)));
		}
	}
	file_content[i] = 0;
	if (ft_isvalid_file(vault, color, file_content))
		return (ft_freedata(vault), ft_doublefree(file_content),
			printf("Error : %s\n", strerror(22)));
	return (free(file->file), ft_doublefree(file_content), 0);
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
