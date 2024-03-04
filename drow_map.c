/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drow_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelbouab <aelbouab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 17:32:32 by aelbouab          #+#    #+#             */
/*   Updated: 2024/02/24 11:30:24 by aelbouab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	wall_drowing(char **lines, t_data *img)
{
	int	j;
	int	i;

	j = 0;
	i = 0;
	while (lines[i])
	{
		j = 0;
		while (lines[i][j])
		{
			if (lines[i][j] == '1')
				mlx_put_image_to_window((img)->mlx_ptr,
					(img)->win, (img)->img_wall, j * 60, i * 60);
			j++;
		}
		i++;
	}
}

void	keys_drow(char **lines, t_data *img)
{
	int	j;
	int	i;

	j = 0;
	i = 0;
	while (lines[i])
	{
		j = 0;
		while (lines[i][j])
		{
			if (lines[i][j] == 'C')
				mlx_put_image_to_window((img)->mlx_ptr,
					(img)->win, (img)->img_key, j * 60, i * 60);
			j++;
		}
		i++;
	}
}

void	door_drow(char **lines, t_data *img)
{
	int	j;
	int	i;

	j = 0;
	i = 0;
	while (lines[i])
	{
		j = 0;
		while (lines[i][j])
		{
			if (lines[i][j] == 'E')
			{
				mlx_put_image_to_window((img)->mlx_ptr,
					(img)->win, img->img_door, j * 60, i * 60);
				break ;
			}
			j++;
		}
		i++;
	}
}

void	player_drow(char **lines, t_data *img)
{
	int	j;
	int	i;

	j = 0;
	i = 0;
	while (lines[i])
	{
		j = 0;
		while (lines[i][j])
		{
			if (lines[i][j] == 'P')
			{
				mlx_put_image_to_window((img)->mlx_ptr,
					(img)->win, (img)->img_pface, j * 60, i * 60);
				break ;
			}
			j++;
		}
		i++;
	}
}

void	drowing(char *maps)
{
	t_data	img;
	void	*mlx_ptr;

	mlx_ptr = mlx_init();
	img.lines = ft_split(maps, '\n');
	img.cp = 1;
	img = ft_imgnew(&img, mlx_ptr);
	floor_drowing(img.lines, &img);
	wall_drowing(img.lines, &img);
	door_drow(img.lines, &img);
	player_drow(img.lines, &img);
	keys_drow(img.lines, &img);
	mlx_hook(img.win, 2, 0, move_player, &img);
	mlx_loop(img.mlx_ptr);
}
