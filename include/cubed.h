/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cubed.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalvarez <aalvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 16:59:47 by aalvarez          #+#    #+#             */
/*   Updated: 2022/09/20 18:09:37 by adel-cor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBED_H
# define CUBED_H

# include "Libft_extended/libft.h"
# include "minilib/mlx.h"
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <math.h>

# define ROTATE_LEFT        123
# define ROTATE_RIGHT       124
# define FORWARD_W_Z        13
# define BACK_S_S           1
# define RIGHT_D_D          2
# define LEFT_A_Q           0

# define ENOTXPM "File has not an xpm extension"

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

typedef struct  s_texture
{
    int         texdir;
    double      wallX;
    int         texX;
    int         texY;
    double      step;
    double      texPos;
}                   t_texture;

typedef struct  s_ray
{
    double      posX;
    double      posY;
    double      dirX;
    double      dirY;
    double      planX;
    double      planY;
    double      rayDirX;
	double		oldDirX;
	double		oldPlaneX;
    double      rayDirY;
    double      cameraX;
    int         mapX;
    int         mapY;
    double      sideDistX;
    double      sideDistY;
    double      deltaDistX;
    double      deltaDistY;
    int         stepX;
    int         stepY;
    int         hit;
    int         side;
    double      perpWallDist;
    int         lineHeight;
    int         drawStart;
    int         drawEnd;
    double      movespeed;
    double      rotspeed;
    int         x;
    int         texture;
}                   t_ray;

typedef struct      s_data
{

    void        *mlx_ptr;
    void        *mlx_win;
    void        *img;
    int         *addr;
    int         bits_per_pixel;
    int         line_length;
    int         endian;
    int         forward;
    int         back;
    int         left;
    int         right;
    int         rotate_left;
    int         rotate_right;
    int         width;
    int         height;
    void        *img2;
    int         *addr2;
}                   t_data;


typedef struct s_vault
{
	char	*north_texture;
	char	*south_texture;
	char	*east_texture;
	char	*west_texture;
	int		floor;
	int		ceiling;
	int         Rx;
    int         Ry;
    char        **map;
    char        compass;
    int         init_x;
    int         init_y; 
    t_data      texture[4];
    t_data      data;
    t_ray       ray;
    t_texture   t;

}	t_vault;

/* User input errors */
int		ft_input_errors(int argc, char *file);
int		ft_file_errors(t_file *file, t_vault *vault, t_color *color);
int		ft_fill_data(t_vault *vault, char *line);
int		ft_invalidmap_line(char **file_content);
int		ft_create_map(t_vault *vault, char **file_content);
int		ft_invalidcolor_line(t_vault *vault, t_color *color, char **content);


char	*ft_get_next_line(int fd);

/* Different general utilities functions */
void	ft_freedata(t_vault *vault);
void	ft_init_structs(t_vault *vault, t_color *color);
void	ft_trim_data(t_vault *vault);
int         ft_start(t_vault *vault);
void        ft_color_res(t_vault *vault);
void        ft_init(t_vault *vault);

int         ft_raycast(t_vault *vault);
int         ft_draw(t_vault *vault);
int        ft_texture(t_vault *vault);
void        ft_texture_adress(t_vault *vault);
int         ft_key_press(int keycode, t_vault *vault);
int         ft_key_release(int keycode, t_vault *vault);
int         ft_brush(t_vault *vault);
void        ft_draw_text(t_vault *vault, int x, int y);
void        ft_init_2(t_vault *vault);
void        ft_init_3(t_vault *vault);
void        ft_init_texture(t_vault *vault);
void        ft_sidedist(t_vault *vault);
void        ft_ray_inc(t_vault *vault);
void        ft_drawstarte(t_vault *vault);
void        ft_magic(t_vault *vault);
void        ft_forward_back(t_vault *vault);
void        ft_left_right(t_vault *vault);
void        ft_rotate_right_left(t_vault *vault);
void		ft_r_right(t_vault *vault);
void		ft_r_left(t_vault *vault);
void        ft_error(t_vault *vault, char *str);
int         ft_exit(t_vault *vault);


#endif
