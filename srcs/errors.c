/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalvarez <aalvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 17:45:21 by aalvarez          #+#    #+#             */
/*   Updated: 2022/08/26 17:45:25 by aalvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubed.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

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

int	ft_isvalid_route(char *line)
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
		}
	}
	return (free(tmp), 0);
}

int	ft_fill_data(t_data *data, char *line)
{
	if (!ft_strncmp(line, "NO", 2))
	{
		if (data->north_texture || ft_isvalid_route(line))
			return (1);
		data->north_texture = ft_substr(line, 2, (ft_strlen(line) - 2));
	}
	if (!ft_strncmp(line, "SO", 2))
	{
		if (data->south_texture || ft_isvalid_route(line))
			return (1);
		data->south_texture = ft_substr(line, 2, (ft_strlen(line) - 2));
	}
	if (!ft_strncmp(line, "WE", 2))
	{
		if (data->west_texture || ft_isvalid_route(line))
			return (1);
		data->west_texture = ft_substr(line, 2, (ft_strlen(line) - 2));
	}
	if (!ft_strncmp(line, "EA", 2))
	{
		if (data->east_texture || ft_isvalid_route(line))
			return (1);
		data->east_texture = ft_substr(line, 2, (ft_strlen(line) - 2));
	}
	return (0);
}

int ft_invalidmap_line(char **file_content)
{
	char	**tmp;
	int 	i;

	tmp = (char **)malloc(sizeof(char *) * (ft_doublestrlen(tmp) + 1));
	if (!tmp)
		return (1);
	i = -1;
	while (file[++i])
		tmp[i] = ft_strtrim(file[i], " \n");
	tmp[i] = 0;
	i = -1;
	while (tmp[++i])
	{
		if (**tmp == 1)
	}
	return (0);
}

static int	ft_isvalid_file(t_data *data, char **file_content)
{
	int	i;

	i = -1;
	ft_init_data(data);
	while (file_content[++i])
	{
		printf("line: %s", file_content[i]);
		if (ft_fill_data(data, file_content[i]))
			return (1);
	}
	if (!data->north_texture || !data->south_texture
		|| !data->west_texture || !data->east_texture)
		return (1);
	if (ft_invalidmap_line(file_content))
		return (1);
	ft_trim_data(data);
	printf("\n%s\n%s\n%s\n%s\n", data->north_texture, data->south_texture, data->west_texture, data->east_texture); //TODO trim the paths with space and newline
	return (0);
}

int	ft_file_errors(t_info *info, t_data *data)
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
	if (ft_isvalid_file(data, file_content))
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
