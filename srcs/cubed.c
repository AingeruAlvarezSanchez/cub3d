/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cubed.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalvarez <aalvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 13:38:28 by aalvarez          #+#    #+#             */
/*   Updated: 2022/09/06 01:20:29 by aalvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubed.h"
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

int	main(int argc, char **argv)
{
	t_file	file;
	t_vault	vault;
	t_color	color;

	if (ft_input_errors(argc, argv[1]))
		return (1);
	file.file_fd = open(argv[1], O_RDONLY);
	file.file_size = ft_getfile_size(file.file_fd);
	close(file.file_fd);
	if (!file.file_size)
		return (1);
	file.file = ft_strdup(argv[1]);
	file.file_fd = open(file.file, O_RDONLY);
	if (ft_file_errors(&file, &vault, &color))
		return (close(file.file_fd), free(file.file), 1);
	//testing purposes
	int check = -1;
	while (vault.map[++check])
		printf("map: %s", vault.map[check]);
	printf("\ntextures:\nNO: %s\nSO: %s\nWE: %s\nEA: %s\n", vault.north_texture, vault.south_texture, vault.west_texture, vault.east_texture);
	printf("\ncolor integer representation for mlx:\nfloor: %d\nceiling: %d\n", vault.floor, vault.ceiling);
	//testing purposes
	close(file.file_fd);
	ft_freedata(&vault);
	return (0);
}
