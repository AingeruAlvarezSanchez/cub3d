/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thundercaster.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adel-cor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 14:43:31 by adel-cor          #+#    #+#             */
/*   Updated: 2022/09/20 16:21:30 by adel-cor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubed.h"

void    ft_texture_adress(t_vault *vault)
{
	vault->texture[0].addr = (int *)mlx_get_data_addr(vault->texture[0].img,
			&vault->texture[0].bits_per_pixel,
			&vault->texture[0].line_length, &vault->texture[0].endian);
	vault->texture[1].addr = (int *)mlx_get_data_addr(vault->texture[1].img,
			&vault->texture[1].bits_per_pixel,
			&vault->texture[1].line_length, &vault->texture[1].endian);
	vault->texture[2].addr = (int *)mlx_get_data_addr(vault->texture[2].img,
			&vault->texture[2].bits_per_pixel,
			&vault->texture[2].line_length, &vault->texture[2].endian);
	vault->texture[3].addr = (int *)mlx_get_data_addr(vault->texture[3].img,
			&vault->texture[3].bits_per_pixel,
			&vault->texture[3].line_length, &vault->texture[3].endian);
}

void    ft_texture(t_vault *vault)
{
    if (!(vault->texture[0].img = mlx_xpm_file_to_image(vault->data.mlx_ptr,
                    vault->north_texture, &(vault->texture[0].width),
                    &(vault->texture[0].height))))
        ft_error(vault, "Texture NO\n");
    if (!(vault->texture[1].img = mlx_xpm_file_to_image(vault->data.mlx_ptr,
                    vault->south_texture, &(vault->texture[1].width),
                    &(vault->texture[1].height))))
        ft_error(vault, "Texture SO\n");
    if (!(vault->texture[2].img = mlx_xpm_file_to_image(vault->data.mlx_ptr,
                    vault->west_texture, &(vault->texture[2].width),
                    &(vault->texture[2].height))))
        ft_error(vault, "Texture WE\n");
    if (!(vault->texture[3].img = mlx_xpm_file_to_image(vault->data.mlx_ptr,
                    vault->east_texture, &(vault->texture[3].width),
                    &(vault->texture[3].height))))
        ft_error(vault, "Texture EA\n");
    ft_texture_adress(vault);
}

int     ft_raycast(t_vault *vault)
{
    vault->ray.x = 0;
    while (vault->ray.x < vault->Rx)
    {
        ft_init_3(vault);
        ft_sideDist(vault);
        ft_brush(vault);
        vault->ray.x++;
    }
    mlx_put_image_to_window(vault->data.mlx_ptr, vault->data.mlx_win,
            vault->data.img, 0, 0);
    ft_forward_back(vault);
    ft_left_right(vault);
    ft_rotate_right_left(vault);
    ft_magic(vault);
    return (0);
}

int 	ft_exit_game(void)
{
	exit(0);
	//TODO
}
int     ft_draw(t_vault *vault)
{
    ft_init_2(vault);
    vault->data.mlx_ptr = mlx_init();
    ft_texture(vault);
    vault->data.img = mlx_new_image(vault->data.mlx_ptr, vault->Rx, vault->Ry);
    vault->data.addr = (int *)mlx_get_data_addr(vault->data.img, &vault->data.
            bits_per_pixel, &vault->data.line_length, &vault->data.endian);
    vault->data.mlx_win = mlx_new_window(vault->data.mlx_ptr, vault->Rx,
            vault->Ry, "Cub3d");
    vault->data.img2 = mlx_new_image(vault->data.mlx_ptr, vault->Rx, vault->Ry);
    vault->data.addr2 = (int *)mlx_get_data_addr(vault->data.img2, &vault->
            data.bits_per_pixel, &vault->data.line_length, &vault->data.endian);
    mlx_hook(vault->data.mlx_win, 17, 1L<<17, ft_exit_game, vault);
    mlx_hook(vault->data.mlx_win, 2, 1L << 0, ft_key_press, vault);
    mlx_loop_hook(vault->data.mlx_ptr, ft_raycast, vault);
    mlx_hook(vault->data.mlx_win, 3, 1L << 1, ft_key_release, vault);
    mlx_loop(vault->data.mlx_ptr);
    return (0);
}