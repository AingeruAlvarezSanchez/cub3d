/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalvarez <aalvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 17:19:02 by aalvarez          #+#    #+#             */
/*   Updated: 2022/08/26 17:19:02 by aalvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

char	*ft_aux(char *line, char c)
{
	char	*str;
	int		i;

	i = 0;
	while (line[i])
		i++;
	str = (char *)malloc(2 + i);
	if (!str)
		return (NULL);
	i = -1;
	while (line[++i])
		str[i] = line[i];
	str[i] = c;
	str[i + 1] = 0;
	return (free(line), str);
}

int	ft_check_ch(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] == '\n' || str[i] == '\0')
			return (1);
		i++;
	}
	return (0);
}

char	*ft_get_next_line(int fd)
{
	char	*line;
	char	buff;
	int		filled;

	if (fd < 0)
		return (NULL);
	line = malloc(1);
	if (!line)
		return (NULL);
	line[0] = 0;
	filled = 1;
	while (!(ft_check_ch(line)) && filled != 0)
	{
		filled = read(fd, &buff, 1);
		if (filled == 0)
		{
			if (line[0] == '\0')
				return (free(line), NULL);
			return (line);
		}
		if (filled < 0)
			return (free(line), NULL);
		line = ft_aux(line, buff);
	}
	return (line);
}
