/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drow_map_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelbouab <aelbouab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 17:32:32 by aelbouab          #+#    #+#             */
/*   Updated: 2024/03/02 11:17:17 by aelbouab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	wall_drowing_bonus(char **lines, t_data *img)
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
				mlx_put_image_to_window(img->mlx_ptr,
					img->win, img->img_wall, j * 60, i * 60);
			j++;
		}
		i++;
	}
}

static void	keys_drow_bonus(char **lines, t_data *img)
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
				mlx_put_image_to_window(img->mlx_ptr,
					img->win, img->img_key, j * 60, i * 60);
			j++;
		}
		i++;
	}
}

static void	monster_drow_bonus(char **lines, t_data *img)
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
			if (lines[i][j] == 'M')
				mlx_put_image_to_window(img->mlx_ptr,
					img->win, img->monster, j * 60, i * 60);
			j++;
		}
		i++;
	}
}

static void	door_drow_bonus(char **lines, t_data *img)
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
				mlx_put_image_to_window(img->mlx_ptr,
					img->win, img->img_door, j * 60, i * 60);
				break ;
			}
			j++;
		}
		i++;
	}
}

void	drowing_bonus(char *maps)
{
	t_data	img;
	void	*mlx_ptr;

	mlx_ptr = mlx_init();
	img.lines = ft_split(maps, '\n');
	img.cp = 1;
	img = ft_imgnew_bonus(&img, mlx_ptr);
	floor_drowing_bonus(img.lines, &img);
	wall_drowing_bonus(img.lines, &img);
	door_drow_bonus(img.lines, &img);
	player_drow_bonus(img.lines, &img);
	keys_drow_bonus(img.lines, &img);
	monster_drow_bonus(img.lines, &img);
	mlx_hook(img.win, 2, 0, move_player_bonus, &img);
	mlx_loop_hook(img.mlx_ptr, monster_move, &img);
	mlx_loop(img.mlx_ptr);
}
