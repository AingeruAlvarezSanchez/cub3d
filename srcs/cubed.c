/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cubed.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalvarez <aalvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 13:38:28 by aalvarez          #+#    #+#             */
/*   Updated: 2022/09/01 20:26:48 by aalvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubed.h"
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

int	main(int argc, char **argv)
{
	t_info	info;
	t_data	data;

	if (ft_input_errors(argc, argv[1]))
		return (1);
	info.file_fd = open(argv[1], O_RDONLY);
	info.file_size = ft_getfile_size(info.file_fd);
	close(info.file_fd);
	if (!info.file_size)
		return (1);
	info.file = ft_strdup(argv[1]);
	info.file_fd = open(info.file, O_RDONLY);
	if (ft_file_errors(&info, &data))
		return (close(info.file_fd), free(info.file), 1);
	printf("\n%s\n%s\n%s\n%s\n", data.north_texture, data.south_texture, data.west_texture, data.east_texture);
	close(info.file_fd);
	ft_freedata(&data);
	return (0);
}
