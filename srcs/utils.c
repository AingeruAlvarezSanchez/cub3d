#include "cubed.h"
#include <stdlib.h>

void	ft_freedata(t_data *data)
{
	free(data->north_texture);
	free(data->south_texture);
	free(data->west_texture);
	free(data->east_texture);
}

void	ft_init_data(t_data *data)
{
	data->north_texture = NULL;
	data->south_texture = NULL;
	data->west_texture = NULL;
	data->east_texture = NULL;
}
void 	ft_trim_data(t_data *data)
{
	char *tmp;

	tmp = ft_strdup(data->north_texture);
	free(data->north_texture);
	data->north_texture = ft_strtrim(tmp, " \n");
	free(tmp);
	tmp = ft_strdup(data->south_texture);
	free(data->south_texture);
	data->south_texture = ft_strtrim(tmp, " \n");
	free(tmp);
	tmp = ft_strdup(data->west_texture);
	free(data->west_texture);
	data->west_texture = ft_strtrim(tmp, " \n");
	free(tmp);
	tmp = ft_strdup(data->east_texture);
	free(data->east_texture);
	data->east_texture = ft_strtrim(tmp, " \n");
	free(tmp);
}
