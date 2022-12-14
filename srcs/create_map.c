/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalvarez <aalvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 01:12:06 by aalvarez          #+#    #+#             */
/*   Updated: 2022/09/07 00:53:39 by aalvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubed.h"
#include <stdlib.h>

static int	ft_map_limits(t_vault *vault)
{
	int	i;

	i = -1;
	while (vault->map[0][++i])
		if (!ft_chr_in_set(vault->map[0][i], " 1\n"))
			return (1);
	i = -1;
	while (vault->map[ft_doublestrlen((const char **)vault->map) - 1][++i])
		if (!ft_chr_in_set(vault->map
				[ft_doublestrlen((const char **)vault->map) - 1][++i], " 1\n"))
			return (1);
	i = -1;
	while (vault->map[++i])
		if (!ft_chr_in_set(vault->map[i][ft_strlen(vault->map[i]) - 2], " 1\n"))
			return (1);
	return (0);
}

static int	ft_parse_map(t_vault *vault)
{
	int	i;
	int	j;

	if (ft_map_limits(vault))
		return (1);
	i = 0;
	while (++i < ft_doublestrlen((const char **)vault->map) - 1)
	{
		j = 0;
		while (vault->map[i][++j])
		{
			if (vault->map[i][j] == ' '
				&& (!ft_chr_in_set(vault->map[i][j + 1], " 1\n")
					|| !ft_chr_in_set(vault->map[i][j - 1], " 1\n")
					|| !ft_chr_in_set(vault->map[i + 1][j], " 1\n")
					|| !ft_chr_in_set(vault->map[i - 1][j], " 1\n")))
				return (1);
			else if (ft_chr_in_set(vault->map[i][j], "NSWE"))
			{
				vault->init_x = j;
				vault->init_y = i;
			}
		}
	}
	return (0);
}

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

int	ft_create_map(t_vault *vault, char **file_content)
{
	int		i;
	int		j;
	char	*tmp;

	if (ft_map_size(file_content) == -1)
		return (1);
	vault->map = (char **)ft_calloc((ft_map_size(file_content) + 1),
			sizeof(char *));
	i = -1;
	while (file_content[++i])
	{
		tmp = ft_strtrim(file_content[i], " \n");
		if (*tmp == '1')
		{
			j = -1;
			while (++j < ft_map_size(file_content))
				vault->map[j] = ft_strdup(file_content[i++]);
			vault->map[j] = 0;
			break ;
		}
		free(tmp);
	}
	if (ft_parse_map(vault))
		return (1);
	return (0);
}
