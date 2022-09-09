/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cubed.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalvarez <aalvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 16:59:47 by aalvarez          #+#    #+#             */
/*   Updated: 2022/09/06 01:12:48 by aalvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBED_H
# define CUBED_H

# include "Libft_extended/libft.h"
# include "minilib/mlx.h"

typedef struct s_file
{
	int		file_fd;
	int		file_size;
	char	*file;
}	t_file;

typedef struct s_color
{
	int		ceiling_integer;
	int		floor_integer;
	int		color_r;
	int		color_g;
	int		color_b;
}	t_color;

typedef struct s_vault
{
	char	*north_texture;
	char	*south_texture;
	char	*east_texture;
	char	*west_texture;
	char	**map;
	int		floor;
	int		ceiling;
	int		init_x;
	int		init_y;
	char	compass;
}	t_vault;

/* User input errors */
int		ft_input_errors(int argc, char *file);
int		ft_file_errors(t_file *file, t_vault *vault, t_color *color);
int		ft_fill_data(t_vault *vault, char *line);
int		ft_invalidmap_line(char **file_content);
int		ft_create_map(t_vault *vault, char **file_content);
int		ft_invalidcolor_line(t_vault *vault, t_color *color, char **content);

//TODO change get_next_line place in the program
char	*ft_get_next_line(int fd);

/* Different general utilities functions */
void	ft_freedata(t_vault *vault);
void	ft_init_structs(t_vault *vault, t_color *color);
void	ft_trim_data(t_vault *vault);

#endif
