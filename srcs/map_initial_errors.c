/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_initial_errors.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalvarez <aalvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 20:18:45 by aalvarez          #+#    #+#             */
/*   Updated: 2022/09/01 20:21:06 by aalvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubed.h"
#include <stdlib.h>

static int	ft_syntax_errors(char **file)
{
	int	i;
	int	j;
	int	init_pos;

	i = -1;
	init_pos = 0;
	while (file[++i])
	{
		if (*file[i] == '1')
		{
			j = -1;
			while (file[i][++j])
			{
				if (!ft_chr_in_set(file[i][j], "10NSWE "))
					return (1);
				else if (ft_chr_in_set(file[i][j], "NSWE"))
					init_pos++;
			}
		}
	}
	if (init_pos != 1)
		return (1);
	return (0);
}

static int	ft_blankline_in_map(char **file)
{
	int	i;

	i = -1;
	while (file[++i])
	{
		if (*file[i] == '1')
		{
			while (file[i])
			{
				if (!ft_isempty(file[i]))
				{
					while (file[i])
					{
						if (*file[i] == '1')
							return (1);
						i++;
					}
					break ;
				}
				i++;
			}
			break ;
		}
	}
	return (0);
}

int	ft_invalidmap_line(char **file_content)
{
	char	**tmp;
	int		i;

	tmp = (char **)malloc(sizeof(char *)
			* (ft_doublestrlen((const char **)file_content) + 1));
	if (!tmp)
		return (1);
	i = -1;
	while (file_content[++i])
	{
		tmp[i] = ft_strtrim(file_content[i], " \n");
		if (*tmp[i] == 'F' || *tmp[i] == 'C')
			if (tmp[i][1] != ' ')
				return (ft_doublefree(tmp), 1);
	}
	tmp[i] = 0;
	if (ft_syntax_errors(tmp) || ft_blankline_in_map(tmp))
		return (ft_doublefree(tmp), 1);
	return (ft_doublefree(tmp), 0);
}
