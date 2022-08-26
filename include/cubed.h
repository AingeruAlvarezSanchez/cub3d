/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cubed.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalvarez <aalvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 16:59:47 by aalvarez          #+#    #+#             */
/*   Updated: 2022/08/26 16:59:52 by aalvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBED_H
# define CUBED_H

# include "Libft_extended/libft.h"

typedef struct s_info
{
	int		file_fd;
	int		file_size;
	char	*file;
}	t_info;

/* User input errors */
int		ft_input_errors(int argc, char *file);
int		ft_file_errors(t_info *info);

//TODO change get_next_line place in the program
char	*ft_get_next_line(int fd);

#endif
