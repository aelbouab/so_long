/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exitdoor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelbouab <aelbouab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 14:18:10 by aelbouab          #+#    #+#             */
/*   Updated: 2024/03/02 16:56:50 by aelbouab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	fined_exit(char **lines)
{
	int	i;
	int	j;
	int	cp;

	i = 0;
	j = 0;
	cp = 0;
	while (lines[i])
	{
		j = 0;
		while (lines[i][j])
		{
			if (lines[i][j] == 'E' || lines[i][j] == 'X')
			{
				cp = 1;
				break ;
			}
			j++;
		}
		i++;
	}
	return (cp);
}

int	keychecker(char **lines)
{
	int	i;
	int	j;
	int	cp;

	i = 0;
	j = 0;
	cp = 0;
	while (lines[i])
	{
		j = 0;
		while (lines[i][j])
		{
			if (lines[i][j] == 'C')
				cp++;
			j++;
		}
		i++;
	}
	return (cp);
}

void	door_open(char **lines, t_data *map)
{
	int	i;
	int	j;

	i = 0;
	while (lines[i])
	{
		j = 0;
		while (lines[i][j])
		{
			if (lines[i][j] == 'E')
			{
				lines[i][j] = 'X';
				mlx_put_image_to_window(map->mlx_ptr,
					map->win, map->img_floor, j * 60, i * 60);
				if (lines[i][j + 1] == '0')
					mlx_put_image_to_window(map->mlx_ptr,
						map->win, map->img_floor, (j + 1) * 60, i * 60);
				mlx_put_image_to_window(map->mlx_ptr,
					map->win, map->img_opendoor, j * 60, i * 60);
				break ;
			}
			j++;
		}
		i++;
	}
}
