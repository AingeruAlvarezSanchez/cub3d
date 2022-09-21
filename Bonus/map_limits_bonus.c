/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_limits.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalvarez <aalvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 00:46:04 by aalvarez          #+#    #+#             */
/*   Updated: 2022/09/21 14:06:48 by adel-cor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubed.h"

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
				[ft_doublestrlen((const char **)vault->map) - 1][i], " 1\n"))
			return (1);
	i = -1;
	while (vault->map[++i])
		if (!ft_chr_in_set(vault->map[i][ft_strlen(vault->map[i]) - 2], " 1\n"))
			if (ft_strlen(vault->map[i]) > 1)
				return (1);
	return (0);
}

static int	ft_limits_0(t_vault *vault, int i, int j)
{
	if (vault->map[i][j] == '0')
		if (!ft_chr_in_set(vault->map[i][j + 1], "01NSWE")
			|| !ft_chr_in_set(vault->map[i][j - 1], "01NSWE")
			|| !ft_chr_in_set(vault->map[i + 1][j], "01NSWE")
			|| !ft_chr_in_set(vault->map[i - 1][j], "01NSWE"))
			return (1);
	return (0);
}

static int	ft_limits_init_pos(t_vault *vault, int i, int j)
{
	if (ft_chr_in_set(vault->map[i][j], "NSWE"))
		if (!ft_chr_in_set(vault->map[i][j + 1], "01")
			|| !ft_chr_in_set(vault->map[i][j - 1], "01")
			|| !ft_chr_in_set(vault->map[i + 1][j], "01")
			|| !ft_chr_in_set(vault->map[i - 1][j], "01"))
			return (1);
	return (0);
}

int	ft_checklimits(t_vault *vault, int i, int j)
{
	if (ft_limits_0(vault, i, j))
		return (1);
	if (ft_limits_init_pos(vault, i, j))
		return (1);
	if (ft_map_limits(vault) && ((vault->map[i][j] == ' '
			&& (ft_strlen(vault->map[i])
				< ft_strlen(vault->map[i + 1])))
		&& (!ft_chr_in_set(vault->map[i][j + 1], " 1\n")
		|| !ft_chr_in_set(vault->map[i][j - 1], " 1\n")
		|| !ft_chr_in_set(vault->map[i + 1][j], " 1\n")
		|| !ft_chr_in_set(vault->map[i - 1][j], " 1\n"))))
		return (1);
	return (0);
}
