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

static int	ft_isvalid_line(char *line)
{
	printf("line: %s", line);
	return (1);
}

int	ft_file_errors(t_info *info)
{
	char	**file_content;
	int		i;

	i = -1;
	file_content = (char **)ft_calloc(info->file_size + 1, sizeof(char *));
	if (!file_content)
		return (1);
	while (++i < info->file_size)
	{
		file_content[i] = ft_get_next_line(info->file_fd);
		if (ft_isvalid_line(file_content[i]))
		{
			file_content[i] = 0;
			ft_doublefree(file_content);
			return (printf("Error : %s\n", strerror(22)));
		}
	}
	file_content[i] = 0;
	return (ft_doublefree(file_content), 0);
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
