/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_p.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelbouab <aelbouab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 10:46:07 by aelbouab          #+#    #+#             */
/*   Updated: 2024/03/04 11:19:37 by aelbouab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	move_up(t_data *img)
{
	char	**lines;
	t_pos	pp;

	lines = img->lines;
	pp = player_pous(lines, 0);
	if (lines[(pp.x) - 1][pp.y] != '1')
	{
		ft_putnbr (img->cp++);
		write (1, "\n", 1);
		if (lines[(pp.x) - 1][pp.y] == 'X')
			return (write(1, "you win", 7), exit (0));
		if (!fined_exit(lines))
			lines[pp.x][pp.y] = 'E';
		else
			lines[pp.x][pp.y] = '0';
		lines[(pp.x) - 1][pp.y] = 'P';
		mlx_put_image_to_window(img->mlx_ptr,
			img->win, img->img_floor, pp.y * 60, pp.x * 60);
		if (lines[(pp.x)][pp.y] == 'E')
			mlx_put_image_to_window(img->mlx_ptr,
				img->win, img->img_door, pp.y * 60, pp.x * 60);
		mlx_put_image_to_window(img->mlx_ptr,
			img->win, img->img_pback, pp.y * 60, (pp.x - 1) * 60);
	}
}

static void	move_down(t_data *img)
{
	char	**lines;
	t_pos	pp;

	lines = img->lines;
	pp = player_pous(lines, 0);
	if (lines[(pp.x) + 1][pp.y] != '1')
	{
		ft_putnbr (img->cp++);
		write (1, "\n", 1);
		if (lines[(pp.x) + 1][pp.y] == 'X')
			return (write(1, "you win", 7), exit (0));
		if (!fined_exit(lines))
			lines[pp.x][pp.y] = 'E';
		else
			lines[pp.x][pp.y] = '0';
		lines[(pp.x) + 1][pp.y] = 'P';
		mlx_put_image_to_window(img->mlx_ptr,
			img->win, img->img_floor, pp.y * 60, pp.x * 60);
		if (lines[(pp.x)][pp.y] == 'E')
			mlx_put_image_to_window(img->mlx_ptr,
				img->win, img->img_door, pp.y * 60, pp.x * 60);
		mlx_put_image_to_window(img->mlx_ptr,
			img->win, img->img_pface, pp.y * 60, (pp.x + 1) * 60);
	}
}

static void	move_right(t_data *img)
{
	char	**lines;
	t_pos	pp;

	lines = img->lines;
	pp = player_pous(lines, 0);
	if (lines[pp.x][pp.y + 1] != '1')
	{
		ft_putnbr (img->cp++);
		write (1, "\n", 1);
		if (lines[pp.x][pp.y + 1] == 'X')
			return (write(1, "you win", 7), exit (0));
		if (!fined_exit(lines))
			lines[pp.x][pp.y] = 'E';
		else
			lines[pp.x][pp.y] = '0';
		lines[pp.x][(pp.y) + 1] = 'P';
		mlx_put_image_to_window(img->mlx_ptr,
			img->win, img->img_floor, pp.y * 60, pp.x * 60);
		if (lines[pp.x][pp.y] == 'E')
			mlx_put_image_to_window(img->mlx_ptr,
				img->win, img->img_door, pp.y * 60, pp.x * 60);
		mlx_put_image_to_window(img->mlx_ptr,
			img->win, img->img_pright, (pp.y + 1) * 60, pp.x * 60);
	}
}

static void	move_left(t_data *img)
{
	char	**lines;
	t_pos	pp;

	lines = img->lines;
	pp = player_pous(lines, 0);
	if (lines[pp.x][pp.y - 1] != '1')
	{
		ft_putnbr (img->cp++);
		write (1, "\n", 1);
		if (lines[pp.x][pp.y - 1] == 'X')
			return (write(1, "you win", 7), exit (0));
		if (!fined_exit(lines))
			lines[pp.x][pp.y] = 'E';
		else
			lines[pp.x][pp.y] = '0';
		mlx_put_image_to_window(img->mlx_ptr,
			img->win, img->img_floor, pp.y * 60, pp.x * 60);
		if (lines[pp.x][pp.y] == 'E')
			mlx_put_image_to_window(img->mlx_ptr,
				img->win, img->img_door, pp.y * 60, pp.x * 60);
		mlx_put_image_to_window(img->mlx_ptr,
			img->win, img->img_pleft, (pp.y - 1) * 60, pp.x * 60);
		lines[pp.x][(pp.y) - 1] = 'P';
	}
}

int	move_player(int key, void *p)
{
	t_data	*map;
	char	**lines;
	int		i;

	map = p;
	lines = map->lines;
	if (key == 126)
		move_up(p);
	else if (key == 125)
		move_down(p);
	else if (key == 124)
		move_right(p);
	else if (key == 123)
		move_left(p);
	else if (key == 53)
		exit (1);
	i = keychecker(lines);
	if (i == 0)
		door_open(lines, map);
	return (0);
}
