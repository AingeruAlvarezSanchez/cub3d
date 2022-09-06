/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalvarez <aalvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 01:12:06 by aalvarez          #+#    #+#             */
/*   Updated: 2022/09/06 01:15:57 by aalvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubed.h"
#include <stdlib.h>

static int	ft_actual_size(char **file)
{
	int	i;
	int	result;

	i = -1;
	result = 0;
	while (file[++i])
	{
		if (*file[i] == '1')
		{
			while (file[i] && *file[i] == '1')
			{
				result++;
				i++;
			}
			break ;
		}
	}
	if (result < 3)
		return (ft_doublefree(file), -1);
	return (ft_doublefree(file), result);
}

static int	ft_map_size(char **file_content)
{
	int		i;
	char	**tmp;

	tmp = (char **)ft_calloc(
			(ft_doublestrlen((const char **)file_content) + 1), sizeof(char *));
	if (!tmp)
		return (1);
	i = -1;
	while (file_content[++i])
		tmp[i] = ft_strtrim(file_content[i], " \n");
	tmp[i] = 0;
	i = -1;
	return (ft_actual_size(tmp));
}

int	ft_create_map(t_data *data, char **file_content)
{
	int		i;
	int		j;
	char	*tmp;

	if (ft_map_size(file_content) == -1)
		return (1);
	data->map = (char **)ft_calloc((ft_map_size(file_content) + 1),
			sizeof(char *));
	if (!data->map)
		return (1);
	i = -1;
	while (file_content[++i])
	{
		tmp = ft_strtrim(file_content[i], " \n");
		if (*tmp == '1')
		{
			j = -1;
			while (++j < ft_map_size(file_content))
				data->map[j] = ft_strdup(file_content[i++]);
			data->map[j] = 0;
		}
		free(tmp);
	}
	return (0);
}
