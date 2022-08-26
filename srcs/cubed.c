/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cubed.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalvarez <aalvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 13:38:28 by aalvarez          #+#    #+#             */
/*   Updated: 2022/08/22 14:27:41 by aalvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubed.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

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

int	main(int argc, char **argv)
{
	if (ft_input_errors(argc, argv[1]))
		return (1);
	return (0);
}
